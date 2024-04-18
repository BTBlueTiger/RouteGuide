# RouteGuide - Die App für einfache Routenerstellung und mehr

## RouteGuide soll eine Anwendung sein, die ursprünglich für Zusteller gedacht war um einfache Routen mit mehreren Zwischenstopps zu planen. 

Anders als bei bekannten Diensten ist es nicht benutzerfreundlich, eine Route mit mehreren Zwischenstopps zu planen. 
Im Laufe der Ideenfindung wurde auch um die Erweiterung für anderen Gruppen wie Touristen, Sportlern und Wanderern erwogen.
So soll der Routeguide erstmals nur mithilfe von Straßen und Straßennummern eine praktische Route erstellen können, später aber auch für Touristen, die Sehenswürdigkeiten einplanen, Sportler, die neue Strecke ausprobieren oder Wanderer, die neue Wege erforschen wollen, interessant sein.

## Interne Datenbank
Unsere Datenbank soll viele Straßen kennen, damit dem User durch Autovervollständigung Arbeit und Frust abgenommen werden kann.
Aber sie soll auch favorisierte Routen und auch veröffentlichte Routen für andere User in der gleichen Usergruppe beinhalten.
Sodass eine Community immer mehr Zugriff auf Routen erhält.

Es soll möglich sein, diese zu filtern, beispielsweise nach Länge oder Dauer, oder später mit einem etwaigen Bewertungssystem.
Routen, die zu oft negativ bewertet wurden, sollen auch herausfallen, oder Routen, die zu lange "unbenutzt" waren.

Für Sportler oder Wanderer ist ein Feature angedacht, womit sich User vergleichen können, seien es Bestzeiten oder Durchschnittszeiten.
Diese Zeiten sollen später aber wahrscheinlich nicht manuell dokumentiert werden können.

##### Berufszweige mit Zwischenstops
Hier soll es interne Gruppen geben, die normale User nicht sehen können.
Nur authentifizierte User sollen die Möglichkeit haben, diese Routen und auch die Strecken darin zu betrachten.
Aus bestimmten Bezirken könnten diese sich so immer ihre Route erstellen.
Neben Zustellern könnten das lokale Spediteure, Busfahrer oder Ähnliches sein.

## Was wird benötigt
Ein Interface, mit dem der User kommunizieren kann und die Datenbank, um diese Dinge zu speichern.
Außerdem muss die API zwischendrin User authentifizieren können. Besonders bei den beruflich Nutzenden wichtig.

##### Die Google API
Um dies zu realisieren ist es besonders wichtig eine Datenquelle für die Kartendaten zu besitzen.
Die Google-API bietet sich hier an. Der User soll seine Route gewohnt über Google Maps sehen und die Navigation hierüber zu benutzen, mit ein paar Features.
Zudem soll es dem User nachher gestattet sein, mithilfe von gesetzten Punkten auf der Karte eine Route zu erstellen, wo sich dieser Dienst sehr gut anbietet.
