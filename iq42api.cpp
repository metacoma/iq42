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
        QJsonDocument jsonReply = QJsonDocument::fromJson(pingReply.toUtf8());
        QJsonObject jsonObj = jsonReply.object();

        qDebug() << "Pong status" << jsonObj["pong"].toBool();

        if (jsonObj["pong"].toBool() != true) {
            qDebug() << "Server status error";
            // TODO fire fail event, try except
        }


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

void IQ42Api::uploadImage(QImage image) {
    QUrl apiEndpoint = QUrl(getBackendURL().toString() + "/uploadEZ");
    QByteArray postData;
    QByteArray imageData;
    QBuffer buffer(&imageData);
    image.save(&buffer, "PNG");

    QString boundary("------------------------------------asdfyiuqwer762345");

    postData.append("--" + boundary + "\r\n");
    postData.append("Content-Disposition: form-data; name=\"image\"\r\n\r\n");
    postData.append(imageData);
    postData.append("\r\n--" + boundary + "--\r\n");


    QNetworkRequest request(apiEndpoint);
    request.setRawHeader("Content-Type", QByteArray("multipart/form-data; boundary=").append(boundary));

    request.setHeader(QNetworkRequest::ContentLengthHeader, postData.size());

    qnam.post(request, postData);
    /*

    buffer.open(QIODevice::WriteOnly);
    buffer.write(boundary.toUtf8(), boundary.length());



    qDebug() << "Upload image size: " << buffer.size();

    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "image/png; boundary=" + boundary);
    qnam.post(networkRequest, postData);
    */
}

void IQ42Api::setBackendURL(QString URL) {
    backendURL = QUrl(URL);
}



QUrl IQ42Api::getBackendURL() {
    return backendURL;
}


