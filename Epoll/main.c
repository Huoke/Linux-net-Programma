#include "util.h"
#include "lt.h"
#include "et.h"

int main(int argc, char* argv[])
{
   if(argc <= 2)
   {
       printf("usage: %s ip_address port_number\n", basename(argv[0]));
       return 1;
   } 

   const char* ip = argv[1];
   int port = atoi(argv[2]);

   int ret = 0;
   struct sockaddr_in address;
   bzero(&address, sizeof(address));

   address.sin_family = AF_INET;
   inet_pton(AF_INET, ip, &address.sin_addr);
   address.sin_port = htons(port);
   
   int listenfd = socket(PF_INET, SOCK_STREAM, 0);
   assert( listenfd >= 0 );

   ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
   assert( ret != -1 );
   ret = listen(listenfd, 5);
   assert( ret != -1);

   struct epoll_event events[MAX_EVENT_NUMBER];
   int epollfd = epoll_create(5);
   assert(epollfd != -1);
   addfd(epollfd, listenfd, true);

   while(1)
   {
       int ret = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
       if(ret < 0)
       {
           printf("epoll failure\n");
           break;
       }

      // Lt(events, ret, epollfd, listenfd);
      Et(events, ret , epollfd, listenfd);
   }
   close(listenfd);
   return 0;
}
