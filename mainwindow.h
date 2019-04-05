#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void createTrayIcon();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
};

#endif // MAINWINDOW_H
