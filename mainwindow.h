#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include<WINSOCK2.H>
#include <Ws2tcpip.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, int m = 0);
    ~MainWindow();
    void send(QString m);
    void send(QString m, int f);
    void insimg(QString path);
    SOCKET sclient;
    QString name;


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int mode;
};

#endif // MAINWINDOW_H
