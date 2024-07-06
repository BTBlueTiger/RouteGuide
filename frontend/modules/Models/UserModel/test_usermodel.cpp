#include "test_usermodel.h"

QString GetRandomString(int length)
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = length; // assuming you want random strings of 12 characters

    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {
        int index = rand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}

void TestUserModel::test_LoginAttempt()
{
    QVariantMap map;
    map["username"] = "TestUser";
    map["password"] = "TestUsersSecretPassword";
    loginAttempt(map);
    QCOMPARE(loggedIn(), false);
}



void TestUserModel::test_registerAttempt()
{
    QVariantMap map;
    QString username = GetRandomString(5);
    QString email = GetRandomString(5);
    QString password = GetRandomString(5);
    map["username"] = username;
    map["email"] = email;
    map["password"] = password;
    registerAttempt(map);
    QCOMPARE(registerSuccess(), true);
    map.remove("email");
    loginAttempt(map);
    QCOMPARE(loggedIn(), true);
}

void TestUserModel::test_LogoutAttempt()
{
    logoutAttempt();
}

QTEST_MAIN(TestUserModel)
#include "test_usermodel.moc"
