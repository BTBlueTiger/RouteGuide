# Erfahrung mit Github Action
### Positiv:
- Kostenfrei in public Repos
- Viele Plugins
- Konsolen Programm like

### Negativ:
- nicht "kostenlos"
- Ohne Caching kann es ewig dauern
- ob ein Build erfolgreich war sagt nicht immer was aus


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
- Testbare Komponenten sollten als Lib geschrieben werden, dies macht sie zu eigenständigen Projekten was die größte Entkoppelung bietet
- Ein Modul kann ein reines C++-Modul, ein QML Modul oder eine Mischung aus beidem sein.

## C++ Modul

- **Ein reines C++ kann als Modul auch ohne Gui dienen wenn es nur logische Aspekte betrachtet**

![alt text](https://github.com/BTBlueTiger/RouteGuide/blob/main/docs/diagrams/frontend/Cpp-Modul.png)

### Die Klasse
- Die _einfache Klasse_ Klasse UserModel hat 3 relevante Methoden die getestet werden sollen können.

### Die Testklasse
[Refer to QTs Tutorial](https://doc.qt.io/qt-6/qttestlib-tutorial1-example.html)

Leitet von der C++ Klasse ab die getestet werden soll.

##### .h
```C++
#ifndef TEST_USERMODEL_H
#define TEST_USERMODEL_H

#include "UserModel.h"
#include <QTest>

class TestUserModel: public UserModel
{
    Q_OBJECT

private slots:
    void test_LoginAttempt();
    void test_LogoutAttempt();
    void test_registerAttempt();

};
```
- UserModel beinhaltet öberflächliche drei wichtige Funktionen die getestet werden müssen
    - login
    - logout
    - register      

##### .cpp

```C++
#include "test_usermodel.h"
void TestUserModel::test_registerAttempt()
{
    QVariantMap map;
    QString username = GetRandomString(5);
    ...
    // QCOMPARE testet ob der Fall war ist
    QCOMPARE(registerSuccess(), true);
    // Der Login sollte nun mit den Daten aus der Registrierung funktionieren wenn die Registrierung erfolgreich war
    loginAttempt(map);
    QCOMPARE(loggedIn(), true);
}
... Am Ende: 

// Das Makro sorgt dafür das eine automatische Testklasse erstellt wird
QTEST_MAIN(TestUserModel)
// Das .moc ist die generierte Klasse
#include "test_usermodel.moc"

```

- Jede zu testende Methode erhält die standard Inputs
- Funktionen wie `QCOMPARE(loggedIn(), true);` validieren sie
- Das Makro steht am Ende, eine simple main() die alle test funktionen durchläuft.


##### Beispielhaftes CMake für das UserModel

```CMake
cmake_minimum_required(VERSION 3.16)

# Das Projekt an sich

project(UserModel VERSION 0.1 LANGUAGES CXX)

# Such die benötigten Componenten

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Qml)
find_package(Qt6 REQUIRED COMPONENTS Qml)

# Erstelle das Modul/Library das später zum Hauptprojekt hinzugefügt werden soll

add_library(UserModel STATIC
    UserModel.cpp UserModel.h

)

# Linke die benötigten libs

target_link_libraries(UserModel PRIVATE
    Qt6::Qml
    AbstractRessource
)

### Test Projekt ####

# Aktieviere das testen

enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Test Widgets)

# Setze das das Testprojekt auf

qt_standard_project_setup()

qt_add_executable(test_userModel
    test_usermodel.cpp
    test_usermodel.h
)

# linke die libs

target_link_libraries(test_userModel PRIVATE
    Qt6::Core
    Qt6::Qml
    Qt6::Test
    UserModel
)


# boilerplate installation

set_target_properties(test_userModel PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

install(TARGETS test_userModel
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

```

#### Nutzen in der View-Schicht als Model
- Das erstellte Model wird als Singleton verfügbargemacht
- Die Methode "createSingletonInstance" ist Boilerplate in der Klasse

```C++
    qmlRegisterSingletonType<UserModel>("UserModel", 1, 0, "UserModel", UserModel::createSingletonInstance);
```

- Nun Nutzbar in der Kompletten App

```QML

import UserModel

    btnLogin.onClicked: {
        UserModel.loginAttempt
        (
            {
                ["username"] : userName.text,
                ["password"] : userPassword.text
            }
        )
    }

    Connections{
        target: UserModel
        function onUserChanged() {
            if(!UserModel.loggedIn) {
                wrongCredentialsToolTip.visible = true
            }
        }
    }
```

- Funktionen nun global wie Javascript anzuwenden
- Connection verbinden Signal und Slots in QML und C++


## QML C++ Mixed Modul Beispiel an ValidationTextfield

- kurze grundlegene Erklärung zum Framework
    - Propertys
    - Signal and Slot
    - Erklärung zu form.ui.qml und qml
      

- ausgelassen werden
    - MACROS die Ähnliches bewirken
    - bestimmte Funktionen die das selbe bewirken
    - Jegliche Funktion die noch nicht bekannt
 

![alt text](https://github.com/BTBlueTiger/RouteGuide/blob/main/docs/diagrams/frontend/QML-Modul.png)

### Die Model Klasse für die Gui
- **Model** in C++ geschrieben
- **Delegate** in .qml geschrieben
    - Kann Funktionen
    - Könnte auch Gui sollte es aber nicht    
- **View** in ui.qml geschrieben
    - Kann keine Funktionen aufnehmen
    - vorstellbar wie html    

![Model View architecture in QT](https://doc.qt.io/qt-6/images/modelview-overview.png)

##### Q_PROPERTY

```C++
// Wir erben von der Base Klasse QObject
class ValidationTextfieldModel : public QObject
{
    Q_OBJECT
    // Propertys sind von Qml Dateien boabactbar und können mit 
    // 1.               Typ Deklaration
    // 2. READ      -   Read Methode
    // 3. WRITE     -   Setter Methode
    // 4. NOTIFY    -   Signal zum qml element oder einer klasse, quasi der Sender
    Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)
    // Unser Model ist quasie ein QML Element
    QML_ELEMENT

```

- Propertys sind die Verbindungen von C++ zu QML

```C++
...
public:
...
  // Der nach außen sichtbare State des Q_PROPERTY
  // 2. READ      -   Read Methode
  int state() const;
...
  // Der nach außen sichtbare State, kann also auch von einer qml verändert werden.
  // 3. WRITE     -   Setter Methode
  void setState(const int state);
private:
    // Unser privater state des states
    // 1.               Typ Deklaration
    int m_state;
signals:
    void stateChanged();
    // Das Signal der mit anderen Componenten reagiert
    // Ein Quasi Observer Pattern
    // 4. NOTIFY    -   Signal zum qml element mit einem String
    void borderColorChanged(QString);

    //Slots sind quasi Empfänger von Signalen im cpp context
private slots:
    void changeBorderColorOnStateChanged();
    void changeColorOnStateChanged();
    void changeOpacityOnStateChanged();
```
- Definieren getter, setter, signal und slots
- Signal and Slot ist wie ein ObservablePattern 

#### SIGNAL
- ändert sich ein zustand, wie durch ein WRITE/set lässt sich das signalisieren
    - setState ändert das model
    - neuer Status wird gesetzt
    - keywoard emit sendet das Signal

```C++
void ValidationTextfieldModel::setState(const int state)
{
    if(m_state == state)
        return;
    m_state = state;
    emit stateChanged(); <--- senden
}
```
#### SLOT

- slot ist eine art Listener function
- wird ein slot an eine function gebunden hört sie auf das emit keywoard
- es braucht im Grunde Parameter
    - Signalisierende Klasse
    - Signalisierende Funktion
    - Zuhörende Klasse
    - Zuhörende Funktion

```C++
ValidationTextfieldModel::ValidationTextfieldModel(QObject* parent) : QObject(parent)
{
    // Wir brauchen einen Sender, das ist in diesem Fall diese Klasse this
    // Wir brauchen eine Funktion die Sendet, also ein SIGNAL das ist stateChanged
    // Wir braucehn einen Empfänger, wieder wir thist
    // Wir brauchen einen SLOT der das Signal annimt
    
    // Mit dieser Syntax nehmen wir statische Methoden
    connect(this, &ValidationTextfieldModel::stateChanged, this, &ValidationTextfieldModel::changeBorderColorOnStateChanged);
    
    // Mit dieser Syntax könnten wir zum Beispiel auch Parameter weitergeben
    connect(this, SIGNAL(stateChanged()), this, SLOT(changeColorOnStateChanged()));
    connect(this, SIGNAL(stateChanged()), this, SLOT(changeOpacityOnStateChanged()));
}
```
#### Model View Verkettung 

- property alias gibt leichten Zugriff von **View** auf **Delegate**
- 
```QML
      property alias userName : textfieldUserName
      ValidationTextfield {
          id: textfieldUserName
          placeholderText: qsTr("UserName")
        ....
      }
```

- username alias im **Delegate** für Funktionen Verfügbar
- User editiert text im **Delegate**
- onTextChanged emitiert das **Signal**
- State verändert sich durch eine bestimmte Vorraussetzung
```QML
      userName.onTextChanged: {
      // Verwalten der Variable um beim wechseln von klein auf großen Screen oder anders rum die Variable nicht einfach verloren geht
          registerPage.userName = userName.text
      // Setzen des States
          userName.state = username_state
      }
```
- Slot wird aktiviert da sich state ändert

```C++
void ValidationTextfieldModel::changeColorOnStateChanged()
{
    m_color = getNewColor();
    emit colorChanged(m_color);
}
```
- Farbe wird durch **Delegate** aufgenommen
```QML
    // Unsere propertys aus dem Model
    property alias m_color : model.color
  ...
```
- Farbe wird an **View** weitergegeben 
```QML
    background: Rectangle {
        color: m_color
    ...
    }
```


### Resultat

Nun haben wir ein Modul das selbst gebaut und auch allein getestet werden kann.
Zudem können wir es jetzt als Componente in unsere Anwednung einbauen




##### Vorteil:
- Wir haben unser Modul entkoppelt, können es einfacher testen und es ist einfacher mit ihm allein zu arbeiten.
- Wir sehen wo ein Modul von anderen Modulen abhängig ist und können Kopplungen leichter reduzieren.
- Zum Teil wird es übersichtlicher, da jedes Modul wie ein eigenes _CMake_ Projekt funktioniert, und wir sie nur noch als Modul/Lib hinzufügen müssen.
- Entkoppelte Projekte Können einfach in jedem Programm wieder verwendet werden

##### Nachteil
- Für jedes dieser Module müssen wir viel Boilerplate code schreiben.
- Es dauert einfach viel länger


