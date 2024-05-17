FROM openjdk:17-jdk-slim

RUN mkdir /app

WORKDIR /app

COPY build/libs/rest-0.0.1.jar /app

EXPOSE 8080

CMD ["java", "-jar", "rest-0.0.1.jar"]
