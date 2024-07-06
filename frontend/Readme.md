# Erfahrung mit der QT Umgebung.

## Das Build-System
### Positiv:
- Funktioniert mit GCC, mit einem Host-Compiler für Android und MSCV für Windows sobald eingerichtet Kinderleicht
- Es ist schnell für Desktop Pcs
### Negativ
- Android hat eine lange Build-Time und kann zu Anfang Probleme bereiten
- Es ist nicht immer einfach echte Objekte zu bauen

## Die Nutzeroberfläche der erstellten Anwendung und das erstellen dieser
### Positiv:
- Meiner Meinung nach sehr hübsch
### Neutral
- Das Qml Framework ist mittels Javascript einfach zu benutzen, sobald verstanden.
- Das QT es so vorgesehen hat eine Form.ui.qml zu haben in der nur die Benutzeroberfäche beschrieben wird und
Funktionen in der ähnlich bennanten .qml Datei hat es die ersten Dateien ein wenig Spaghetti Mäßig aufgblasen.
### Negativ:
- Zu Anfang gehofft mit dem Creator zu arbeiten funktionierte aber nicht, wahrscheinlich wäre es dann mit dem Form.ui.qml System eher
und besser aufgefallen.

## Das C++ System als Logische Verstärkung
### Positiv:
- Die Perrformance ist einfach spürbar
- C++ ist zwar sehr verbose aber auch aufgeräumt
### Neutral
- CMakeLists.txt ist nicht das einfachste Build System und auch sehr verbose und aufgeräumt, eventuell kommt daher meine Subjektive Meinung

## Qt als QT
### Positiv:
- Es ist quasi alles bereits vorhanden was benötigt wird.
- Es ist ein C++/Javascript Gigant für wunderschöne Oberflächen.
- Es gibt auch eine kostenlose OpenSoft-Lösung für Private Anwender.
### Negativ:
- Es ist oft nicht einfach das zu bekommen was man will
- Es ist kein "kostenloses" Framework an sich, was das Suchen von Lösungen sehr schwer macht(kleine Community im Vergleich zu React).

### Abschließendes Fazit
Qt ist an sich ein super Framework, bedarf aber oft viel suchen da die Docu nicht immer die beste war und es auf Stack nicht oft Hilfe
zu finden schien.

Ich werde dieses System in Zukunft wahrscheinlich nutzen, 
aber eher in einem Betrieb als das ich das für ein Privates Projekt aussuchen würde.
Dafür muss man zuviel Arbeit investieren um ein Resultat zu erzeugen.
Aber genau deswegen fand ich es super in so einem Projekt nutzen zu können und es hat mir viel gelehrt.

# Beschreibung von QT mit QML 
Für jede Komponente die wir auch testen wollen und die wir vom ganzen "abkapseln" wollen erstellen wir ein Modul.
Ein Modul kann ein reines C++-Modul, ein QML Modul oder eine Mischung aus beidem sein.
Man testet ein QML Modul mit QTQuick in einer qml File. Ein reines C++ Modul mit QTest.

### C++ Modul

![alt text](http://url/to/img.png)

### QML Modul

![alt text](http://url/to/img.png)
