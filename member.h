#pragma once
#ifndef MEMBER_H
#define MEMBER_H
#include <QMainWindow>
#include <time.h>
class bag
{
public:
    bag(char n[100], char m[1000]);
    bag();
    ~bag();
    QString send();
    QString send(int f);
    char checkm();
private:
    char name[100];
    time_t t;
    char message[1000];
};



#endif // !1
