#include "include/models/UserModel.h"

#include <QDebug>

#define WITHOUT_DATABASE true
#define WITHOUT_LOGIN_VERIFICATION true

UserModel::UserModel(QObject *parent)  {
    companyMailAdresses.push_back("mydphdl");
}

int UserModel::onEmailTypeRequestet()
{
    return m_emailType;
}

bool UserModel::onPasswordEntered(const QString& text)
{
    m_password = text;
    return true;
}

bool UserModel::onSecondPasswordEntered(const QString &str)
{
    if(str == m_password)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int UserModel::onEmailAdressEntered(const QString &str)
{
    QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailREX.setCaseSensitivity(Qt::CaseInsensitive);
    mailREX.setPatternSyntax(QRegExp::RegExp);
    if(mailREX.exactMatch(str))
    {
        QStringList splittedString(str.split("@"));
        QStringList endPart(splittedString[1].split("."));
        m_emailType = emailToEmailType(endPart[0]);
        return m_emailType;
    }
    else
    {
        m_emailType = 0;
        return m_emailType;
    }
}

void UserModel::addOrRemoveGroup(const Group& group)
{
    int index = m_groupsSelected.indexOf(group);
    if (index != -1)
    {
        m_groupsSelected.removeAt(index);
    }
    else
    {
        m_groupsSelected.append(group);
    }
}


void UserModel::onGroupSelect(const int &group)
{
    switch (group) {
    case 0:
        addOrRemoveGroup(Group::Hiker);
        break;
    case 1 :
        addOrRemoveGroup(Group::Sportler);
        break;
    case 2 :
        addOrRemoveGroup(Group::Tourist);
        break;
    case 3 :
        addOrRemoveGroup(Group::Company);
        break;
    default:
        break;
    }
}

int UserModel::emailToEmailType(const QString& email) {
    auto it = std::find_if(companyMailAdresses.begin(), companyMailAdresses.end(), [&email](const QString& address) {
        return address == email;
    });

    if (it != nullptr) {
        m_emailType = 2;
        return 2;
    }
    else
    {
        m_emailType = 1;
        return 1;
    }
}

void UserModel::onLoginAttempt(const QString &email, const QString &password)
{
    if(WITHOUT_DATABASE) {
        m_email = email;
        m_emailType = emailToEmailType(m_email[0]);
        emit loginAttemptSuccess(m_emailType);
        return;
    }
    else {

    }
}

void UserModel::onRegisterAttempt(
    const QString &email,
    const QString &passwort,
    const QString &reenteredPassword
    )
{

}
