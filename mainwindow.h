#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QDebug>

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

    QMenu *trayIconMenu;
    QAction *quitAction;
    QAction *doAction;
};

#endif // MAINWINDOW_H
