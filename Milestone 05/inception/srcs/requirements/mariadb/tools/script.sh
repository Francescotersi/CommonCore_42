#!/bin/sh


# avvia il servizio
service mariadb start 

sleep 5

# se il database esiste
if [ ! -d "/var/lib/mysql/$SQL_DATABASE" ]; then

    echo "Configurazione Iniziale MariaDB..."

    # Mettiamo in sicurezza l'installazione (equivalente a mysql_secure_installation manuale)
    mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PASSWORD';"
    
    # creiamo il database per WordPress
    mysql -u root -p$SQL_ROOT_PASSWORD -e "CREATE DATABASE IF NOT EXISTS \`$SQL_DATABASE\`;"

    # creiamo l'utente per WordPress e diamo i permessi
    # la parte con "@'%'" permette connessioni remote altrimenti wordpress 
    # non riuscirebbe a connettersi essendo in un container diverso
    mysql -u root -p$SQL_ROOT_PASSWORD -e "CREATE USER IF NOT EXISTS '$SQL_USER'@'%' IDENTIFIED BY '$SQL_PASSWORD';"
    mysql -u root -p$SQL_ROOT_PASSWORD -e "GRANT ALL PRIVILEGES ON \`$SQL_DATABASE\`.* TO '$SQL_USER'@'%';"
    
    # aggiorniamo i privilegi
    mysql -u root -p$SQL_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"
    
    echo "Database creato e utente configurato!"
else
    # se il database non esiste
    echo "Il Database esiste già. Salto la configurazione."
fi

# Fermiamo il servizio temporaneo
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown

# Avviamo MariaDB in modalità sicura e in primo piano (fondamentale per Docker)
exec mysqld_safe