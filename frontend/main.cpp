#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSslSocket>
#include <QIcon>
#include <QtQml/qqmlextensionplugin.h>

#include "include/utility/ScreenInfo.h"

#include "include/models/UserModel.h"


#include "include/models/waypoint/WaypointModel.h"
#include "include/models/waypoint/WaypointModelItem.h"
#include "include/models/waypoint/WaypointModelManager.h"

#include "include/models/routing/RoutingModel.h"
#include "include/models/routing/RoutingManager.h"



Q_IMPORT_QML_PLUGIN(ValidationTextfieldPlugin)


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QGuiApplication::setWindowIcon(QIcon(":/res/img/logo.jpeg"));

    QQmlApplicationEngine engine;

    qDebug() << "Device supports OpenSSL: " << QSslSocket::supportsSsl();

    qmlRegisterSingletonType<UserModel>("UserModel", 1, 0, "UserModel", UserModel::createSingletonInstance);
    qmlRegisterUncreatableType<UserModel::EMAIL_T>("EMAIL_T", 1, 0, "EMAIL_T", "");

    qmlRegisterType<Waypoint::WaypointModelItem>("WaypointModelItem", 1, 0, "WaypointModelItem");
    qmlRegisterType<Waypoint::WaypointModel>("WaypointModel", 1, 0, "WaypointModel");
    qmlRegisterType<Waypoint::WaypointManager>("WaypointManager", 1, 0, "WaypointManager");

    qmlRegisterType<Routing::RoutingModel>("RoutingModel", 1, 0, "RoutingModel");
    qmlRegisterType<Routing::RoutingManager>("RoutingManager", 1, 0, "RoutingManager");


    qmlRegisterType<ScreenInfo>("ScreenInfo", 1, 0, "ScreenInfo");

    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
