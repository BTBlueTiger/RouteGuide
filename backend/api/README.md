
# RouteGuide - Backend

### Version & Build Info

![](https://img.shields.io/badge/Current%20Version-1.0.0-green?style=for-the-badge&logo=git)

![GitHub Workflow Status (with event)](https://img.shields.io/github/actions/workflow/status/dubskysteam/AQP/.github%2Fworkflows%2Fgradle.yml?branch=dev&style=for-the-badge&logo=teamcity)

### Stack Info

![](https://img.shields.io/badge/Java%20SDK-21%20LTS-orange?style=for-the-badge&logo=java)
![](https://img.shields.io/badge/Jakarta%20EE-9.1.0-green?style=for-the-badge&logo=Jakarta)
![](https://img.shields.io/badge/Spring%20-6.1-green?style=for-the-badge&logo=Spring)

![](https://img.shields.io/badge/Gradle-8.7-blue?style=for-the-badge&logo=gradle)
![](https://img.shields.io/badge/PostgreSQL-16-blue?style=for-the-badge&logo=postgresql)

___
[![](https://img.shields.io/badge/Download-Latest-blue?style=for-the-badge&logo=)](https://github.com/DubskySteam/AQP/releases)

### Managed Dependencies

The dependencies are managed by Gradle, so you don't need to worry about them. If you need to update a dependency, you can do so by editing the `build.gradle` file.

```groovy  
    // RabbitMQ DEPENDENCIES
    implementation('com.rabbitmq:amqp-client:5.20.0')
```

## How to work with this project

This microservice uses Gradle as build tool. Most IDEs with Gradle support will allow you to open the build.gradle file and build the entire project from there.

Installing Gradle is not required as the project comes with a Gradle wrapper, but it is recommended to install it to your system anyway, since it can make the build process faster to build by hand.

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