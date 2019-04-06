#include "mainwindow.h"
#include "iq42.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(nullptr, QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        return 1;
    }


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("iq42", new IQ42(&engine));

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    /*
    MainWindow w;
    w.setWindowIcon(QIcon(":/images/iq42_icon32x32.png"));
    w.show();
    */

    return app.exec();
}
