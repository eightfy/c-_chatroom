#include<WINSOCK2.H>
#include<iostream>
#include<string>
#include <Ws2tcpip.h>
#include "member.h"
#include <QtWidgets/QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "set_name.h"
#include "ui_set_name.h"
using namespace std;

#define PORT 8888
#define AI_PORT 8000
#define QUEUE 20
char ip[] = "xxx.xx.xx.xxx";
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // 设置入口地址



DWORD _stdcall draw(LPVOID x);
DWORD _stdcall ai(LPVOID x);

int main(int argc, char *argv[])
{
    int port = PORT;
    QApplication qtn(argc, argv);
    set_name wn;
    wn.showw();
    qtn.exec();
    if(wn.check() == 4)
        port = AI_PORT;
    //--------------------------------------------
    SOCKET sclient;
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA data;
    if (WSAStartup(sockVersion, &data) != 0)
    {
        QMessageBox::information(NULL, "Error", "连接出错",QMessageBox::Ok);
        exit(1);
    }
    while (true) {
        sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sclient == INVALID_SOCKET)
        {
            QMessageBox::information(NULL, "Error", "invalid socket!",QMessageBox::Ok);
            exit(1);
        }

        sockaddr_in serAddr;
        serAddr.sin_family = AF_INET;
        serAddr.sin_port = htons(port);
        inet_pton(AF_INET, ip, &serAddr.sin_addr.S_un.S_addr);
        if (connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
        {  //连接失败
            //cout << "connect error !" << endl;
            closesocket(sclient);
            QMessageBox::information(NULL, "Error", "服务端现在未开启，请稍后再试",QMessageBox::Ok);
            exit(1);
        }
        else break;
    }
    //connection succeed
    //-----------------------------------------------------------------------------------------
    QApplication qtw(argc, argv);
    MainWindow w(nullptr, port);
    w.name = wn.name;
    w.sclient = sclient;
    w.show();
    long long int trans[2] = {0};
    trans[0] = sclient;
    trans[1] = (long long int)&w;
    switch(port)
    {
       case 8888:  CreateThread(NULL, 0, draw, trans, 0, NULL);break;
       case 8000:  CreateThread(NULL, 0, ai, trans, 0, NULL);
    }
    qtw.exec();
    WSACleanup();
    return 0;
}
