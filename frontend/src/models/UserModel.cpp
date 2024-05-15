#include "include/models/UserModel.h"
#include "include/Constants.h"

#include <QtNetwork/qhttpheaders.h>
#include <QtNetwork/qrestaccessmanager.h>
#include <QtNetwork/qrestreply.h>

#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>

#define WRONG_LOGIN true

UserModel *UserModel::m_instance = nullptr;

UserModel::UserModel(QObject *parent)
    : AbstractResource(parent)
{
    m_companyMailAdresses.push_back("mydphdl");
}

QObject* UserModel::createSingletonInstance(QQmlEngine *engine, QJSEngine *scriptEngine){
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    if(m_instance==nullptr) { m_instance = new UserModel;}
    return m_instance;
}

QString UserModel::user() const
{
    return m_user ? m_user->email : QString();
}

bool UserModel::loggedIn() const
{
    return m_user.has_value();
}

void UserModel::loginAttempt(const QVariantMap& data)
{
    if(WITH_LOGIN_API) {
        QString loginPath =
            QString(API_PATH) + "login_dummy";

        m_manager->post(m_api->createRequest(loginPath), data, this, [this,  data] (QRestReply &reply){
            m_user.reset();
            if(const auto json = reply.readJson();
            json && json->isObject() && json->object().contains("token"))
            {
                m_user = User{
                    data.value("id").toInt(),
                    data.value("email").toString(),
                    data.value("user_name").toString(),
                    emailType("Dummy@web.de"),
                    (*json)["tokenField"].toVariant().toByteArray(),
                };
            }
            QHttpHeaders headers;
            headers.append("token", m_user ? m_user->token : "");
            m_api->setCommonHeaders(headers);
            emit userChanged();
        });
    }
    else if(WRONG_LOGIN)
    {
        m_user.reset();
        emit userChanged();
    }
    else
    {
        m_user.reset();
        m_user = User
        {
            0,
            data["email"].toString(),
            "Dummy",
            emailType(data["email"].toString()),
            "Dummy"
        };
        emit userChanged();
    }

}

void UserModel::logoutAttempt()
{

}

UserModel::EMAIL_T UserModel::emailType(const QString& email)
{
    if(WITH_VALIDATION_TEXTFIELD) {
        QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
        mailREX.setCaseSensitivity(Qt::CaseInsensitive);
        mailREX.setPatternSyntax(QRegExp::RegExp);
        if(mailREX.exactMatch(email)) {
            qDebug() << "valid";
            QStringList splittedString(email.split("@"));
            QStringList endPart(splittedString[1].split("."));
            QVector<QString>::iterator it = std::find(m_companyMailAdresses.begin(), m_companyMailAdresses.end(), endPart[0]);
            return it != m_companyMailAdresses.end()
                       ? EMAIL_T::COMPANY : EMAIL_T::PRIVATE;
        }
        return EMAIL_T::ERROR;
    }
    //Not with LOGIN API

    return EMAIL_T::COMPANY;
}
