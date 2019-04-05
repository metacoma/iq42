#ifndef IQ42API_H
#define IQ42API_H

#include <QString>

class IQ42Api
{
public:
    IQ42Api();
    void setBackendURL(QString URL);
    QString getBackendURL();

private:
    QString backendURL;
};

#endif // IQ42API_H
