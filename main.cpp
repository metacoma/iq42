#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(nullptr, QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        return 1;
    }



    MainWindow w;
    w.setWindowIcon(QIcon(":/images/iq42_icon32x32.png"));
    w.createTrayIcon();
    w.show();

    return a.exec();
}
