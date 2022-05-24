#include<iostream>
#include <time.h>
#include<string.h>
#include<WS2tcpip.h>
#include "member.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMetaType>
using namespace std;

bag::bag(char n[100], char m[1000])
{
    strncpy(name, n, sizeof(name));
    strncpy(message, m, sizeof(message));
    time_t timep;
    time(&timep);
    t = timep;
}
bag::~bag(){}

QString bag::send()
{
    QString m1{ctime(&t)};
    QString m0{" "};
    QString m2 = QString::fromLocal8Bit(name);
    QString m3{"\t:"};
    QString m4 = QString::fromLocal8Bit(message);
    return m1+m0+m2+m3+m4;
}

QString bag::send(int f)
{
    QString m1{ctime(&t)};
    QString m0{" "};
    QString m2 = QString::fromLocal8Bit(name);
    QString m3 = ":\t";
    return m1+m0+m2+m3;
}

char bag::checkm()
{
    if(message[0] == '/'  && message[2] == '/' )
        return message[1];
    else
        return 'e';
}

DWORD _stdcall draw(LPVOID x)
{
    long long int* trans = (long long int*)x;
    SOCKET sclient = *trans;
    MainWindow *w = (MainWindow *)*(trans+1);
    while(1)
    {
        char n[100] = { 0 }, m[1000] = { 0 };
        bag *rec = new bag(n, m);
        int re = recv(sclient, (char*)rec, sizeof(bag), 0);
        if (re == 1112)
        {
            char file = rec->checkm();
            if(file != 'e')
            {
                QString m = rec->send(1);
                QMetaObject::invokeMethod(w, [w, m]{
                w->send(m,1);});
                QString path = QString(":/%1.png").arg(file);
                QMetaObject::invokeMethod(w, [w, path]{
                w->insimg(path);});
                continue;
            }
            QString m = rec->send();
            QMetaObject::invokeMethod(w, [w, m]{
            w->send(m);});
        }
        delete rec;
    }
    return 0;
}

DWORD _stdcall ai(LPVOID x)
{
    long long int* trans = (long long int*)x;
    SOCKET sclient = *trans;
    MainWindow *w = (MainWindow *)*(trans+1);
    while(1)
    {
        char m[1000] = { 0 };
        int re = recv(sclient, m, 1000, 0);
        if (re != 0)
        {
            QString m0 = QString::fromLocal8Bit(m);
            QString m1{":\n\t"};
            QString m2{"AI"};
            QString me = m2 + m1 + m0;
            QMetaObject::invokeMethod(w, [w, me]{
            w->send(me);});
        }
    }
    return 0;
}

