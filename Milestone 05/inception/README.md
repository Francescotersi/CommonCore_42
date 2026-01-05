*This project has been created as part of the 42 curriculum by ftersill.*

# Inception - System Administration with Docker

## Description
This project aims to broaden the knowledge of system administration by using **Docker**. The goal is to virtualize several Docker images, creating a personal web server infrastructure.

Instead of creating a full Virtual Machine, we set up a lightweight infrastructure composed of multiple services (NGINX, WordPress, MariaDB) running in separate containers, orchestrated by **Docker Compose**.

## Instructions

### Prerequisites
* Docker
* Docker Compose
* Make

### Installation & Execution
1.  **Clone the repository:**
    ```bash
    git clone <repo_url>
    cd <repo_folder>
    ```

2.  **Build and Run:**
    Use the `Makefile` to set up the environment easily.
    ```bash
    make up
    ```
    *This command will build the Docker images and start the containers in the background.*

3.  **Access:**
    Open your browser and navigate to `https://ftersill.42.fr` (or `https://localhost`).

4.  **Stop and Clean:**
    ```bash
    make down    # Stops containers
    make delete  # removes images/volumes
    ```

---

## Project Details & Design Choices

### Docker and Sources
This project uses **Debian** as the base for all containers to ensure a lightweight footprint. Custom `Dockerfiles` are used to build each service from source, avoiding pre-made images to ensure deep understanding of the configuration process.

**Main Design Choices:**
* **Decoupling:** Each service (Database, Web Server, PHP application) runs in its own isolated container.
* **Orchestration:** `docker-compose.yml` is used to manage dependencies and networking between containers.

### Technical Comparisons

#### 1. Virtual Machines vs Docker

| Feature | Virtual Machine (VM) | Docker (Container) |
| :--- | :--- | :--- |
| **Architecture** | Virtualizes hardware. Includes a full Guest OS. | Virtualizes the OS. Shares the Host kernel. |
| **Size** | Heavy (GBs). | Lightweight (MBs). |
| **Performance** | Slower boot, higher overhead. | Instant startup, native performance. |
| **Isolation** | High (Hardware level). | Moderate (Process/Namespace level). |

#### 2. Secrets vs Environment Variables
* **Environment Variables:** Stored as plain text. Easy to implement but visible via `docker inspect`. Not recommended for sensitive data (passwords).
* **Docker Secrets:** They are mounted as files inside the container (usually in `/run/secrets/`), ensuring higher security for credentials, but i have the file `/secrets` in the project.

#### 3. Docker Network vs Host Network
* **Docker Network (Bridge):** Creates an isolated network where containers communicate via names. Ports are not exposed to the host unless explicitly mapped.
* **Host Network:** The container shares the networking namespace of the host. It uses the host's IP and ports directly, removing network isolation.

#### 4. Docker Volumes vs Bind Mounts

* **Docker Volumes:** Managed completely by Docker (stored in `/var/lib/docker/volumes/`). Easier to back up, migrate, and safer for data persistence across container restarts.
* **Bind Mounts:** Maps a file or directory on the host machine to the container. Dependent on the host's file structure. Useful for development to see code changes instantly.

---

## Resources

### References
* [Official Docker Documentation](https://docs.docker.com/)
* [Docker Compose Specification](https://docs.docker.com/compose/)
* [NGINX Documentation](https://nginx.org/en/docs/)

### AI Usage
AI tools (e.g., ChatGPT/Claude) were used in this project for the following tasks:
* **Concept Clarification:** To better understand how Docker works and how containers works.
* **Debugging:** To troubleshoot syntax errors in the NGINX configuration file.
* **Documentation:** Assistance in summarizing the technical differences between VM and Containers for this README.
