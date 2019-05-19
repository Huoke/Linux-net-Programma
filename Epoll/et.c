#include "et.h"
/*ET模式的工作流程*/

void Et(struct epoll_event* events, int number, int epollfd, int listenfd)
{
    char buf[BUFFER_SIZE];
    for(int i=0; i< number; i++)
    {
        int sockfd = events[i].data.fd;

        if(sockfd == listenfd)
        {
            struct sockaddr_in client_address;
            socklen_t client_addrlength = sizeof(client_address);
            int connfd = accept(listenfd, (struct sockaddr*)&client_address, &client_addrlength);
            addfd(epollfd, connfd, true);// 对connfd 开启ET模式
        }
        else if(events[i].events & EPOLLIN)
        {
            printf("event trigggrt once\n");
            while(1)
            {
                memset(buf, '\0', BUFFER_SIZE);
                int ret = recv(sockfd, buf, BUFFER_SIZE-1, 0);
                if(ret <0 )
                {
                    // 对于非阻塞IO，下面的条件成立表示数据已经全部读取完毕, 此后epoll就能再次触发sockfd上的EPOLLIN事件，以此驱动下一次读操作
                    if((errno == EAGAIN) || (errno == EWOULDBLOCK))
                    {
                        printf("read later\n");
                        break;
                    }
                    close(sockfd);
                    break;
                }else if(ret > 0){
                    printf("get %d bytes of content:%s\n", ret, buf);
                }else{
                    printf("something else happend\n");
                }

            }
        }

    }
}