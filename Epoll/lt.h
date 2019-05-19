#ifndef _LT_H__
#define _LT_H__
#include "util.h"

void Lt(struct epoll_event* events, int number, int epollfd, int listenfd);
#endif //_LT_H__