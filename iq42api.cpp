#include "iq42api.h"

IQ42Api::IQ42Api() : QObject ()
{
    setBackendURL("http://8aff09151ba7.sn.mynetname.net:18080");


}

IQ42Api::~IQ42Api() {
    qDebug() << "Destroy Api QObject";
}

void IQ42Api::PingFinished() {

    if (reply->error() == QNetworkReply::NoError) {

        QString pingReply = QString::fromStdString(reply->readAll().toStdString());
        qDebug() << "Ping reply finished answer: " << pingReply;
        //QJsonDocument doc = QJsonDocument::fromJson((QString)reply->readAll());
    } else {
        // TODO fire fail event
        qDebug() << "Network error";
    }


}

void IQ42Api::Ping() {
    QUrl pingUrl = QUrl(getBackendURL().toString() + "/ping");
    reply = qnam.get(QNetworkRequest(pingUrl));
    QObject::connect(reply, &QNetworkReply::finished, this, &IQ42Api::PingFinished);
}

void IQ42Api::setBackendURL(QString URL) {
    backendURL = QUrl(URL);
}



QUrl IQ42Api::getBackendURL() {
    return backendURL;
}

