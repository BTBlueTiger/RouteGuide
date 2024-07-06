#include <QtQml/qqmlextensionplugin.h>
#include "setup.h"

void Setup::applicationAvailable()
{
    // custom code that does not require QQmlEngine
}

void Setup::qmlEngineAvailable(QQmlEngine *engine)
{
    engine->addImportPath("../../modules/ValidationTextfield");
}

void Setup::cleanupTestCase()
{
    // custom code to clean up before destruction starts
}

