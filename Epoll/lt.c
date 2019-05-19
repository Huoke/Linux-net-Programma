#include "lt.h"

void Lt(struct epoll_event* events, int number, int epollfd, int listenfd)
{
   char buf[BUFFER_SIZE];
   for(int i = 0; i<number; i++)
   {
       int sockfd = events[i].data.fd;
       if(sockfd == listenfd)
       {
           struct sockaddr_in client_address;
           socklen_t client_addrlength = sizeof(client_address);
           int connfd = accept(listenfd, (struct sockaddr*)&client_address, &client_addrlength);
           addfd(epollfd, connfd, false);
       }else if (events[i].events & EPOLLIN){
           printf("event trigger once\n");
           memset(buf , '\0', BUFFER_SIZE);
            
           int ret = recv(sockfd, buf, BUFFER_SIZE-1,0);
           if(ret <= 0){
               close(sockfd);
               continue;
           }
           printf("get %d bytes of content: %s\n", ret, buf);
       }else{
           printf("something else happened \n");
       }

   }
}