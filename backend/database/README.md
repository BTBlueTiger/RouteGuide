# RouteGuide - Database

### Info

![](https://img.shields.io/badge/Database-Postgres%2016-blue?style=for-the-badge&logo=postgresql)

### Setup

**Dependencies**
* Docker

___
**1. Pull the image**
```bash
docker pull postgres:latest
```

**2. Build the container**
````bash
docker run --name RouteGuide -p 5432:5432 -e POSTGRES_PASSWORD=routeguideroot -d postgres
````

**3. Connect to the database using a tool of your choice**

examples:
````
Datagrip
pgAdmin
````

**4. Run the creation scripts from the current directory**

example if psql is installed:
```bash
psql -h localhost -U postgres -d postgres -a -f create.sql
```