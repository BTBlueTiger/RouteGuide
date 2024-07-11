#include "test_usermodel.h"
#include "qjsonvalue.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

QString GetRandomString(int length)
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = length; // assuming you want random strings of 12 characters

    srand (time(NULL));

    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {

        QChar nextChar = possibleCharacters.at(rand() % possibleCharacters.length());
        randomString.append(nextChar);
    }
    return randomString;
}



void TestUserModel::test_LoginAttempt()
{
    QVariantMap map;
    map["username"] = "mmm";
    map["password"] = "test";
    loginAttempt(map);
    QCOMPARE(loggedIn(), false);
}



void TestUserModel::test_registerAttempt()
{
    QVariantMap map;
    QString username = GetRandomString(5);
    QString email = GetRandomString(5);
    email.append("@test.de");
    QString password = GetRandomString(5);
    map["username"] = username;
    map["email"] = email;
    map["password"] = password;
    QVariantMap group;
    group["id"] = 1;
    map["group"] = group;
    registerAttempt(map);
    // QCOMPARE testet ob der Fall war ist
    qDebug() << map;
    QCOMPARE(registerSuccess(), true);
    map.remove("email");
    // Der Login sollte nun mit den Daten aus der Registrierung
    //funktionieren wenn die Registrierung erfolgreich war
    loginAttempt(map);
    QCOMPARE(loggedIn(), true);
}

void TestUserModel::test_LogoutAttempt()
{
    logoutAttempt();
}

QTEST_MAIN(TestUserModel)
#include "test_usermodel.moc"
