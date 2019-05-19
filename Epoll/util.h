#ifndef __UTIL_H__
#define __UTIL_H__
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>
#include <stdbool.h>
#include<libgen.h>
#define MAX_EVENT_NUMBER  1024
#define BUFFER_SIZE 10

int setnonblocking(int fd);
void addfd(int epollfd, int fd, bool enable_et);
typedef struct epoll_evnet epoll_evnet;
#endif //__UTIL_H__
