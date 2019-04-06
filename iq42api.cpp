#include "iq42api.h"

IQ42Api::IQ42Api() : QObject ()
{
    setBackendURL("http://8aff09151ba7.sn.mynetname.net:18080");


}

IQ42Api::~IQ42Api() {
    qDebug() << "Destroy Api QObject";
}

void IQ42Api::PingFinished() {
    qDebug() << "Ping reply finished";
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

