#ifndef IQ42API_H
#define IQ42API_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>
#include <QNetworkReply>



class IQ42Api : public QObject
{
    Q_OBJECT
//    Q_INTERFACES(QObject)

public:
    IQ42Api();
    ~IQ42Api();
    void setBackendURL(QString URL);
    QUrl getBackendURL();

    void Ping();

public slots:
    void PingFinished();


private:
    QUrl backendURL;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
};

#endif // IQ42API_H
