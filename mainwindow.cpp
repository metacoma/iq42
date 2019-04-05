#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    createActions();
    createTrayIcon();

    ui->setupUi(this);


}

void MainWindow::createTrayIcon() {
    trayIconMenu = new QMenu(this);

    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/iq42_icon.png"));
    trayIcon->setVisible(true);

    trayIcon->setContextMenu(trayIconMenu);

}

void MainWindow::createActions() {
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, &QCoreApplication::quit);
}


MainWindow::~MainWindow()
{
    delete ui;
}
