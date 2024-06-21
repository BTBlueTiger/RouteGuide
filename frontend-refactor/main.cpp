#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/qqmlextensionplugin.h>

#include "include/utility/ScreenInfo.h"
#include "modules/Models/UserModel/UserModel.h"




Q_IMPORT_QML_PLUGIN(ValidationTextfieldPlugin)


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<ScreenInfo>("ScreenInfo", 1, 0, "ScreenInfo");

    qmlRegisterUncreatableType<UserModel::EMAIL_T>("EMAIL_T", 1, 0, "EMAIL_T", "");
    qmlRegisterSingletonType<UserModel>("UserModel", 1, 0, "UserModel", UserModel::createSingletonInstance);


    const QUrl url(u"qrc:/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
