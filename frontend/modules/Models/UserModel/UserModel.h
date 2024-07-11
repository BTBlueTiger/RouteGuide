#ifndef USERMODEL_H
#define USERMODEL_H

#include <QQmlEngine>
#include <QJSEngine>


#include "../../NetworkRessource/AbstractRessource/AbstractRessource.h"

class UserModel : public AbstractRessource {
    Q_OBJECT
    Q_PROPERTY(QString user READ user NOTIFY userChanged)
    Q_PROPERTY(QString group READ group NOTIFY groupChanged)
    Q_PROPERTY(QVariantList routes READ routes NOTIFY routesChanged FINAL)
    Q_PROPERTY(int groupID READ groupID WRITE setGroupID NOTIFY groupIDChanged FINAL)
    Q_PROPERTY(bool loggedIn READ loggedIn NOTIFY userChanged)
    Q_PROPERTY(bool registerSuccess READ registerSuccess NOTIFY registerSuccessChanged)

    Q_PROPERTY(int email_t READ email_t WRITE setEmail_t NOTIFY email_tChanged FINAL)

    Q_PROPERTY(QString loginPath MEMBER m_loginPath);
    Q_PROPERTY(QString logoutPath MEMBER m_logoutPath);

public:

    enum EMAIL_T {
        COMPANY,
        PRIVATE,
        PREMIUM,
        ERROR
    };
    Q_ENUM(EMAIL_T)

    enum PREMIUM_GROUPS {
        HIKER,
        SPORTLER,
        TOURIST,
        P_COMPANY
    };
    Q_ENUM(PREMIUM_GROUPS)



    explicit UserModel(QObject *parent = nullptr);
    static QObject* createSingletonInstance(QQmlEngine *engine,  QJSEngine *scriptEngine);

    QString user() const;
    QString group() const;
    bool loggedIn() const;
    bool registerSuccess() const;
    int email_t() const;
    int groupID() const;
    void setGroupID(int);
    void setEmail_t(int);
    QVariantList routes() const
    {
        return m_routes;
    }

    Q_INVOKABLE void loginAttempt(const QVariantMap &data);
    Q_INVOKABLE void logoutAttempt();
    Q_INVOKABLE EMAIL_T emailType(const QString& email);

    Q_INVOKABLE void registerAttempt(const QVariantMap &data);

    Q_INVOKABLE void changePremiumGroup(int group);
    Q_INVOKABLE bool createRoute(const QVariantMap& data);
    /**
     * int 0 = public
     * int 1 = private + public
     * @brief getRoutes
     */
    Q_INVOKABLE void getRoutes(int);

private:
    struct User{
        QString email, userName;
        EMAIL_T emailT;
        PREMIUM_GROUPS gr;
    };
    static UserModel *m_instance;


    QVariantList m_routes;
    QVector<int> premiumGroups;;
    QString m_loginPath, m_logoutPath;
    std::optional<User> m_user;
    QVector<QString> m_companyMailAdresses;
    int m_email_t;
    bool m_registerSuccess;
    int m_groupID = 1;

    std::shared_ptr<QUrl> m_userServiceURL;
    std::shared_ptr<QHttpHeaders> m_userServiceHttpHeaders;


signals:
    void userChanged();
    void groupChanged();
    void groupIDChanged();
    void registerSuccessChanged();
    void premiumGroupsChanged(QVector<int>);
    void email_tChanged(int);
    void routesChanged();

};


#endif // USERMODEL_H
