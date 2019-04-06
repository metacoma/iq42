#ifndef IQ42_H
#define IQ42_H

#include <QObject>

class iq42 : public QObject
{
    Q_OBJECT
public:
    explicit iq42(QObject *parent = nullptr);

signals:

public slots:
};

#endif // IQ42_H