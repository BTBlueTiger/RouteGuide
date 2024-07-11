#include "UserModel.h"
//#include "include/Constants.h"

#include <QtNetwork/qhttpheaders.h>
#include <QtNetwork/qrestaccessmanager.h>
#include <QtNetwork/qrestreply.h>

#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>

#define WRONG_LOGIN true
#define IS_COMPANY false
#define WITH_API false

UserModel *UserModel::m_instance = nullptr;

UserModel::UserModel(QObject *parent)
    : AbstractRessource(parent)
{
    // Base url
    m_url->setScheme("http");
    m_url->setHost("94.16.31.72");
    m_url->setPort(8080);

    // setting to abstract ressource
    m_api->setBaseUrl(*m_url);

    // setting http headers
    m_headers->append("Content-Type", "application/json");
    m_api->setCommonHeaders(*m_headers);
}

QObject* UserModel::createSingletonInstance(QQmlEngine *engine, QJSEngine *scriptEngine){
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    if(m_instance==nullptr) { m_instance = new UserModel;}
    return m_instance;
}

QString UserModel::user() const
{
    return m_user ? m_user->userName : QString();
}

QString UserModel::group() const
{
    if(m_user.has_value())
    {
        switch (m_user.value().gr) {
        case HIKER:
            return "Hiker";
        case SPORTLER:
            return "Sportler";
        case TOURIST:
            return "Tourist";
        case P_COMPANY:
            return "Company";
        default:
            return "Error";
        }
    }
    return QString();
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
        // Nachricht  erstellen
        QNetworkReply* response = postRequest(
            *qVariantMapToQByteArray(data),
            m_api->createRequest("/auth/login")
            );
        // Verbinden von der angekommenen Nachricht
        QObject::connect(response, &QNetworkReply::finished, [=](){
            if(response->error() == QNetworkReply::NoError)
            {
                // Setzen vom Token wenn Nachricht ok
                m_api->setBearerToken(response->readAll());

                // Fragen nach UserDaten
                QNetworkReply * secondResponse = getRequest(m_api->createRequest("/users/me"));

                //Verbinden der des Users mit den mit den Daten aus dem Reply
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

                                     if(jsonObj["company"].isNull())
                                     {
                                         m_user->emailT = EMAIL_T::COMPANY;
                                     }
                                     else
                                     {
                                         m_user->emailT = EMAIL_T::PRIVATE;
                                     }


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
                PRIVATE,
                SPORTLER
            };
        emit userChanged();
    }
    // userChanged kommt in der QML an
    // Wenn der user keine Daten hat gilt er als nicht eingeloggt
    // Hat er Daten gilt er als eingeloggt
    // bool UserModel::loggedIn() const
}


void UserModel::logoutAttempt()
{
    m_user.reset();
    emit userChanged();
}

UserModel::EMAIL_T UserModel::emailType(const QString& email)
{
    QRegularExpression mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = mailREX.match(email);

    // Überprüfen der Richtigkeit der Email
    if (match.hasMatch()) {
        QStringList splittedString = email.split("@");
        if (splittedString.size() != 2) {
            return EMAIL_T::ERROR;
        }

        QStringList endPart = splittedString[1].split(".");
        if (endPart.isEmpty()) {
            return EMAIL_T::ERROR;
        }


        QVector<QString>::const_iterator it = std::find(m_companyMailAdresses.cbegin(), m_companyMailAdresses.cend(), endPart[0]);
        return it != m_companyMailAdresses.cend() ? EMAIL_T::PRIVATE : EMAIL_T::COMPANY ;
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

int UserModel::groupID() const
{
    return m_groupID;
}

void UserModel::setGroupID(int groupID)
{
    if(m_groupID != groupID)
        m_groupID = groupID;
    emit groupIDChanged();
}

