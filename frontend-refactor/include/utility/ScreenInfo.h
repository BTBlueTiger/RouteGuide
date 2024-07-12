#include <QObject>
#include <QGuiApplication>
#include <QScreen>

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
