#include "include/models/UserModel.h"
#include "include/Constants.h"

#include <QtNetwork/qhttpheaders.h>
#include <QtNetwork/qrestaccessmanager.h>
#include <QtNetwork/qrestreply.h>

#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>

#define WRONG_LOGIN true
#define IS_COMPANY false

UserModel *UserModel::m_instance = nullptr;

UserModel::UserModel(QObject *parent)
    : AbstractResource(parent)
{
    m_companyMailAdresses.push_back("mydphdl");
    m_companyMailAdresses.push_back("scorp");

    url->setScheme("http");
    url->setHost("94.16.31.72");
    url->setPort(8080);
    m_api->setBaseUrl(*url);
    headers->append("Content-Type", "application/json");
    m_api->setCommonHeaders(*headers);
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

bool UserModel::registerSuccess() const
{
    return m_registerSuccess;
}

void UserModel::loginAttempt(const QVariantMap& data)
{
    if(WITH_API)
    {
        QNetworkReply* response = postRequest(
            *qVariantMapToQByteArray(data),
            m_api->createRequest("/auth/login")
            );

        QObject::connect(response, &QNetworkReply::finished, [=](){
            if(response->error() == QNetworkReply::NoError)
            {

                m_api->setBearerToken(response->readAll());
                qDebug()<< response->readAll();
                QNetworkReply * secondResponse = getRequest(m_api->createRequest("/users/me"));

                QObject::connect(secondResponse, &QNetworkReply::finished, this, [=]()
                {
                    QByteArray jsonData = secondResponse->readAll();
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
                    QJsonObject jsonObj = jsonDoc.object();
                    m_user =
                    {
                        jsonObj["email"].toString(),
                        jsonObj["username"].toString()
                    };
                    qDebug() << jsonObj["email"];
                    qDebug() << jsonObj["company"];
                    if(jsonObj["company"].isNull())
                    {
                        m_user->emailT = EMAIL_T::COMPANY;
                    }
                    else
                    {
                        m_user->emailT = EMAIL_T::PRIVATE;
                    }
                    qDebug() << jsonObj;
                    emit userChanged();
                });
            } else {
                m_user.reset();
                emit userChanged();
            }
        });
    } else {
        m_user.reset();
        m_user = User
            {
                data["email"].toString(),
                "Dummy",
                emailType("kamalte@web.de"),
            };
        qDebug() << m_user->emailT;
        emit userChanged();

    }
}


void UserModel::logoutAttempt()
{

}

UserModel::EMAIL_T UserModel::emailType(const QString& email)
{
        QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
        mailREX.setCaseSensitivity(Qt::CaseInsensitive);
        mailREX.setPatternSyntax(QRegExp::RegExp);
        if(mailREX.exactMatch(email)) {
            QStringList splittedString(email.split("@"));
            QStringList endPart(splittedString[1].split("."));
            QVector<QString>::iterator it = std::find(m_companyMailAdresses.begin(), m_companyMailAdresses.end(), endPart[0]);
            return it != m_companyMailAdresses.end()
                       ? EMAIL_T::COMPANY : EMAIL_T::PRIVATE;
        }
        return EMAIL_T::ERROR;
}

void UserModel::changePremiumGroup(int group)
{
    int wasInserted = -1;
    if(premiumGroups.size() > 0)
    {
        for(int i = 0; i < premiumGroups.size(); i++)
        {
            if(premiumGroups.at(i) == group)
            {
                wasInserted = i;
            }
        }
    }
    if(wasInserted)
    {
        premiumGroups.removeAt(wasInserted);
    }
    else
    {
        premiumGroups.append(group);
    }
    emit premiumGroupsChanged(premiumGroups);
}


void UserModel::registerAttempt(const QVariantMap& data)
{
    QNetworkReply* response = postRequest(
        *qVariantMapToQByteArray(data),
        m_api->createRequest("/auth/register")
        );
    QObject::connect(response, &QNetworkReply::finished, [=](){
        if(response->error() == QNetworkReply::NoError)
        {
            m_registerSuccess = true;
            emit registerSuccessChanged();
        }
        else
        {
            m_registerSuccess = false;
            emit registerSuccessChanged();
        }
    });
}

int UserModel::email_t() const
{
    return m_email_t;
}

void UserModel::setEmail_t(int type)
{
    if(type == m_email_t)
        return;
    m_email_t = type;
    emit email_tChanged(m_email_t);
}
