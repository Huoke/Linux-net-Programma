#include "util.h"
int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, new_option);
    return old_option;
}

// 将文件描述符fd上的EPOLLIN注册到epollfd指示的epoll内核事件表中, 参数enable_et指定是否对fd启动ET模式
void addfd(int epollfd, int fd, bool enable_et)
{
   struct epoll_event event;
   event.data.fd = fd;
   event.events = EPOLLIN;// 数据可读

   if(enable_et)
   {
       event.events |= EPOLLET;
   }
   epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
   setnonblocking(fd);
}
