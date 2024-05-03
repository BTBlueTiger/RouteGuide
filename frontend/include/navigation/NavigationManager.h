#include <QObject>
#include <QDebug>

class NavigationManager : public QObject
{
    Q_OBJECT

public:
    explicit NavigationManager(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE void changePage(const QString &page);

signals:
    void goToPage(const QString &page);

};
