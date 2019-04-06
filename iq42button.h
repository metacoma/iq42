#ifndef IQ42BUTTON_H
#define IQ42BUTTON_H

#include <QObject>
#include <QWidget>
#include <QtQuickWidgets/QQuickWidget>

class IQ42Button : public QWidget
{
    Q_OBJECT
public:
    explicit IQ42Button(QWidget *parent = nullptr);

signals:

public slots:

private:
    QQuickWidget *m_quickWidget;
};

#endif // IQ42BUTTON_H
