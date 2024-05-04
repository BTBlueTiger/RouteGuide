#include "include/model/UserModel.h"

#define WITHOUT_DATABASE false

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
    qDebug() << str << m_password;
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
        if(endPart[0] == "mydphdl")
        {
            m_emailType = 2;
            return m_emailType;
        }
        else
        {
            m_emailType = 1;
            return m_emailType;
        }
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

void UserModel::onLoginAttempt(const QString &email, const QString &password)
{
    if(WITHOUT_DATABASE) {
        m_email = email;
        emit onLoginAttemptSuccess();
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
