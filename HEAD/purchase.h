#ifndef _PURCHACE_H_
#define _PURCHACE_H_
#include "database.h"
#include "queue.h"

void purchace_confirm_draw(USER *u, Ticket t); //购票信息确定界面绘制

void lightup_purchace_confirm(int x1, int y1, int x2, int y2, int flag);

void recoverbuttom_purchace_confirm(int x1, int y1, int x2, int y2, int flag);

void purchace_confirm_main(int *func, USER *u, Ticket t); //购票信息确定主函数

int info_check(char *health_code); //判断健康状态是否可以购票

void purchace_draw(char *name,char *id, Ticket t); //购票界面绘制

void purchace_main(int *func,USER u, Ticket t); //购票主函数

#endif