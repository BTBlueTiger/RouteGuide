
# RouteGuide - Backend

### Version & Build Info

![](https://img.shields.io/badge/Current%20Version-1.6.2-green?style=for-the-badge&logo=git)

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
// Spring Boot
implementation("org.springframework.boot:spring-boot-starter-amqp")
implementation("org.springframework.boot:spring-boot-starter-data-jpa")
implementation("org.springframework.boot:spring-boot-starter-jdbc")
implementation("org.springframework.boot:spring-boot-starter-mail")
implementation("org.springframework.boot:spring-boot-starter-web")
implementation("org.springframework.boot:spring-boot-starter-security")
implementation("org.springframework.security:spring-security-test")
developmentOnly("org.springframework.boot:spring-boot-devtools")
testImplementation("org.springframework.boot:spring-boot-starter-test")
runtimeOnly("org.postgresql:postgresql")

// Lombok
compileOnly("org.projectlombok:lombok:edge-SNAPSHOT")
annotationProcessor("org.projectlombok:lombok:edge-SNAPSHOT")

// RabbitMQ
testImplementation("org.springframework.amqp:spring-rabbit-test")

// OpenAPI
implementation("javax.servlet:javax.servlet-api:4.0.1")
implementation("org.springdoc:springdoc-openapi-starter-webmvc-ui:2.5.0")

// JSON Web Token
implementation("io.jsonwebtoken:jjwt-api:0.12.5")
runtimeOnly("io.jsonwebtoken:jjwt-impl:0.12.5")
runtimeOnly("io.jsonwebtoken:jjwt-jackson:0.12.5")

// Google
implementation("com.google.maps:google-maps-services:2.2.0")
implementation("org.slf4j:slf4j-simple:1.7.25")

// AdvancedLog
implementation("dev.dubsky:advancedlog:0.1.3")
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
  -e GOOGLE_API_KEY="your_google_api_key" \
  dubskysteam/routeguide:TAG
```

**3. Check the logs**
```bash
docker logs -f <container_id>
```

## Deployment errors & solutions
````
Hibernate Error
````
**Solution:** The database is not reachable. Start it up and try again.
Also has been known to happen when the database is not setup correctly.
