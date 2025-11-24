# FROM decide l'ambiente in cui 
FROM debian:bullseye

# aggiorna ed installa mariadb-server
RUN apt update && apt install -y mariadb-server

# Configura le directory e i permessi necessari
# MariaDB ha bisogno di questa cartella per il socket e il PID senno'
# mariadb non parte e va in crash all'avvio con errore 2002
RUN mkdir -p /var/run/mysqld \
    && chown mysql:mysql /var/run/mysqld \
    && chmod 777 /var/run/mysqld

COPY conf/config.conf /etc/mysql/mariadb.conf.d/config.conf

COPY tools/script.sh /usr/local/bin/script.sh

RUN chmod +x /usr/local/bin/script.sh

# Esponi la porta (solo informativa per Docker)
EXPOSE 3306

# Imposta l'entrypoint
ENTRYPOINT ["/usr/local/bin/script.sh"]

CMD ["mysqld"]
