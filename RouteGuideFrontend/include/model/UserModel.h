#include <QObject>
#include "./include/group/Group.h"

class UserModel : public QObject
{
    Q_OBJECT

public:
    explicit UserModel(QObject *parent = nullptr) {}

    Q_INVOKABLE void onLoginAttempt(const QString &email, const QString &password);
    Q_INVOKABLE void onRegisterAttempt(
        const QString &firstName,
        const QString &lastName,
        const QString &email,
        const QString &passwort,
        const QString &reenteredPassword
        );
    Q_INVOKABLE void onGroupSelect(const int &group);

signals:
    void onLoginAttemptSuccess();
    void onLoginAttemptFailed();

    void groupSelect();

    void onRegisterAttemptSuccess();
    void onRegisterAttemptFailed();


private:
    QString m_email;
    QString m_firstName;
    QString m_lastName;
    QList<Group> m_groupsSelected;

    bool isLoggedIn;

    void addOrRemoveGroup(const Group& group);
};
