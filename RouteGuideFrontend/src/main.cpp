#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSslSocket>
#include <QScreen>

#include "include/map_control/QLocationSearch.h"
#include "include/utility/ScreenInfo.h"
#include "include/navigation/NavigationManager.h"
#include "include/model/UserModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qDebug() << "Device supports OpenSSL: " << QSslSocket::supportsSsl();


    qmlRegisterType<QLocationSearch>("QLocationSearch", 1, 0, "QLocationSearch");
    qmlRegisterType<ScreenInfo>("ScreenInfo", 1, 0, "ScreenInfo");
    qmlRegisterType<NavigationManager>("NavigationManager", 1, 0, "NavigationManager");
    qmlRegisterType<UserModel>("UserModel", 1, 0, "UserModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
