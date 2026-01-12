# Inception 42 — Developer Documentation

## Quick Start

### Prerequisites
- Docker and Docker Compose installed
- Create data directories if they do not exists:
  ```bash
  mkdir -p /home/francesco/data/mariadb
  mkdir -p /home/francesco/data/wordpress
  sudo chown 999:999 /home/francesco/data/mariadb
  sudo chown 33:33 /home/francesco/data/wordpress
  ```

### Build and Start
```bash
sudo make up
```

---

## Essential Commands

| Command | Action |
|---------|--------|
| `sudo make up` | Build and start containers |
| `sudo make down` | Stop and remove containers |
| `sudo make ps` | Show container status |
| `sudo make logs` | View logs |
| `sudo make rebuild` | Full rebuild |

### Container Access
```bash
docker exec -it mariadb bash
docker exec -it wordpress bash
docker exec -it nginx bash
```

### Database Operations
```bash
# Connect to MariaDB
docker exec -it mariadb mysql -u root -p${MYSQL_ROOT_PASSWORD}

# Backup database
docker exec mariadb mysqldump -u root -p${MYSQL_ROOT_PASSWORD} ${MYSQL_DATABASE} > backup.sql

# Restore database
docker exec -i mariadb mysql -u root -p${MYSQL_ROOT_PASSWORD} ${MYSQL_DATABASE} < backup.sql
```

### Test Connectivity
```bash
# WordPress → MariaDB
docker exec wordpress mysqladmin ping -h mariadb -P 3306 --silent

# HTTPS
curl -Ik https://ftersill.42.fr
```

---

## Data Persistence

### Storage Locations
| Service | Host Path | Container Path |
|---------|-----------|-----------------|
| MariaDB | `/home/francesco/data/mariadb/` | `/var/lib/mysql/` |
| WordPress | `/home/francesco/data/wordpress/` | `/var/www/html/` |

Data persists on host even when containers stop.

### Complete Reset
```bash
sudo make down
sudo make delete
rm -rf /home/francesco/data/mariadb/*
rm -rf /home/francesco/data/wordpress/*
sudo make up
```

---

## Troubleshooting

### WordPress can't reach MariaDB
```bash
docker exec wordpress mysqladmin ping -h mariadb -P 3306 --silent
```

### Permission issues
```bash
sudo chown 999:999 /home/francesco/data/mariadb
sudo chown 33:33 /home/francesco/data/wordpress
```

### View logs
```bash
sudo make logs
docker compose -f srcs/docker-compose.yml logs --tail=200 mariadb wordpress nginx
```

---
