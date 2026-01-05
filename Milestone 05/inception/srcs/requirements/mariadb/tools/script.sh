#!/bin/bash

set -eux

# flag per la prima inizializzazione
FIRST=1

# inizializza datadir se mancano le tabelle di sistema
if [ ! -d /var/lib/mysql/mysql ]; then
    echo "Initializing MariaDB data directory"
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
else
    echo "MariaDB data directory already initialized"
    FIRST=0
fi

# crea dir runtime e assegna permessi a mysql
mkdir -p /var/run/mysqld
chown -R mysql:mysql /var/run/mysqld
chown -R mysql:mysql /var/lib/mysql

# avvio temporaneo per configurazione
echo "Starting MariaDB server"
mysqld_safe --user=mysql --datadir=/var/lib/mysql --pid-file=/var/run/mysqld/mysqld.pid &
pid="$!"

# attende che il server risponda a ping
echo "Waiting for MariaDB to start..."
for i in {30..0}; do
    if mysqladmin ping --silent; then
        break
    fi
    sleep 1
done

if [ "$i" = 0 ]; then
    echo >&2 "MariaDB did not start"
    exit 1
fi

# se prima inizializzazione, accedi senza password; altrimenti usa root pwd
if [ "$FIRST" -eq "1" ]; then
    DB_PASS=""
    echo "First time setup"
else
    DB_PASS="-p${MYSQL_ROOT_PASSWORD}"
    echo "Not first time setup"
fi

# crea/aggiorna utenti e database richiesti
echo "Setting up database and users"
mysql -u root ${DB_PASS} <<EOSQL
    CREATE USER IF NOT EXISTS 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
    CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
    ALTER USER 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

    GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' WITH GRANT OPTION;
    GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;
    FLUSH PRIVILEGES;

    CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};

    CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
    ALTER USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
    GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
    FLUSH PRIVILEGES;
EOSQL

# arresta l'istanza temporanea
mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
wait "$pid"

# avvio definitivo in foreground
echo "Starting MariaDB server"
touch /tmp/mariadb_ready
mysqld --user=mysql --datadir=/var/lib/mysql --pid-file=/var/run/mysqld/mysqld.pid