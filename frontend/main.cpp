#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSslSocket>
#include <QIcon>

#include "include/utility/ScreenInfo.h"
#include "include/map_control/QLocationSearch.h"
#include "include/models/plan_a_route/PlanARouteModel.h"
#include "include/models/plan_a_route/WaypointModel.h"
#include "include/models/UserModel.h"
#include "include/custom_controls/ValidationTextfieldModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QGuiApplication::setWindowIcon(QIcon(":/res/img/logo.jpeg"));

    QQmlApplicationEngine engine;


    qDebug() << "Device supports OpenSSL: " << QSslSocket::supportsSsl();

    qmlRegisterSingletonType<UserModel>("UserModel", 1, 0, "UserModel", UserModel::createSingletonInstance);
    qmlRegisterUncreatableType<UserModel::EMAIL_T>("EMAIL_T", 1, 0, "EMAIL_T", "");

    qmlRegisterType<ValidationTextfieldModel>("ValidationTextfieldModel", 1, 0, "ValidationTextfieldModel");

    qmlRegisterType<PlanARouteModel>("PlanARouteModel", 1, 0, "PlanARouteModel");
    qmlRegisterType<WaypointModel>("WaypointModel", 1, 0, "WaypointModel");


    qmlRegisterType<ScreenInfo>("ScreenInfo", 1, 0, "ScreenInfo");
    qmlRegisterType<QLocationSearch>("QLocationSearch", 1, 0, "QLocationSearch");


    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
