#include "iq42button.h"

IQ42Button::IQ42Button(QWidget *parent) : QWidget(parent)
{
    m_quickWidget = new QQuickWidget(this);
    m_quickWidget->setSource(QUrl("qrc:/qml/iq42button.qml"));
}
