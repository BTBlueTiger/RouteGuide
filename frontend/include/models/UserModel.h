#include <QObject>
#include <QRegExp>
#include <QtQml>
#include <QQmlEngine>
#include <QJSEngine>

#include "include/connections/AbstractResource.h"

/***
 * Singleton
 *
*/
class UserModel : public AbstractResource
{
    Q_OBJECT
    Q_PROPERTY(QString user READ user NOTIFY userChanged)
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
        TOURIST
    };
    Q_ENUM(PREMIUM_GROUPS)

    explicit UserModel(QObject *parent = nullptr);
    static QObject* createSingletonInstance(QQmlEngine *engine,  QJSEngine *scriptEngine);

    QString user() const;
    bool loggedIn() const;
    bool registerSuccess() const;
    int email_t() const;

    void setEmail_t(int);


    Q_INVOKABLE void loginAttempt(const QVariantMap &data);
    Q_INVOKABLE void logoutAttempt();
    Q_INVOKABLE EMAIL_T emailType(const QString& email);

    Q_INVOKABLE void registerAttempt(const QVariantMap &data);

    Q_INVOKABLE void changePremiumGroup(int group);

private:
    static UserModel *m_instance;
    struct User{
        QString email, userName;
        EMAIL_T emailT;
    };

    QVector<int> premiumGroups;;
    QString m_loginPath, m_logoutPath;
    std::optional<User> m_user;
    QVector<QString> m_companyMailAdresses;
    int m_email_t;
    bool m_registerSuccess;


signals:
    void userChanged();
    void registerSuccessChanged();
    void premiumGroupsChanged(QVector<int>);
    void email_tChanged(int);
};
