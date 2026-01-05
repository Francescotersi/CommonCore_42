FROM debian:bullseye

# installa PHP, client MariaDB e utilità base
RUN apt-get update \
    && apt-get install -y wget curl mariadb-client \
    && apt-get install -y php php-fpm php-mysql php-cli php-curl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# crea document root e imposta permessi
RUN mkdir -p /var/www/html
RUN chown -R www-data:www-data /var/www/html/
RUN chmod -R 755 /var/www/html/

# configura PHP-FPM per ascoltare sulla porta 9000
RUN sed -i 's|listen = .*|listen = 9000|' /etc/php/7.4/fpm/pool.d/www.conf

# installa Wordpress Client
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp \
    && wp cli update

# directory runtime per PHP-FPM
RUN mkdir -p /run/php

COPY ./tools/script.sh /
# rende eseguibile lo script di bootstrap
RUN chmod +x /script.sh
# imposta cartella di lavoro
WORKDIR /var/www/html/

# avvia lo script all'entrypoint
ENTRYPOINT [ "sh" , "/script.sh" ]