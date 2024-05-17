#include "include/custom_controls/ValidationTextfieldModel.h"

ValidationTextfieldModel::ValidationTextfieldModel(QObject* parent) : QObject(parent)
{

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
    m_borderColor = getNewBorderColor();
    m_color = getNewColor();
    float newOpacity = getNewOpacity();
    if(m_opacity != newOpacity)
    {
        m_opacity = getNewOpacity();
        emit opacityChanged(m_opacity);
    }
    emit borderColorChanged(m_borderColor);
    emit colorChanged(m_color);
    emit stateChanged();
}
