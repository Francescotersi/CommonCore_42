
################################################################################
# Simple Makefile for Inception (root)
# - Minimal, readable targets to manage docker compose
################################################################################

# Path to docker-compose file (override with env if needed)
COMPOSE_FILE ?= srcs/docker-compose.yml

# Host data dir used by containers (override with env if needed)
DATA_DIR ?= $(HOME)/data

# Compose command (modern Docker: `docker compose`)
DOCKER_COMPOSE ?= docker compose

.PHONY: help validate up down build logs ps fclean re

help:
	@echo "Usage: make [target]"
	@echo
	@echo "Targets:"
	@echo "  help       - Show this help"
	@echo "  validate   - Validate $(COMPOSE_FILE) (if docker available)"
	@echo "  up         - Build and start all services (creates local data dirs)"
	@echo "  down       - Stop all services"
	@echo "  build      - Build images without starting containers"
	@echo "  logs       - Follow logs for all services"
	@echo "  ps         - Show service status"
	@echo "  fclean     - Stop, remove volumes/images, and remove local data dirs"
	@echo "  re         - Recreate from scratch (fclean then up)"
	@echo
	@echo "Variables (can override): COMPOSE_FILE=$(COMPOSE_FILE), DATA_DIR=$(DATA_DIR), DOCKER_COMPOSE=$(DOCKER_COMPOSE)"

validate:
	@echo "Validating compose file: $(COMPOSE_FILE)"
	@if [ ! -f "$(COMPOSE_FILE)" ]; then \
		echo "Error: compose file '$(COMPOSE_FILE)' not found." >&2; exit 1; \
	fi
	@if command -v docker >/dev/null 2>&1; then \
		$(DOCKER_COMPOSE) -f "$(COMPOSE_FILE)" config || true; \
	else \
		echo "Warning: docker not found, skipping compose validation."; \
	fi

up: validate
	@echo "Starting Inception (build + up)"
	@mkdir -p "$(DATA_DIR)/wordpress" "$(DATA_DIR)/mariadb"
	@$(DOCKER_COMPOSE) -f "$(COMPOSE_FILE)" up -d --build

down:
	@echo "Stopping Inception"
	@$(DOCKER_COMPOSE) -f "$(COMPOSE_FILE)" down

build:
	@echo "Building images"
	@$(DOCKER_COMPOSE) -f "$(COMPOSE_FILE)" build

logs:
	@$(DOCKER_COMPOSE) -f "$(COMPOSE_FILE)" logs -f --tail=200

ps:
	@$(DOCKER_COMPOSE) -f "$(COMPOSE_FILE)" ps

fclean: down
	@echo "Deep clean: removing volumes/images and local data dirs"
	@$(DOCKER_COMPOSE) -f "$(COMPOSE_FILE)" down --volumes --rmi all
	@if [ -d "$(DATA_DIR)/wordpress" ]; then rm -rf "$(DATA_DIR)/wordpress"; fi
	@if [ -d "$(DATA_DIR)/mariadb" ]; then rm -rf "$(DATA_DIR)/mariadb"; fi

re: fclean up

