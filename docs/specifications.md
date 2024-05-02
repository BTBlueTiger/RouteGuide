
# Anforderungs- und Entwurfsspezifikation ("Pflichtenheft")
# 0 Titelseite
* Projektname: RouteGuide
* Autoren:
*   - Malte Kanders
    - Clemens Maas
* Inhaltsverzeichnis
# 1 Einführung
## 1.1 Beschreibung
* Ein Tool zum erstellen, speichern und veröffentlichen von Routen.
# 2 Anforderungen
## 2.1 Stakeholder
| Funktion / Relevanz | Name | Kontakt / Verfügbarkeit | Wissen | Interessen / Ziele |
|---|---|---|---|---|
|Product Owner|Brunsman|---|Allwissend|---|
|Backend Developer|Clemens Maas|---|---|---|
|Frontend Developer|Malte Kanders|---|---|Vereinfachung des Nebenjobs|
| | | | | |
## 2.2 Funktionale Anforderungen
* ggfs. Use-Case Diagramme
* Strukturierung der Diagramme in funktionale Gruppen
* Definition der Akteure
* Akteure sowie andere Begriffe der implementierten Fachdomäne definieren
* Begriffe konsistent in der Spezifikation verwenden
* Begriffe im Glossar am Ende des Dokuments darstellen
## 2.3 Nicht-funktionale Anforderungen
### 2.3.1 Rahmenbedingungen
* Normen, Standards, Protokolle, Hardware, externe Vorgaben
### 2.3.2 Betriebsbedingungen
Vorallem Mobile Anwendung als Navigation durch die Routen.
Eventuell Desktop oder Web Anwendung für die erweiterten Funktionalitäten.
### 2.3.3 Qualitätsmerkmale
* Externe Qualitätsanforderungen (z.B. Performance, Sicherheit, Zuverlässigkeit,
Benutzerfreundlichkeit)

Qualitätsmerkmal | sehr gut | gut | normal | nicht relevant |
| :------ | :------ | :----- | :------ | :------ |
**Zuverlässigkeit** |-|-|-|-|
Fehlertoleranz |X|-|-|-|
Wiederherstellbarkeit |X|-|-|-|
Ordnungsmäßigkeit |X|-|-|-|
Richtigkeit |X|-|-|-|
Konformität |-|X|-|-|
**Benutzerfreundlichkeit** |-|-|-|-|
Installierbarkeit |-|-|X|-|
Verständlichkeit |X|-|-|-|
Erlernbarkeit |-|X|-|-|
Bedienbarkeit |-|X|-|-|
**Performance** |-|-|-|-|
Zeitverhalten |-|-|X|-|
Effizienz|-|-|-|X|
**Sicherheit** |-|-|-|-|
Analysierbarkeit |X|-|-|-|
Modifizierbarkeit |-|-|-|X|
Stabilität |X|-|-|-|
Prüfbarkeit |X|-|-|-|

## 2.4 Graphische Benutzerschnittstelle
#### Übersicht
![Mockup mit Graph](mockups/RouteGuideMockups.png)
#### Login
![Login](mockups/LoginScreen.png)
Use Cases: 1, 2, 3
#### Map
![Map](mockups/Map.png)
Use Cases: 5, 6, 7, 8
#### Passwort vergessen
![Passwort Vergessen](mockups/ForgotPasswort.png)
Use Case: 1
#### Neuer Nutzer, erste Seite
![Neuer User 0](mockups/NewUser0.png)
#### Neuer Nutzer, zweite Seite
![Neuer User 1](mockups/NewUser1.png)
Use Case: 4
#### Route planen, erste Seite
![Plan a Route 0](mockups/PlanARoute0.png)
#### Route planen, zweite Seite
![Plan a Route 1](mockups/PlanARoute1.png)
Use Cases: 16, 17, 18, 19
#### Profil, erste Seite
![Profile 0](mockups/Profile0.png)
Use Case: 10, 11, 12, 13, 14
#### Profil, zweite Seite
![Profile 1](mockups/Profile1.png)
Use Cases: 15
#### Community
![Community](mockups/Community.png)
Use Cases: 11, 14

* Mockups für unterschiedliche Akteure
* Mockups für unterschiedliche Frontends (Mobil, Web, Desktop)
## 2.5 Anforderungen im Detail

* Sicherheit: Misuse-Stories formulieren

| ID | **Als** | **möchte ich** | **so dass** | **Akzeptanz** |
| :------ | :------ | :----- | :------ | :-------- |
| 1 | Wer | Was | Warum | Wann akzeptiert |
| 2 | Benutzer | einen Button für das zurücksetzen des Passwort | ich mir ein neues Passwort geben lassen kann | Passwort wird durch neues ersetzt |
| 3 | Benutzer | einen Button zum erstellen eines Profils | ich als neuer Nutzer ein neues Profil machen kann | Benutzer wird angelegt und beim Login erkannt |
| 4 | Backend  | keine Fehlerhaften Anfragen | bei fehlerhafter Mail keine Anfrage geschickt wird | Falsche Email wird nicht angenommen |
| 5 | Benutzer | den Grund für meine Anmeldung angeben | damit ich für mich passende Routen finde | User wird einer Gruppe zugeordnet |
| 6 | Benutzer | eine simple Kartenansicht | damit ich mich auf das wesentliche konzentrieren kann | Simple Karten Ansicht |
| 7 | Benutzer | bei einer Navigation eine sich mitbewegende Karte | damit ich immer genau weiß wo ich bin und lang will/muss | Mitbewegende Karte |
| 8 | System | standortfreigabe vom Nutzer | damit die Karte und die geteilten Routen in etwa zu dem User passen | Standort des Users bekommen |
| 9 | Benutzer | die Karte wieder auf den Nutzer zentrieren | damit man bei verschobener Karte sich wieder findet | Button der den Nutzer zentriert
| 10 | Benutzer | zwischen den Hauptanwendungen leicht hin und her wechseln können | damit die App nicht überfordert | Navigationsleiste mit wesentlichen Anwendungen |
| 11 | Benutzer | die Möglichkeit bereits gefasste Routen zu speichern | damit ich Routen wiederholen kann | Speichermöglichkeit für Routen |
| 12 | Benutzer | die Möglichkeit gespeicherte Routen mit anderen zu teilen | damit ich Routen von anderen ausprobieren kann und eigene teilen kann | Teil Möglichkeit von gespiecherten Routen |
| 13 | Benutzer | bereits gefasste Routen wieder entfernen kann | so das ich meine Routen auch wieder löschen kann | Gespeicherte und/oder geteilte Routen löschen |
| 14 | Benutzer | routen die ich geliked habe wiederfinden | ich mir gefallende Routen öfters aufrufen kann | Gelikede Routen in meinem Profil wiederfinden |
| 15 | System | routen sollen bewertet werden können | user gut bewertete Routen finden können | Ein User bestimmtes Bewertungssystem
| 16 | Benutzer | mein Profil und meine Gruppe wechseln | um auch Routen zu erhalten die der User zuerst als unrelevant ansah | Eine Seite im Profil mit Tick Boxen |
| 17 | Benutzer | eine Route bestehend aus vielen Stops erstellen | um eine Route mit Zwischenstops erstellen zu können | Route aus einer Liste von Routen erstellen |
| 18 | Benutzer | Punkte auf der Kart anklicken um sie in die Routenplanung aufzunehmen | unabhängig von Straßen auch andere Wegpunkte setzen kann | Map Ansicht mit der Möglichkeit für Wegpunkte |
| 19 | Benutzer | eine optimierte Route erstellen können | um aus mehreren Wegpunken eine Optimale Strecke zu erstellen | Erstellen einer optimierten Route mithilfe eines Buttons |
| 20 | Benutzer | eine Route erstellen die nicht optimiert ist | um eine Route auch so zu haben wie der Nutzer es wollte | Erstellen einer unoptimierten Route mithilfe eines Buttons |
| x | System | dauer der Route soll gespeichert werden | es eine Durschschnitt und Bestzeit gibt | Zeitmessung der Navigation |
| x | System | listen sollen intuitiv scrollbar sein | so das es im Prinzip unendlich lange Listen gibt | Scrollbare Listen |


# 3 Technische Beschreibung
## 3.1 Systemübersicht
![](diagrams/backend/architecture_simple.png)
## 3.2 Softwarearchitektur
![](diagrams/backend/architecture.png)
### 3.2.1 Technologieauswahl
Beschreiben Sie hier, welche Frameworks / Technologien / Bibliotheken / Datenformate /
Protokolle benutzt werden. 

QT als Crossplattform Framework.
  - QT Quick mit QML da vorrangig das Smartphone genutzt werden soll
  - Direkter vergleich von MAUI einem .NET Frameork, primär für Mobile Anwendung zeigten, QT ist perfomanter.
  - [Openrouteservice](https://openrouteservice.org/) Hilft beim erstellen von Routen  
  - [OpenstreetMap](https://www.openstreetmap.de/) Darstellen von der Karte

Backend
  - Java + Spring als Authentifizierungsserver
  - Rust + Rocket als REST API
  - RabbitMQ als Message Broker
  - PostgreSQL als Datenbank
  - TeamCity als CI/CD Pipeline
## 3.3 Schnittstellen
* Schnittstellenbeschreibung (API)
* Auflistung der nach außen sichtbaren Schnittstelle der Softwarebausteine
Hier sollen sämtliche Schnittstellen definiert werden:
* die externen Schnittstellen nach außen. Über welche Schnittstelle kann z.B. der Client
den Server erreichen?
* die internen Schnittstellen der unter 3.2 definierten Softwarebausteine
Es ist sinnvoll, wenn die API von denjenigen definiert werden, die die Anforderungen an
die API kennen: in einem Client-Server-System haben die Client-Entwickler Anforderungen
an die Backend-Entwickler, so dass in diesem Fall die Client-Entwickler die API
definieren sollten, die dann vom Backend-Entwickler implementiert werden.
## 3.3.1 Ereignisse
* In Event-gesteuerten Systemen: Definition der Ereignisse und deren Attribute
## 3.4 Datenmodell
* Konzeptionelles Analyseklassendiagramm (logische Darstellung der Konzepte der
Anwendungsdomäne)
* Modellierung des physikalischen Datenmodells
* RDBMS: ER-Diagramm bzw. Dokumentenorientiert: JSON-Schema
## 3.5 Abläufe
* Aktivitätsdiagramme für relevante Use Cases
* Aktivitätsdiagramm für den Ablauf sämtlicher Use Cases
* Aktivitätsdiagramm mit Swimlanes sind in der Regel hilfreich
für die Darstellung der Interaktion von Akteuren der Use Cases / User Stories
* Abläufe der Kommunikation von Rechnerknoten (z.B. Client/Server)
in einem Sequenz- oder Aktivitätsdiagramm darstellen
* Modellieren Sie des weiteren die Diagramme, die für das (eigene) Verständnis des
Softwaresystems hilfreich sind.
## 3.6 Entwurf
* Detaillierte UML-Diagramme für relevante Softwarebausteine
* ![Frontend UML](diagrams/frontend/frontendUML.png)
## 3.7 Fehlerbehandlung
* Mögliche Fehler / Exceptions auflisten
* Fehlercodes / IDs sind hilfreich
* Nicht nur Fehler technischer Art ("Datenbankserver nicht erreichbar") definieren,
sondern auch im Hinblick auf
Kapitel 3.8 sind fachliche Fehler wie "Kunde nicht gefunden". "Nachricht wurde bereits
gelöscht" o.ä.

| Fehlercode | Fehlermeldung | Beschreibung | Lösung |
|---|---|---|---|
| 400 | Bad Request | Die Anfrage war fehlerhaft | Überprüfen Sie die Anfrage |
| 401 | Unauthorized | Der User ist nicht berechtigt | Überprüfen Sie die Berechtigungen |
| 403 | Forbidden | Der User hat keine Berechtigung | Überprüfen Sie die Berechtigungen |
| 404 | User not found | Der User konnte nicht gefunden werden | Überprüfen Sie die Eingabe |
| 405 | Method Not Allowed | Die Methode ist nicht erlaubt | Überprüfen Sie die Methode |
| 408 | Request Timeout | Die Anfrage hat zu lange gedauert | Versuchen Sie es später erneut |
| 429 | Too Many Requests | Der Server hat zu viele Anfragen erhalten | Versuchen Sie es später erneut |
| 500 | Server Error | Ein Server Fehler ist aufgetreten | Versuchen Sie es später erneut |
| 503 | Service Unavailable | Der Service ist nicht verfügbar | Versuchen Sie es später erneut |
| 504 | Gateway Timeout | Der Server hat zu lange gebraucht | Versuchen Sie es später erneut |

## 3.8 Validierung
* Relevante (Integrations)-Testfälle, die aus den Use Cases abgeleitet werden können
* Testfälle für
* Datenmodell
* API
* User Interface
* Fokussieren Sie mehr auf Integrationstestfälle als auf Unittests
* Es bietet sich an, die IDs der Use Cases / User Stories mit den Testfällen zu
verbinden, so dass erkennbar ist, ob Sie alle Use Cases getestet haben.
# 4 Projektorganisation
## 4.1 Annahmen
* Nicht durch den Kunden definierte spezifische Annahmen, Anforderungen und
Abhängigkeiten
* C++
* QTQuick
* QT
  
* Aufteilung in Repositories gemäß Software- und Systemarchitektur und Softwarebausteinen
* Einschränkungen, Betriebsbedingungen und Faktoren, die die Entwicklung beeinflussen
(Betriebssysteme, Entwicklungsumgebung)
* Interne Qualitätsanforderungen (z.B. Softwarequalitätsmerkmale wie z.B.
Erweiterbarkeit)
## 4.2 Verantwortlichkeiten
* Zuordnung von Personen zu Softwarebausteinen aus Kapitel "Systemübersicht" und
"Softwarearchitektur"
* Rollendefinition und Zuordnung
| Softwarebaustein | Person(en) |
|----------|-----------|
| Komponente A | Thomas Mustermann |
### Rollenzuordnung
| Name | Rolle |
|----------|-----------|
| Malte Kanders | Frontend-Entwickler |
| Clemens Maas | Backend-Entwickler |
## 4.3 Grober Projektplan
- Meilensteine
### Meilensteine
* KW 43 (21.10)
* Abgabe Pflichtenheft
* KW 44 (28.10) / Projekt aufsetzen
* Repository Struktur
* KW 45 (4.11) / Implementierung
* Implementierung #3 (Final)
* KW 48 (18.12) / Abnahmetests
* manuelle Abnahmetests
* Präsentation / Software-Demo
# 5 Anhänge
## 5.1 Glossar
* Definitionen, Abkürzungen, Begriffe
## 5.2 Referenzen
* Handbücher, Gesetze
* z.B. Datenschutzgrundverordnung
## 5.3 Index
