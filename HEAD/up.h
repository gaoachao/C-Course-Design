#ifndef _UP_H_
#define _UP_H_
#include"database.h"

void up_main(int *func, USER *u);
void up_draw(void);
void up_scan(void);
void lightup_up(int x1, int y1, int x2, int y2, int flag);
void recover_up(int x1, int y1, int x2, int y2, int flag);

#endif