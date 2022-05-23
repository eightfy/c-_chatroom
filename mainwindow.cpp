#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<WINSOCK2.H>
#include<iostream>
#include<string>
#include <Ws2tcpip.h>
#include "member.h"
using namespace std;



int connects(SOCKET sclient, char mm[1000], char nn[100]);
int connects(SOCKET sclient, char mm[1000]);

MainWindow::MainWindow(QWidget *parent, int m) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/app.ico"));
    mode = m;
}

MainWindow::~MainWindow()
{
    delete ui;
    WSACleanup();
    exit(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->textEdit->document()->isEmpty()) return;
    else{
        QString temp = ui->textEdit->toPlainText();
        QByteArray ba = temp.toLocal8Bit();
        char m[1000] = {0};
        strncpy(m,ba.data(),sizeof(m));
        QByteArray ba2 = name.toLocal8Bit();
        char n[100] = {0};
         strncpy(n,ba2.data(),sizeof(n));
         //cout<<n<<endl<<m<<endl;
         switch(mode)
         {
            case 8888:  connects(sclient, m, n);break;
            case 8000:
                    {
                        connects(sclient, m);
                        QString m0 = QString::fromLocal8Bit(m);
                        QString m1{":\n\t"};
                        QString me = name + m1 + m0;
                        send(me);
                    }
         }
        ui->textEdit->clear();
    }
}

void MainWindow::send(QString m)
{
    ui->textBrowser->insertPlainText(m);
    ui->textBrowser->insertPlainText("\n");
    ui->textBrowser->moveCursor(QTextCursor::End);
}
