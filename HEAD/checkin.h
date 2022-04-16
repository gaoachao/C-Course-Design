#ifndef _CHECKIN_H_
#define _CHECKIN_H_
#include"database.h"

void checkin_main(int *func);
void lightup_checkin(int x1, int y1, int x2, int y2, int flag);
void recover_checkin(int x1, int y1, int x2, int y2, int flag);
void checkin_draw(void);
void date_select(int x, int y);
void check_in(char *day,int data);

#endif