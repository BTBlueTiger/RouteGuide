
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
| | | | | |
### Beispiel
| Funktion / Relevanz | Name | Kontakt / Verfügbarkeit | Wissen | Interessen / Ziele |
|---|---|---|---|---|
| Leiter der Bibliothek, Fachlicher Entscheider | Herr Bauer | Tel. 409000, Von 9-19
Uhr telefonisch erreichbar, Mitarbeit zu 30% möglich, Nürnberg | Kennt das Altsystem aus
der Anwendersicht, soll mit dem System arbeiten | Vereinfachung der Ausleihprozesse |
| Administrator, Informationslieferant bzgl. Wartungsanforderungen | Herr Heiner |
Heiner@gmx.net, Per E-Mail, immer erreichbar, Verfügbarkeit 50%, Nürnberg | Vertraut mit
vergleichbarer Verwaltungssoftware | Stabiles System, geringer Wartungsaufwand |
| Product-Owner, Entscheider - als Koordinator der Stakeholderanforderungen | Paul
Ottmer | po@ottmer.de, Per E-Mail und tel. tagsüber, Verfügbarkeit 100%, Nürnberg |
Koordinator für die Inputs der Stakeholder | ROI des Systems sicherstellen |
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
Qualitätsmerkmal | sehr gut | gut | normal | nicht relevant
---|---|---|---|---
**Zuverlässigkeit** | | | | |
Fehlertoleranz |X|-|-|-|
Wiederherstellbarkeit |X|-|-|-|
Ordnungsmäßigkeit |X|-|-|-|
Richtigkeit |X|-|-|-|
Konformität |-|X|-|-|
**Benutzerfreundlichkeit** | | | | |
Installierbarkeit |-|-|X|-|
Verständlichkeit |X|-|-|-|
Erlernbarkeit |-|X|-|-|
Bedienbarkeit |-|X|-|-|
**Performance** | | | | |
Zeitverhalten |-|-|X|-|
Effizienz|-|-|-|X|
**Sicherheit** | | | | |
Analysierbarkeit |X|-|-|-|
Modifizierbarkeit |-|-|-|X|
Stabilität |X|-|-|-|
Prüfbarkeit |X|-|-|-|
## 2.4 Graphische Benutzerschnittstelle
* GUI-Mockups passend zu User Stories
* Screens mit Überschrift kennzeichnen, die im Inhaltsverzeichnis zu sehen ist
* Unter den Screens darstellen (bzw. verlinken), welche User Stories mit dem Screen
abgehandelt werden
* Modellierung der Navigation zwischen den Screens der GUI-Mockups als Zustandsdiagramm
* Mockups für unterschiedliche Akteure
* Mockups für unterschiedliche Frontends (Mobil, Web, Desktop)
## 2.5 Anforderungen im Detail
* User Stories mit Akzeptanzkritierien
* Optional: Name (oder ID) und Priorität ("Must", "Should", "Could", "Won't")
* Strukturierung der User Stories in funktionale Gruppen
* Sicherheit: Misuse-Stories formulieren
### Schablone für User Stories
| **Als** | **möchte ich** | **so dass** | **Akzeptanz** |
| :------ | :----- | :------ | :-------- |
| Wer | Was | Warum | Wann akzeptiert |
### Beispiel 1
| **Als** | **möchte ich** | **so dass** | **Akzeptanz** |
| :------ | :----- | :------ | :-------- |
| Benutzer | bei Fehleingabe die Lösung angezeigt bekommen | ich lernen kann | Lösung
wird angezeigt |
### Beispiel 2
| **Name**| **In meiner Rolle als**...| ...**möchte ich**... | ..., **so dass**... |
**Erfüllt, wenn**... | **Priorität** |
|:-----|:----------:|:-------------------|:-------------|:---------|:----------------|
| Lernen |Benutzer| bei Fehleingabe die Lösung angezeigt bekommen|ich lernen kann|
Lösung wird angezeigt | Muss |
# 3 Technische Beschreibung
## 3.1 Systemübersicht
* Systemarchitekturdiagramm ("Box-And-Arrow" Diagramm)
* Kommunikationsprotokolle, Datenformate
Das Diagramm in Kapitel "Systemübersicht" ist statisch und nicht dynamisch und stellt
daher keine Abläufe dar. Abläufe werden im Kapitel "Abläufe" dargestellt. Im Kapitel
"Systemübersicht" soll genau ein Diagramm dargstellt werden. Das "Box-and-Arrow"-Diagramm
soll als Systemarchitekturdiagramm eine abstrakte Übersicht über das Softwaresystem
geben. Dazu stellt es die Rechnerknoten und deren Kommunikationsbeziehungen (Protokoll
(z.B. HTTP), Datenformat (z.B. JSON)) dar. Also Rechtecke und gerichtete Pfeile. Ähnlich
einem UML-Deployment-Diagramm, aber noch abstrakter, denn es zeigt nicht die Verteilung
der Softwarebausteine auf die Rechnerknoten. So erlangt der Leser einen schnellen und
guten Überblick über das Softwaresystem.
## 3.2 Softwarearchitektur
* Darstellung von Softwarebausteinen (Module, Schichten, Komponenten)
Hier stellen Sie die Verteilung der Softwarebausteine auf die Rechnerknoten dar. Das ist
die Softwarearchitektur. Zum Beispiel Javascript-Software auf dem Client und Java-
Software auf dem Server. In der Regel wird die Software dabei sowohl auf dem Client als
auch auf dem Server in Schichten dargestellt.
* Server
* Web-Schicht
* Logik-Schicht
* Persistenz-Schicht
* Client
* View-Schicht
* Logik-Schicht
* Kommunikation-Schicht
Die Abhängigkeit ist bei diesen Schichten immer unidirektional von "oben" nach "unten".
Die Softwarearchitektur aus Kapitel "Softwarearchitektur" ist demnach detaillierter als
die Systemübersicht aus dem Kapitel "Systemübersicht". Die Schichten können entweder als
Ganzes als ein Softwarebaustein angesehen werden. In der Regel werden die Schichten aber
noch weiter detailliert und in Softwarebausteine aufgeteilt.
### 3.2.1 Technologieauswahl
Beschreiben Sie hier, welche Frameworks / Technologien / Bibliotheken / Datenformate /
Protokolle benutzt werden.
QT als Crossplattform Framework.
  - QT Quick mit QML da vorrangig das Smartphone genutzt werden soll
  - Direkter vergleich von MAUI einem .NET Frameork, primär für Mobile Anwendung zeigten, QT ist perfomanter.
  - [Openrouteservice]([https://link-url-here.org](https://openrouteservice.org/) Hilft beim erstellen von Routen  
  - [OpenstreetMap](https://www.openstreetmap.de/) Darstellen von der Karte
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
## 3.7 Fehlerbehandlung
* Mögliche Fehler / Exceptions auflisten
* Fehlercodes / IDs sind hilfreich
* Nicht nur Fehler technischer Art ("Datenbankserver nicht erreichbar") definieren,
sondern auch im Hinblick auf
Kapitel 3.8 sind fachliche Fehler wie "Kunde nicht gefunden". "Nachricht wurde bereits
gelöscht" o.ä.
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
* Verwendete Technologien (Programmiersprache, Frameworks, etc.)
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
### Rollen
Überlegen Sie, ob es sinnvoll ist, wenn Sie die Rollen für
Product-Owner und Scrum-Master vergeben, wobei Sie bedenken
sollten, ob diese Rollen über den gesamten Projektzeitraum
aktiv sein werden. Neben diesen Rollen können folgende Rollen
sinnvoll sein:
#### Softwarearchitekt
Entwirft den Aufbau von Softwaresystemen und trifft Entscheidungen über das Zusammenspiel
der Softwarebausteine.
#### Frontend-Entwickler
Entwickelt graphische oder andere Benutzerschnittstellen, insbesondere das Layout einer
Anwendung.
#### Backend-Entwickler
Implementiert die funktionale Logik der Anwendung. Hierbei werden zudem diverse
Datenquellen und externe Dienste integriert und für die Anwendung bereitgestellt.
#### DevOps-Engineer
Ist für die Repositories und das Deployment verantwortlich.
### Rollenzuordnung
| Name | Rolle |
|----------|-----------|
| Thomas Mustermann | Frontend-Entwickler |
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
