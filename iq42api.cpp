#include "iq42api.h"

IQ42Api::IQ42Api()
{

    setBackendURL("http://8aff09151ba7.sn.mynetname.net:18080/ping");

}
void IQ42Api::setBackendURL(QString URL) {
    backendURL = URL;
}

QString IQ42Api::getBackendURL() {
    return backendURL;
}
