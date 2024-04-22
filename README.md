
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
#### Übersicht
![Mockup mit Graph](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/RouteGuideMockups.png)
#### Login
![Login](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/LoginScreen.png)
Use Cases: 1, 2, 3
#### Map
![Map](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/Map.png)
Use Cases: 5, 6, 7, 8
#### Passwort vergessen
![Passwort Vergessen](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/ForgotPasswort.png)
Use Case: 1
#### Neuer Nutzer, erste Seite
![Neuer User 0](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/NewUser0.png)
#### Neuer Nutzer, zweite Seite
![Neuer User 1](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/NewUser1.png)
Use Case: 4
#### Route planen, erste Seite
![Plan a Route 0](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/PlanARoute0.png)
#### Route planen, zweite Seite
![Plan a Route 1](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/PlanARoute1.png)
Use Cases: 16, 17, 18, 19
#### Profil, erste Seite
![Profile 0](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/Profile0.png)
Use Case: 10, 11, 12, 13, 14
#### Profil, zweite Seite
![Profile 1](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/Profile1.png)
Use Cases: 15
#### Community
![Community](https://github.com/BTBlueTiger/RouteGuide/blob/main/GuiMockUps/Community.png)
Use Cases: 11, 14


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

| **Als** | **möchte ich** | **so dass** | **Akzeptanz** |
| :------ | :----- | :------ | :-------- |
| Wer | Was | Warum | Wann akzeptiert |
1. | Benutzer | einen Button für das zurücksetzen des Passwort | ich mir ein neues Passwort geben lassen kann | Passwort wird durch neues ersetzt |
2. | Benutzer | einen Button zum erstellen eines Profils | ich als neuer Nutzer ein neues Profil machen kann | Benutzer wird angelegt und beim Login erkannt |
3. | Backend  | keine Fehlerhaften Anfragen | bei fehlerhafter Mail keine Anfrage geschickt wird | Falsche Email wird nicht angenommen |

4. | Benutzer | den Grund für meine Anmeldung angeben | damit ich für mich passende Routen finde | User wird einer Gruppe zugeordnet |

5. | Benutzer | eine simple Kartenansicht | damit ich mich auf das wesentliche konzentrieren kann | Simple Karten Ansicht |
6. | Benutzer | bei einer Navigation eine sich mitbewegende Karte | damit ich immer genau weiß wo ich bin und lang will/muss | Mitbewegende Karte |
7. | System | standortfreigabe vom Nutzer | damit die Karte und die geteilten Routen in etwa zu dem User passen | Standort des Users bekommen |
8. | Benutzer | die Karte wieder auf den Nutzer zentrieren | damit man bei verschobener Karte sich wieder findet | Button der den Nutzer zentriert

9. | Benutzer | zwischen den Hauptanwendungen leicht hin und her wechseln können | damit die App nicht überfordert | Navigationsleiste mit wesentlichen Anwendungen |

10. | Benutzer | die Möglichkeit bereits gefasste Routen zu speichern | damit ich Routen wiederholen kann | Speichermöglichkeit für Routen |
11. | Benutzer | die Möglichkeit gespeicherte Routen mit anderen zu teilen | damit ich Routen von anderen ausprobieren kann und eigene teilen kann | Teil Möglichkeit von gespiecherten Routen |
12. | Benutzer | bereits gefasste Routen wieder entfernen kann | so das ich meine Routen auch wieder löschen kann | Gespeicherte und/oder geteilte Routen löschen |
13. | Benutzer | routen die ich geliked habe wiederfinden | ich mir gefallende Routen öfters aufrufen kann | Gelikede Routen in meinem Profil wiederfinden |
14. | System | routen sollen bewertet werden können | user gut bewertete Routen finden können | Ein User bestimmtes Bewertungssystem

15. | Benutzer | mein Profil und meine Gruppe wechseln | um auch Routen zu erhalten die der User zuerst als unrelevant ansah | Eine Seite im Profil mit Tick Boxen |

16. | Benutzer | eine Route bestehend aus vielen Stops erstellen | um eine Route mit Zwischenstops erstellen zu können | Route aus einer Liste von Routen erstellen |
17. | Benutzer | Punkte auf der Kart anklicken um sie in die Routenplanung aufzunehmen | unabhängig von Straßen auch andere Wegpunkte setzen kann | Map Ansicht mit der Möglichkeit für Wegpunkte |
18. | Benutzer | eine optimierte Route erstellen können | um aus mehreren Wegpunken eine Optimale Strecke zu erstellen | Erstellen einer optimierten Route mithilfe eines Buttons |
19. | Benutzer | eine Route erstellen die nicht optimiert ist | um eine Route auch so zu haben wie der Nutzer es wollte | Erstellen einer unoptimierten Route mithilfe eines Buttons |

x. | System | dauer der Route soll gespeichert werden | es eine Durschschnitt und Bestzeit gibt | Zeitmessung der Navigation |
x. | System | listen sollen intuitiv scrollbar sein | so das es im Prinzip unendlich lange Listen gibt | Scrollbare Listen |


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
  - [Openrouteservice](https://openrouteservice.org/) Hilft beim erstellen von Routen  
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
