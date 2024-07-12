FROM openjdk:17-jdk-slim

RUN mkdir /app

WORKDIR /app

COPY build/libs/rest-1.6.8.jar /app

EXPOSE 8080

CMD ["java", "-jar", "rest-1.6.8.jar"]
