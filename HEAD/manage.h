#ifndef _MANAGE_H_
#define _MANAGE_H_
#include "database.h"

void manage_main(int *func);
void manage_draw(void);
void get_cityname(City *c);
void lightup_manage(int x1, int y1, int x2, int y2, int flag);
void recover_manage(int x1, int y1, int x2, int y2, int flag);
void tick_high_draw(int x);
void tick_middle_draw(int x);
void tick_low_draw(int x);
void change_level(City *c, int x, char *level);

#endif