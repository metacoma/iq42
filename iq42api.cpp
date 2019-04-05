#include "iq42api.h"

IQ42Api::IQ42Api()
{
    setBackendURL("http://8aff09151ba7.sn.mynetname.net:18080/");


}

void Ping() {

}

void IQ42Api::setBackendURL(QString URL) {
    backendURL = QUrl(URL);
}

QString IQ42Api::getBackendURL() {
    return backendURL.toString();
}
