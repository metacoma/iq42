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

void MainWindow::IQ42Do() {
    qDebug() << "Do";
}

void MainWindow::createTrayIcon() {
    trayIconMenu = new QMenu(this);

    trayIconMenu->addAction(doAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/iq42_icon.png"));
    trayIcon->setVisible(true);

    trayIcon->setContextMenu(trayIconMenu);

}

void MainWindow::createActions() {
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, &QCoreApplication::quit);

    doAction = new QAction(tr("&Do"), this);
    //connect(doAction, &QAction::triggered, this, SLOT(IQ42Do()));
    connect(doAction, &QAction::triggered, this, [=]() { this->IQ42Do(); });

}


MainWindow::~MainWindow()
{
    delete ui;
}
