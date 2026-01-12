DOCKER = docker compose
FLAGS_BUILD = --build -d
WORDPRESS_VOL_PATH = /home/francesco/data/wordpress/*
MARIADB_VOL_PATH = /home/francesco/data/mariadb/*


up:
	cd srcs && $(DOCKER) up $(FLAGS_BUILD)	

down:
	cd srcs && $(DOCKER) down -v

ps:
	cd srcs && $(DOCKER) ps

logs:
	cd srcs && $(DOCKER) logs

nginx:
	cd srcs && $(DOCKER) exec nginx sh

re: down build

delete:
	docker system prune -af --volumes ; docker volume prune -af ;

rebuild:
	sudo make down && \
	sudo make delete && \
	sudo make down && \
	sudo make up