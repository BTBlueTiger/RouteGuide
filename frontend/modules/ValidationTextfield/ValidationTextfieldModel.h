#ifndef VALIDATIONTEXTFIELDMODEL_H
#define VALIDATIONTEXTFIELDMODEL_H

#include <QObject>
#include <QQmlEngine>

// Wir erben von der Base Klasse QObject
class ValidationTextfieldModel : public QObject
{
    Q_OBJECT
    // Propertys sind von Qml Dateien boabactbar und können mit
    // 1.               Typ Deklaration
    // 2. READ      -   Read Methode
    // 3. WRITE     -   Setter Methode
    // 4. NOTIFY    -   Signal zum qml element
    Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(QString borderColor READ borderColor NOTIFY borderColorChanged)
    Q_PROPERTY(QString color READ color NOTIFY colorChanged)
    Q_PROPERTY(float opacity READ opacity NOTIFY opacityChanged)
    Q_PROPERTY(int type READ type WRITE setType CONSTANT)
    // Unser Model ist quasie ein QML Element
    QML_ELEMENT

public:

    static constexpr int Default = 0;
    static constexpr int Error = 1;
    static constexpr int Valid = 2;

    enum ValidationTyp {
        NONE,
        EMAIL
    };
    Q_ENUM(ValidationTyp)

    explicit ValidationTextfieldModel(QObject* parent = nullptr);

    // Der nach außen sichtbare State des Q_PROPERTY
    // 2. READ      -   Read Methode
    int state() const;
    int type() const;
    float opacity() const;
    QString borderColor() const;
    QString color() const;

    // Der nach außen sichtbare State, kann also auch von einer qml verändert werden
    // 3. WRITE     -   Setter Methode
    void setState(const int state);
    void setType(const int type);

private:
    // Unser privater state des states
    // 1.               Typ Deklaration
    int m_state;
    int m_type;
    QString m_color = "transparent";
    QString m_borderColor = "dark_gray";
    float m_opacity = 1;
    QString getNewColor() const;
    QString getNewBorderColor() const;
    float getNewOpacity() const;

signals:
    // Der Signal der mit anderen Componenten reagiert
    // Ein Quasi Observer Pattern
    // 4. NOTIFY    -   Signal zum qml element
    void stateChanged();
    // Das Signal der mit anderen Componenten reagiert
    // Ein Quasi Observer Pattern
    // 4. NOTIFY    -   Signal zum qml element mit einem String
    void borderColorChanged(QString);
    void colorChanged(QString);
    void opacityChanged(float);

    //Slots sind quasi Empfänger
private slots:
    void changeBorderColorOnStateChanged();
    void changeColorOnStateChanged();
    void changeOpacityOnStateChanged();
};

#endif // VALIDATIONTEXTFIELDMODEL_H
