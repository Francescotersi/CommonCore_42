FROM debian:bullseye

# installa MariaDB server
RUN apt-get update \
    && apt-get install -y mariadb-server \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# configurazione server (porta, socket, bind, log)
COPY ./conf/config.conf /etc/mysql/mariadb.conf.d/50-server.cnf

# script di bootstrap (init DB/utenti, avvio)
COPY ./tools/script.sh /script.sh
RUN chmod +x /script.sh

# avvia lo script; `mysqld` è il comando di default
ENTRYPOINT ["sh", "/script.sh"]
CMD ["mysqld"]