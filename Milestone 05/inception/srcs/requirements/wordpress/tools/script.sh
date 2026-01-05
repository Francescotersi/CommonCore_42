#!/bin/bash

WP_PATH=/var/www/html

// attende che MariaDB sia raggiungibile via TCP
echo "Waiting for MariaDB to be ready to execute"

until mysqladmin ping -h "mariadb" -P 3306 --silent; do
    echo "Waiting..."
    sleep 1
done
echo "MariaDB is ready to execute!"

# se manca wp-config.php, scarica e installa WordPress impostando cose di base
# come il nome del domain e l'utente admin
if [ ! -f "$WP_PATH/wp-config.php" ]; then
    echo "Downloading WordPress core..."
    wp core download --allow-root
    echo "Creating wp-config.php..."
    wp config create --dbname=${WORDPRESS_DB_NAME} \
        --dbuser=${WORDPRESS_DB_USER} \
        --dbpass=${WORDPRESS_DB_PASSWORD} \
        --dbhost=mariadb:3306 \
        --allow-root
    echo "Installing WordPress..."
    wp core install --url=${DOMAIN_NAME} \
        --title="ftersill's site" \
        --admin_user=${WORDPRESS_ADMIN_USER} \
        --admin_password=${WORDPRESS_ADMIN_PASSWORD} \
        --admin_email=${WORDPRESS_ADMIN_EMAIL} \
        --allow-root
else
    echo "WordPress is already installed!"
fi

# crea utente autore se non esiste già
if ! wp user get ${WORDPRESS_USER} --path=$WP_PATH --allow-root > /dev/null 2>&1; then
    echo "Creating user ${WORDPRESS_USER}..."
    wp user create ${WORDPRESS_USER} ${WORDPRESS_EMAIL} \
    --role=author \
    --user_pass=${WORDPRESS_PASSWORD} \
    --path=$WP_PATH \
    --allow-root
else
    echo "User ${WORDPRESS_USER} already exists."
fi

# imposta URL del sito per HTTPS
wp option update siteurl 'https://ftersill.42.fr' --allow-root
wp option update home 'https://ftersill.42.fr' --allow-root

# avvia PHP-FPM in foreground (necessario per Docker)
echo "Starting PHP-FPM..."

exec php-fpm7.4 -F