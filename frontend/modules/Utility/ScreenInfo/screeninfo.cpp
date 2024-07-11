#include "screeninfo.h"
#include "QtGui/qscreen.h"

ScreenInfo::ScreenInfo(QObject *parent) : QObject(parent)
{
    QList<QScreen *> screens = QGuiApplication::screens();
    if(!screens.isEmpty())
    {
        QScreen * screen = screens.first();
        m_screenResolution = screen->size();
    }
}

void ScreenInfo::updateScreenInfo()
{
    QList<QScreen *> screens = QGuiApplication::screens();
    if(!screens.isEmpty())
    {
        QScreen * screen = screens.first();
        m_screenResolution = screen->size();
        emit screenResolutionChanged(m_screenResolution.width(), m_screenResolution.height());
    }
}

QSizeF ScreenInfo::screenResolution()
{
    return m_screenResolution;
}
