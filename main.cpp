#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setWindowIcon(QIcon(":../../Downloads/iq42_icon.png"));
    w.setWindowIcon(QIcon(":/images/iq42_icon32x32.png"));
    w.show();

    return a.exec();
}
