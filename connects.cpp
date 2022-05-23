#include<WINSOCK2.H>
#include<iostream>
#include<string>
#include <Ws2tcpip.h>
#include "member.h"
using namespace std;
DWORD _stdcall draw(LPVOID x);

int connects(SOCKET sclient, char mm[1000], char nn[100])
{

    bag sen(nn, mm);
    char temp[sizeof(sen)] = {0};
    unsigned long long int p = 0;
    for (p = 0; p < sizeof(sen)-1; p++)
        temp[p] = ((char*)&sen)[p];
    send(sclient, temp, sizeof(temp), 0);
    //send()用来将数据由指定的socket传给对方主机
    //int send(int s, const void * msg, int len, unsigned int flags)
    //s为已建立好连接的socket，msg指向数据内容，len则为数据长度，参数flags一般设0
    //成功则返回实际传送出去的字符数，失败返回-1，错误原因存于error
    //closesocket(sclient);
    return 0;
}

int connects(SOCKET sclient, char mm[1000])
{
    send(sclient, mm, 1000, 0);
    return 0;
}
