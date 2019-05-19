#ifndef _ET_H__
#define _ET_H__
#include "util.h"

void Et(struct epoll_event* events, int number, int epollfd, int listenfd);
#endif // _ET_H__