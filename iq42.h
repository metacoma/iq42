#ifndef IQ42_H
#define IQ42_H

#include <QObject>
#include <QDebug>

class IQ42 : public QObject
{
    Q_OBJECT
public:
    explicit IQ42(QObject *parent = nullptr);

signals:

public slots:
};

#endif // IQ42_H
