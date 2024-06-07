#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/qqmlextensionplugin.h>

#include "include/utility/ScreenInfo.h"
#include "include/ressource/AbstractRessource.h"



Q_IMPORT_QML_PLUGIN(ValidationTextfieldPlugin)


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<ScreenInfo>("ScreenInfo", 1, 0, "ScreenInfo");


    AbstractRessource a;



    const QUrl url(u"qrc:/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
