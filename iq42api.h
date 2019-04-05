#ifndef IQ42API_H
#define IQ42API_H

#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>


class IQ42Api
{
public:
    IQ42Api();
    void setBackendURL(QString URL);
    QString getBackendURL();

    void Ping();

private:
    QUrl backendURL;
    QNetworkAccessManager qnam;
};

#endif // IQ42API_H
