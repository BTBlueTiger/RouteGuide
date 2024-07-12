#include "ValidationTextfieldModel.h"

ValidationTextfieldModel::ValidationTextfieldModel(QObject* parent) : QObject(parent)
{
    // Wir brauchen einen Sender, das ist in diesem Fall diese Klasse this
    // Wir brauchen eine Funktion die Sendet, also ein SIGNAL das ist stateChanged
    // Wir braucehn einen Empfänger, wieder wir thist
    // Wir brauchen einen SLOT der das Signal annimt

    // Mit dieser Syntax nehmen wir statische Methoden
    connect(this, &ValidationTextfieldModel::stateChanged, this, &ValidationTextfieldModel::changeBorderColorOnStateChanged);

    // Mit dieser Syntax könnten wir zum Beispiel auch Parameter weitergeben
    connect(this, SIGNAL(stateChanged()), this, SLOT(changeColorOnStateChanged()));
    connect(this, SIGNAL(stateChanged()), this, SLOT(changeOpacityOnStateChanged()));
}

int ValidationTextfieldModel::type() const
{
    return m_type;
}

void ValidationTextfieldModel::setType(const int type)
{
    if(type == m_type)
        return;
    m_type = type;
}

int ValidationTextfieldModel::state() const
{
    return m_state;
}

QString ValidationTextfieldModel::getNewColor() const
{
    switch (m_state) {
    case Default:
        return "transparent";
    case Error:
        return "red";
    case Valid:
        return "green";
    default:
        return "transparent";
    }
}

QString ValidationTextfieldModel::getNewBorderColor() const
{
    switch (m_state) {
    case Default:
        return "white";
    case Error:
        return "red";
    case Valid:
        return "90EE90";
    default:
        return "white";
    }
}

float ValidationTextfieldModel::getNewOpacity() const
{
    if(m_state == Default){
        return 1;
    } else {
        return 0.2;
    }
}

QString ValidationTextfieldModel::color() const
{
    return m_color;
}

QString ValidationTextfieldModel::borderColor() const
{
    return m_borderColor;
}

float ValidationTextfieldModel::opacity() const
{
    return m_opacity;
}

void ValidationTextfieldModel::setState(const int state)
{
    if(m_state == state)
        return;
    m_state = state;
    emit stateChanged();
}


void ValidationTextfieldModel::changeBorderColorOnStateChanged()
{
    m_borderColor = getNewBorderColor();
    emit borderColorChanged(m_borderColor);
}

void ValidationTextfieldModel::changeColorOnStateChanged()
{
    m_color = getNewColor();
    emit colorChanged(m_color);
}

void ValidationTextfieldModel::changeOpacityOnStateChanged()
{
    float newOpacity = getNewOpacity();
    if(m_opacity != newOpacity)
    {
        m_opacity = getNewOpacity();
        emit opacityChanged(m_opacity);
    }
}
