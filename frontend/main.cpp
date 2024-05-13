#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSslSocket>

#include "include/utility/ScreenInfo.h"
#include "include/models/UserModel.h"
#include "include/map_control/QLocationSearch.h"
#include "include/models/plan_a_route/PlanARouteModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qDebug() << "Device supports OpenSSL: " << QSslSocket::supportsSsl();

    qmlRegisterType<ScreenInfo>("ScreenInfo", 1, 0, "ScreenInfo");
    qmlRegisterType<UserModel>("UserModel", 1, 0, "UserModel");
    qmlRegisterType<QLocationSearch>("QLocationSearch", 1, 0, "QLocationSearch");
    qmlRegisterType<PlanARouteModel>("PlanARouteModel", 1, 0, "PlanARouteModel");


    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
