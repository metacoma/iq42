#ifndef IQ42BUTTON_H
#define IQ42BUTTON_H

#include <QObject>
#include <QWidget>

class IQ42Button : public QObject
{
    Q_OBJECT
public:
    explicit IQ42Button(QObject *parent = nullptr);

signals:

public slots:
};

#endif // IQ42BUTTON_H