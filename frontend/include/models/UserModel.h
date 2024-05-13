#include <QObject>
#include <QRegExp>
#include "./include/group/Group.h"


class UserModel : public QObject
{
    Q_OBJECT

public:
    explicit UserModel(QObject *parent = nullptr);

    Q_INVOKABLE void onLoginAttempt(const QString &email, const QString &password);
    Q_INVOKABLE void onRegisterAttempt(
        const QString &email,
        const QString &passwort,
        const QString &reenteredPassword
        );
    Q_INVOKABLE void onGroupSelect(const int &group);
    Q_INVOKABLE int onEmailAdressEntered(const QString &str);
    Q_INVOKABLE bool onPasswordEntered(const QString &str);
    Q_INVOKABLE bool onSecondPasswordEntered(const QString &str);
    Q_INVOKABLE int onEmailTypeRequestet();

signals:
    void loginAttemptSuccess(const int emailType);
    void loginAttemptFailed();

    void groupSelect();

    void onRegisterAttemptSuccess();
    void onRegisterAttemptFailed();

private:
    int emailToEmailType(const QString& email);

    QList<QString> companyMailAdresses;

    QString m_email;
    int m_emailType;
    QString m_password;
    QString m_lastName;
    QList<Group> m_groupsSelected;



    bool isLoggedIn;

    void addOrRemoveGroup(const Group& group);
};
