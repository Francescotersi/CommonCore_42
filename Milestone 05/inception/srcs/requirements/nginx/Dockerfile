FROM debian:bullseye
# base Debian per Nginx con SSL self-signed

# installa Nginx e OpenSSL
RUN  apt-get update \
     && apt-get install -y nginx openssl \
     && apt-get clean \
     && rm -rf /var/lib/apt/lists/*

# copia configurazione del virtual host
COPY ./conf/nginx.conf /etc/nginx/conf.d/

# directory per certificati SSL
RUN mkdir -p /etc/nginx/ssl

# genera certificato e ceritficato self-signed
RUN openssl req -newkey rsa:2048 -x509 -sha256 -days 365 -nodes \
     -keyout /etc/nginx/ssl/file.key \
     -out /etc/nginx/ssl/file.crt \
     -subj "/C=IT/ST=Toscana/L=Firenze/O=42 Firenze/OU=IT/CN=login.42.fr/emailAddress=ftersill@student.42firenze.it"

# directory runtime
RUN mkdir -p /run/nginx

# avvia nginx in foreground (necessario in container)
ENTRYPOINT ["nginx"]
CMD ["-g", "daemon off;"]