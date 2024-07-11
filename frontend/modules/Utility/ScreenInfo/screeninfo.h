#ifndef SCREENINFO_H
#define SCREENINFO_H

#include "qsize.h"
#include <QObject>

class ScreenInfo : public QObject
{
    Q_OBJECT

public:
    explicit ScreenInfo(QObject *parent = nullptr);
    Q_INVOKABLE QSizeF screenResolution();

public slots:
    void updateScreenInfo();

signals:
    void screenResolutionChanged(qreal width, qreal height);

private:
    QSizeF m_screenResolution;
};


#endif // SCREENINFO_H
