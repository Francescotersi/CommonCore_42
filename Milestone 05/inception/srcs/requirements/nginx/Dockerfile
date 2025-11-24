FROM debian:bullseye

# Installa NGINX e OpenSSL
RUN apt-get update && apt-get install -y nginx openssl

# crea la cartella per i certificati SSL
RUN mkdir -p /etc/nginx/ssl

# genera certificato self-signed e chiave privata senza passphrase
# -x509: crea un certificato self-signed
# -newkey rsa:2048: genera una nuova chiave RSA a 2048 bit
# -nodes: rendi la richiesta senza passphrase
# -keyout: percorso della chiave privata
# -out: percorso del certificato
# -days: validità del certificato in giorni
# -subj: evita prompt interattivi impostando i campi del Distinguished Name
RUN openssl req -x509 -newkey rsa:2048 -nodes \
    -keyout /etc/nginx/ssl/inception.key \
    -out /etc/nginx/ssl/inception.crt \
    -days 365 \
    -subj "/C=IT/ST=Tuscany/L=Florence/O=42 Corporation/CN=ftersill.42.fr/UID=ftersill"


COPY conf/nginx.conf /etc/nginx/nginx.conf

# crea la cartella per i permessi corretti
RUN mkdir -p /var/run/nginx

EXPOSE 443

# avvia NGINX in foreground
# senza "daemon off;" il container si spegne subito dopo l'avvio.
CMD ["nginx", "-g", "daemon off;"]