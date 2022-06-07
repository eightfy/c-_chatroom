# c-_chatroom

## 简介
  高程课设，使用c++编写的面向对象的多线程聊天室
## 功能
1.多人聊天  
2.ai聊天（使用[GPT2 for Chinese chitchat](https://github.com/yangjianxin1/GPT2-chitchat)）  
## 部署
1.后端： 
在linux服务器上部署[服务端](https://github.com/eightfy/chatroom_serve)  
环境：gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)  
2.前端：  
环境：Qt6.2.4，QTCreator 7.0.0  
表情包来自：[桃井最中Monaka](https://space.bilibili.com/692437895/)  
## 使用
1.将ip、port更改为自己的服务器设置  
```c
#define PORT 8888
#define AI_PORT 8000
#define QUEUE 20
char ip[] = "xxx.xx.xx.xxx";
```
2.按上面所述部署后端  
3.编译聊天室  
3.进入聊天室  
## 可能会有的改进（真的会有吗）
1.使用账号密码注册登录  
2.可以发送多媒体文件（涩图群指日可待）  
3.支持私聊  
## tip
1.一次在线人数限制为十人，可在后端中[更改](https://github.com/eightfy/chatroom_serve/blob/master/fun.cpp)  
```c
int list(int* arg, int sClient, int flag)
{
    if (flag) {
        ...
        cout << "当前连接数" << j << endl;
        if (i == 10) {  #可以自由设置
            cout << "连接已满" << endl;
            return -1;
        }
        return 0;
    }
```
