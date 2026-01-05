# USER_DOC.md — User Documentation

Questo documento spiega come un utente o un amministratore può gestire l'infrastruttura Docker del progetto Inception.

---

## 1. Understand what services are provided by the stack
*(Comprendere i servizi forniti dallo stack)*

L'infrastruttura utilizza **Docker Compose** per avviare tre container isolati che comunicano su una rete interna:

* **NGINX (Web Server):** Il punto di ingresso unico. Gestisce le connessioni HTTPS (porta 443) con protocollo TLS v1.2/v1.3 e reindirizza le richieste a WordPress.
* **WordPress + PHP-FPM:** Il CMS dove risiede il sito web. Non è esposto direttamente, ma è accessibile solo tramite NGINX.
* **MariaDB:** Il database che memorizza i dati di WordPress.

---

## 2. Start and stop the project
*(Avviare e arrestare il progetto)*

Tutti i comandi devono essere eseguiti dalla radice del progetto tramite il **Makefile**.

* **Prerequisito:** Assicurati che il tuo dominio sia nel file `/etc/hosts`:
    `127.0.0.1 login.42.fr` (sostituisci `login` con il tuo user).

* **Avviare il progetto:**
    Costruisce le immagini e avvia i container in background.
    ```bash
    make
    # oppure: make up
    ```

* **Arrestare il progetto:**
    Ferma i container mantenendo i dati salvati nei volumi.
    ```bash
    make stop
    # oppure: make down
    ```

* **Reset completo (Wipe):**
    Ferma tutto ed elimina anche i dati persistenti (database e file sito).
    ```bash
    make fclean
    ```

---

## 3. Access the website and the administration panel
*(Accedere al sito web e al pannello di amministrazione)*

Una volta avviati i servizi, apri il browser (Firefox/Chrome):

* **Sito Web Principale:**
    * URL: `https://login.42.fr` (Sostituisci `login` con il tuo username 42).
    * *Nota:* Accetta l'avviso di sicurezza del certificato auto-firmato (Avanzate -> Procedi).

* **Pannello di Amministrazione (WordPress):**
    * URL: `https://login.42.fr/wp-admin`
    * Login: Utilizza le credenziali di amministratore definite nel file `.env` (vedi sezione successiva).

---

## 4. Locate and manage credentials
*(Individuare e gestire le credenziali)*

Per sicurezza, nessuna password è scritta nel codice. Tutte le credenziali si trovano nel file di configurazione delle variabili d'ambiente.

* **Percorso del file:** `srcs/.env`
* **Variabili chiave da consultare:**
    * `WP_ADMIN_USER`: Username per accedere a `/wp-admin`.
    * `WP_ADMIN_PASSWORD`: Password per accedere a `/wp-admin`.
    * `MYSQL_USER` / `MYSQL_PASSWORD`: Credenziali che WordPress usa per connettersi al DB.
    * `MYSQL_ROOT_PASSWORD`: Password di root per MariaDB.

> **Importante:** Se modifichi questo file, devi rigenerare i container con `make re` per applicare le nuove password.

---

## 5. Check that the services are running correctly
*(Verificare che i servizi stiano funzionando correttamente)*

Usa i comandi Docker per verificare lo stato dell'infrastruttura:

* **Verifica stato (Status):**
    Assicurati che i container `nginx`, `mariadb` e `wordpress` siano in stato **Up**.
    ```bash
    docker ps
    ```

* **Verifica Log (Troubleshooting):**
    Se un servizio non risponde, controlla i log per vedere gli errori in tempo reale.
    ```bash
    docker logs nginx
    docker logs wordpress
    docker logs mariadb
    ```

* **Verifica Volumi:**
    Controlla che i volumi per la persistenza dei dati siano montati:
    ```bash
    docker volume ls
    ```
