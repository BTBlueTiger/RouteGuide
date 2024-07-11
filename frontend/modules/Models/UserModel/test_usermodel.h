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


#endif // TEST_USERMODEL_H
