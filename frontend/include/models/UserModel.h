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

    explicit UserModel(QObject *parent = nullptr);
    static QObject* createSingletonInstance(QQmlEngine *engine,  QJSEngine *scriptEngine);

    QString user() const;
    bool loggedIn() const;
    Q_INVOKABLE void loginAttempt(const QVariantMap &data);
    Q_INVOKABLE void logoutAttempt();
    Q_INVOKABLE EMAIL_T emailType(const QString& email);
    //Q_INVOKABLE void registerAttempt(const QVariantMap &data);


private:
    static UserModel *m_instance;
    struct User{
        int id;
        QString email, userName;
        UserModel::EMAIL_T emailT;
        QByteArray token;
    };
    QString m_loginPath, m_logoutPath;
    std::optional<User> m_user;
    QVector<QString> m_companyMailAdresses;


signals:
    void userChanged();
};
