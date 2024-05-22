
# RouteGuide - Backend

### Version & Build Info

![](https://img.shields.io/badge/Current%20Version-1.1.0-green?style=for-the-badge&logo=git)

![TeamCity build status](http://94.16.31.72:8111/app/rest/builds/buildType:id:RouteGuide_BuildApi,branch:name:dev/statusIcon.svg)

### Stack Info

![](https://img.shields.io/badge/Java%20SDK-17%20LTS-orange?style=for-the-badge&logo=java)
![](https://img.shields.io/badge/Jakarta%20EE-9.1.0-green?style=for-the-badge&logo=Jakarta)
![](https://img.shields.io/badge/Spring%20-6.1-green?style=for-the-badge&logo=Spring)

![](https://img.shields.io/badge/Gradle-8.7-blue?style=for-the-badge&logo=gradle)
![](https://img.shields.io/badge/PostgreSQL-16-blue?style=for-the-badge&logo=postgresql)

___
[![](https://img.shields.io/badge/Download-Latest-blue?style=for-the-badge&logo=)](https://github.com/BTBlueTiger/RouteGuide/releases)

### Managed Dependencies

The dependencies are managed by Gradle, so you don't need to worry about them. If you need to update a dependency, you can do so by editing the `build.gradle` file.

```groovy  
    // RabbitMQ DEPENDENCIES
    implementation('com.rabbitmq:amqp-client:5.20.0')

    //Spring DEPENDENCIES
    implementation("org.springframework.boot:spring-boot-starter-amqp")
    implementation("org.springframework.boot:spring-boot-starter-data-jpa")
    implementation("org.springframework.boot:spring-boot-starter-jdbc")
    implementation("org.springframework.boot:spring-boot-starter-mail")
    implementation("org.springframework.boot:spring-boot-starter-web")
    compileOnly("org.projectlombok:lombok")
    developmentOnly("org.springframework.boot:spring-boot-devtools")
    //developmentOnly("org.springframework.boot:spring-boot-docker-compose")
    runtimeOnly("org.postgresql:postgresql")
    annotationProcessor("org.projectlombok:lombok")
    testImplementation("org.springframework.boot:spring-boot-starter-test")
    testImplementation("org.springframework.amqp:spring-rabbit-test")
```

## How to work with this project

This microservice uses Gradle as build tool. Most IDEs with Gradle support will allow you to open the build.gradle file and build the entire project from there.

Installing Gradle is not required as the project comes with a Gradle wrapper, but it is recommended to install it to your system anyway, since it can make the build process faster to build by hand.

**Building the project**
```bash 
gradle clean build
```

## Building / Running the docker container
**1. Build the image**
```bash
docker build -t dubskysteam/routeguide:TAG .
```

or pull the image from the registry
```bash
docker pull dubskysteam/routeguide:TAG
```

**2. Build and run the container**
```bash
docker run -d \
  -p 8080:8080 \
  -e RG_DB_USERNAME="your_username" \
  -e RG_DB_PASSWORD="your_password" \
  -e RG_DB_HOST="your_db_host" \
  -e RG_DB_PORT="your_db_port" \
  -e RG_JWT_SECRET="your_jwt_secret" \
  dubskysteam/routeguide:TAG
```

**3. Check the logs**
```bash
docker logs -f <container_id>
```

## Setting up RabbitMQ

**Dependencies**
* Docker-Desktop
* JDK 17+

**1. Pull the image**
```bash
docker pull rabbitmq:3-management
```

**2. Build the container**
````bash
docker run -d --hostname RabbitGuide --name SmartRabbit -p 15672:15672 -p 5672:5672 rabbitmq:3-management
````

**3. Log into the interface**
````
http://localhost:15672

creds: guest | guest
````

**4. Create new user**
Go to "Admin" and create a new user with the following credentials
````
admin | admin
````
Now also give that user **all** permissions. This will be the admin user from now on.

**5. Create the exchanges**
Go to "Exchanges" and create the following exchanges
````
````

**6. Create the queues**
Go to "Queues" and create the following queues
````
````

## Deployment errors & solutions

````
Initialization failed for Singleton RabbitOverlord
````
**Solution:** RabbitMQ is not running. Start it up and try again.
````
Hibernate Error
````
**Solution:** The database is not reachable. Start it up and try again.
Also has been known to happen when the database is not setup correctly.
