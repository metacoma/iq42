#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QScreen>
#include "iq42api.h"
#include "iq42button.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void createTrayIcon();
    void createActions();
    ~MainWindow();

public slots:
    void IQ42Do();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
    void Screenshot();
    void Initialize();

    IQ42Api *backendApi;
    QImage screenshot;

    QMenu *trayIconMenu;
    QAction *quitAction;
    QAction *doAction;
    QPixmap shot;
    QScreen *screen;
};

#endif // MAINWINDOW_H
