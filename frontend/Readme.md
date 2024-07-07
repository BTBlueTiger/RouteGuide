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

## C++ Modul

Das C++ Modul soll beispielhaft für auch Qml allein dienen, da auf den Qml Aspekt im nächsten Kapitel eingegangen wird.

![alt text](https://github.com/BTBlueTiger/RouteGuide/blob/main/docs/diagrams/frontend/Cpp-Modul.png)

### Die Klasse
Die _einfache Klasse_ Klasse UserModel hat 3 relevante Methoden die getestet werden sollen.
Gerade weil sie die Schnittstelle zur Nutzerdatenbank haben soll.
Diese C++ Klasse wird gewöhnlich implementiert, mit etwas Qt eigenen Eigenschaften, so wie wir es für die Anwendung brauchen.

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

```

Jede zu testete Methode wird so aufgebaut.

##### Macro

```C++
// Das Makro sorgt dafür das eine automatische Testklasse erstellt wird
QTEST_MAIN(TestUserModel)
// Das .moc ist die generierte Klasse
#include "test_usermodel.moc"
```

Das Makro ist eigentlich eine simple main() die alle test funktionen durchläuft.

Ein Beispielhaftes CMake für das Cpp Modul sehe so aus:
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


## QML C++ Mixed Modul

Es soll hier auch das zuvor benutzte form.ui.qml + qml erklärt werden sowie die Bausteine sowie einige des Grundlegenden Qt Framework.
Aber nur angerissen da es sonst zuviel werden würde.
Damit sind bestimmte MACROS die das gleiche bewirken könnten aber anders aufgeschrieben werden.

![alt text](https://github.com/BTBlueTiger/RouteGuide/blob/main/docs/diagrams/frontend/QML-Modul.png)

### Die Model Klasse für die Gui
Unser Gui besitzt ein Model das in Cpp geschrieben wird. Dadurch besitzen wir die Logik auf der Cpp Seite.
Wenn auch gleich ein paar Funktionen in einer qml landen können und dürfen.

##### .h des Models
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

Wir erstellen hier Propertys die von qml Dateien sichtbar sein sollen, hier als Beispiel das Property state.
Man könnte auch mit einem für außen sichtbaren Enum arbeiten.

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
Wir definieren getter, setter und die Signal Methode um das Property Beobachten zu können,
in der .cpp können wir sie ganz normal deklarieren.

Jetzt kommt ein schlauer Clou:

```C++
void ValidationTextfieldModel::setState(const int state)
{
    if(m_state == state)
        return;
    m_state = state;
    emit stateChanged(); <--- senden
}
```
Wenn der state sich durch einen Schreibzugriff ändert, dann senden wir das Signal.

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
Durch das verbinden von dem Signal zu einem Slot werden jetzt alle verbundenen Slots aufgerufen

```C++
void ValidationTextfieldModel::changeColorOnStateChanged()
{
    m_color = getNewColor();
    emit colorChanged(m_color);
}
```
Diese senden nach ändern ihrer Variable wieder Signale, beispielsweise mit der neuen Farbe.
Und das auch an unser QML in der ViewSchicht

```QML
    // Unsere propertys aus dem Model
    property alias m_color : model.color
  ...
```

Dort haben wir zugriff auf die Daten im C++ Model. In der QML Datei.
Und das delegiert es wieder an das ui.qml unser wirklichen Viewschicht in der Funktionen nichts zu suchen haben.

```QML
    background: Rectangle {
        color: m_color
    ...
    }
```

Diese Komponente können wir jetzt nach belieben einbauen.

```QML
      ValidationTextfield {
          placeholderText: qsTr("UserName")
        ....
      }
```

Einmal als Gui Komponente in der .ui.qml

```QML
      property alias userName : textfieldUserName
      ValidationTextfield {
          id: textfieldUserName
          placeholderText: qsTr("UserName")
        ....
      }
```

und einmal in der .qml Componente um die Daten zu delegieren:
```QML
      userName.onTextChanged: {
      // Verwalten der Variable um beim wechseln von klein auf großen Screen oder anders rum die Variable nicht einfach verloren geht
          registerPage.userName = userName.text
      // Setzen des States
          userName.state = username_state
      }
```

### Resultat

Nun haben wir ein Modul das selbst gebaut und auch allein getestet werden kann.
Zudem können wir es jetzt als Componente in unsere Anwednung einbauen

### Testen von Gui Elementen

Im Prinzip gibt es wieder ein Setup in cpp dateien. Sie laden QML Elemente und setzen die Gui auf.
```QML

TestCase {

    ValidationTextfield{
        id: field
        errorMsg: "Error"
        placeholderDefault: "Default"
    }

    function test_initialState() {
        verify(field.state === ValidationTextfield.ValidationState.Default)
        verify(field.errorMsg === "Error")
        verify(field.placeholderDefault === "Default")
    }

}

```
Mit Cmake, das hier größer wäre baut die Datei dann und läuft durch 
Entweder mit Console, Skribt oder dem Editor von QT
```
Config: Using QtTest library 6.7.2, Qt 6.7.2 (x86_64-little_endian-lp64 shared (dynamic) release build; by GCC 10.3.1 20210422 (Red Hat 10.3.1-1)), ubuntu 22.04
PASS   : TestUserModel::initTestCase()
PASS   : TestUserModel::test_LoginAttempt()
PASS   : TestUserModel::test_LogoutAttempt()
FAIL!  : TestUserModel::test_registerAttempt() Compared values are not the same
   Actual   (registerSuccess()): 0
   Expected (true)             : 1
   Loc: [/home/kamalte/Desktop/ToDelete/RouteGuide/frontend/modules/Models/UserModel/test_usermodel.cpp(40)]
PASS   : TestUserModel::cleanupTestCase()
Totals: 4 passed, 1 failed, 0 skipped, 0 blacklisted, 1ms
```


##### Vorteil:
- Wir haben unser Modul entkoppelt, können es einfacher testen und es ist einfacher mit ihm allein zu arbeiten.
- Wir sehen wo ein Modul von anderen Modulen abhängig ist und können Kopplungen leichter reduzieren.
- Zum Teil wird es übersichtlicher, da jedes Modul wie ein eigenes _CMake_ Projekt funktioniert, und wir sie nur noch als Modul/Lib hinzufügen müssen.
- Entkoppelte Projekte Können einfach in jedem Programm wieder verwendet werden

##### Nachteil
- Für jedes dieser Module müssen wir viel Boilerplate code schreiben.
- Es dauert einfach viel länger


