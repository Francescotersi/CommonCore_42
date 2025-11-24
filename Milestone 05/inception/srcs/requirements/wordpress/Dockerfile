FROM debian:bullseye

# aggiorna e installa: 
# - php
# - php-mysql
# - mariadb-client
# - curl: Per scaricare WP-CLI
RUN apt-get update && apt-get install -y \
    php7.4-fpm \
    php7.4-mysql \
    mariadb-client \
    curl \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/php

COPY ./tools/script.sh /usr/local/bin/script.sh

RUN chmod +x /usr/local/bin/script.sh

# 6. Imposta la cartella di lavoro dove scaricheremo WordPress
WORKDIR /var/www/html

EXPOSE 9000

# COPY ./tools/wp-config.php /var/www/html/wp-config.php


CMD [ "/usr/local/bin/script.sh" ]