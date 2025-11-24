#!/bin/bash

cd /var/www/html

# scarica lo strumento a riga di comando per gestire WordPress
if [ ! -f "/usr/local/bin/wp" ]; then
    echo "Installazione di WP-CLI..."
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

# Se il file di configurazione non esiste, vuol dire che è la prima installazione
if [ ! -f "./wp-config.php" ]; then

    echo "WordPress non è configurato. Inizio installazione..."

    # wordPress non può installarsi se MariaDB non è pronto.
    # usiamo un loop che prova a connettersi finché non ci riesce 
    # in cui wdp usa ping per verificare la disponibilita del DB
    echo "Attesa che MariaDB sia pronto..."
    while ! mariadb-admin --host=mariadb --user=$SQL_USER --password=$SQL_PASSWORD ping --silent; do
        sleep 2
        echo "MariaDB non risponde ancora... riprovo..."
    done
    echo "MariaDB è connesso!"

    # scarica i file core di WordPress nella cartella corrente
    wp core download --allow-root

    # collegamento al DB
    wp config create \
        --dbname=$SQL_DATABASE \
        --dbuser=$SQL_USER \
        --dbpass=$SQL_PASSWORD \
        --dbhost=mariadb:3306 \
        --allow-root

    # Crea le tabelle nel DB e imposta l'admin
    wp core install \
        --url=$DOMAIN_NAME \
        --title=$WP_TITLE \
        --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL \
        --allow-root

    # --- 7. Creazione Utente Secondario (Richiesto dal subject) ---
    # Crea un utente editor/autore che non sia admin
    wp user create \
        $WP_USER \
        $WP_EMAIL \
        --user_pass=$WP_PASSWORD \
        --role=author \
        --allow-root
    
    echo "WordPress installato e configurato con successo!"

else
    echo "WordPress è già configurato. Salto l'installazione."
fi

# exec fa partire effettivamente il container
# -F forza l'esecuzione in primo piano (foreground) per non far morire il container.
echo "Avvio PHP-FPM..."
exec /usr/sbin/php-fpm7.4 -F