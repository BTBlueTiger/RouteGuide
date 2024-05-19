#ifndef VALIDATIONTEXTFIELDMODEL_H
#define VALIDATIONTEXTFIELDMODEL_H

#include <QObject>
#include <QQmlEngine>

class ValidationTextfieldModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(QString borderColor READ borderColor NOTIFY borderColorChanged)
    Q_PROPERTY(QString color READ color NOTIFY colorChanged)
    Q_PROPERTY(float opacity READ opacity NOTIFY opacityChanged)
    QML_ELEMENT

public:

    static constexpr int Default = 0;
    static constexpr int Error = 1;
    static constexpr int Valid = 2;

    explicit ValidationTextfieldModel(QObject* parent = nullptr);

    int state() const;
    float opacity() const;
    QString borderColor() const;
    QString color() const;
    void setState(const int state);

private:
    int m_state;
    QString m_color = "transparent";
    QString m_borderColor = "dark_gray";
    float m_opacity = 1;
    QString getNewColor() const;
    QString getNewBorderColor() const;
    float getNewOpacity() const;

signals:
    void stateChanged();
    void borderColorChanged(QString);
    void colorChanged(QString);
    void opacityChanged(float);
};

#endif // VALIDATIONTEXTFIELDMODEL_H
