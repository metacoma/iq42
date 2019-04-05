#include "iq42api.h"

IQ42Api::IQ42Api()
{
    setBackendURL("http://8aff09151ba7.sn.mynetname.net:18080");


}

void IQ42Api::Ping() {
    QUrl pingUrl = QUrl(getBackendURL().toString() + "/ping");
    qnam.get(QNetworkRequest(pingUrl));
}

void IQ42Api::setBackendURL(QString URL) {
    backendURL = QUrl(URL);
}

QUrl IQ42Api::getBackendURL() {
    return backendURL;
}
