#include "UserModel.h"
//#include "include/Constants.h"


#include <QtNetwork/qhttpheaders.h>
#include <QtNetwork/qrestaccessmanager.h>
#include <QtNetwork/qrestreply.h>

#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>
#include <QtCore/QJsonArray>



#define WRONG_LOGIN true
#define IS_COMPANY false
#define WITH_API true

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
    m_companyMailAdresses.append("admin");
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
        switch (m_groupID) {
        case HIKER + 1:
            return "Hiker";
        case SPORTLER + 1:
            return "Sportler";
        case TOURIST + 1:
            return "Tourist";
        case P_COMPANY + 1:
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

bool UserModel::createRoute(const QVariantMap& data)
{
    QString route;
    if(m_email_t == PRIVATE)
    {
        route = "/route/create";
    }
    else
    {
        route = "/route/create_company_route";
    }
    QNetworkReply* response = postRequest(
        *qVariantMapToQByteArray(data),
        m_api->createRequest(route)
        );
    // Verbinden von der angekommenen Nachricht
    qDebug() << data;

    QObject::connect(response, &QNetworkReply::finished, [=](){
        if(response->error() == QNetworkReply::NoError)
        {

            qDebug() << "Success";
            return true;
        }
        else
        {
            qDebug() << "Failure";
            return false;
        }
    }
                     );
    return false;
}

void UserModel::getRoutes(int type)
{
    QString route;
    if(m_email_t == PRIVATE)
    {
        if(type == 0) {
            route = "/route/get";
        } else {
            route = "/route/get_routes_auto";
        }

    } else {
        if(type == 0) {
            route = "/route/get_routes_company";
        } else {
            route = "/route/get_routes_company_public";
        }
    }

    QNetworkReply * secondResponse = getRequest(m_api->createRequest(route));
    QVariantList routes;
    m_routes.clear();
    QObject::connect(secondResponse, &QNetworkReply::finished, this, [=]()
    {
        QByteArray jsonData = secondResponse->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        QJsonArray jsonArr = jsonDoc.array();
        QVariantMap route;
        QVariantList routeList;

        for (const QJsonValue &value : jsonArr)
        {
            QString name;
            QVariantMap addressMap;
            QVariantList addresses;
            QJsonObject jsonObj = value.toObject();
            if (jsonObj.contains("name") && jsonObj["name"].isString())
            {
                name = jsonObj["name"].toString();
            }
            if (jsonObj.contains("addresses") && jsonObj["addresses"].isArray())
            {
                QJsonArray addressesArray = jsonObj["addresses"].toArray();
                for (const QJsonValue &addrValue : addressesArray)
                {
                    QJsonObject addrObj = addrValue.toObject();
                    if (addrObj.contains("identifier") && addrObj["identifier"].isString()) {
                        addressMap["identifier"] = addrObj["identifier"].toString();
                    }
                    addressMap["latitude"] = addrObj["latitude"].toDouble();

                    addressMap["longitude"] = addrObj["longitude"].toDouble();

                    addresses.append(addressMap);
                }
                route["addresses"] = addresses;
                routeList.append(route);
                addresses.clear();
            }
            route.clear();
        }
        m_routes = routeList;
        emit routesChanged();
    });
}


/**
 * Dont know why this dont work like it used to be
 * @brief UserModel::loginAttempt
 * @param data
 */
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
                                     qDebug() << jsonObj;
                                     m_user =
                                         {
                                             jsonObj["email"].toString(),
                                             jsonObj["username"].toString()
                                         };

                                     if(jsonObj["company"].isNull())
                                     {
                                         m_email_t = EMAIL_T::PRIVATE;
                                         m_user->emailT = EMAIL_T::PRIVATE;
                                         emit email_tChanged(1);
                                     }
                                     else
                                     {
                                         m_email_t = EMAIL_T::COMPANY;
                                         m_user->emailT = EMAIL_T::COMPANY;
                                         emit email_tChanged(0);
                                     }
                                     QJsonObject jsonGroup = jsonObj["group"].toObject();
                                     m_groupID = jsonGroup["id"].toInt();
                                     qDebug() << m_groupID;
                                     emit groupIDChanged();
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
        return it != m_companyMailAdresses.cend() ? EMAIL_T::COMPANY : EMAIL_T::PRIVATE ;
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

    if(m_email_t == COMPANY){
        QVariantMap nestedGroup = data["group"].toMap();

        // Step 2: Modify the id value
        nestedGroup["id"] = 2; // Change the id to the desired value
        // Step 3: Reassign the modified nested map back to the original QVariantMap
        data["group"] = nestedGroup;
    }

    QNetworkReply* response = postRequest(
        *qVariantMapToQByteArray(data),
        m_api->createRequest("/auth/register")
    );

    QObject::connect(response, &QNetworkReply::finished, [=](){
        if(response->error() == QNetworkReply::NoError)
        {
            qDebug() << "No Error";
            m_registerSuccess = true;
            emit registerSuccessChanged();
        }
        else
        {
            qDebug() << response;
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

