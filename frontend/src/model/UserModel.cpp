#include "include/model/UserModel.h"

#define WITHOUT_DATABASE false


void UserModel::onFieldEntered(const QString& text, const QString &id)
{

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
            return 2;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
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
        m_firstName = "Max";
        m_lastName = "Muster";
        emit onLoginAttemptSuccess();
        return;
    }
    else {

    }
}

void UserModel::onRegisterAttempt(
    const QString &firstName,
    const QString &lastName,
    const QString &email,
    const QString &passwort,
    const QString &reenteredPassword
    )
{

}
