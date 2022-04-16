#ifndef _hESUAN_H_
#define _HESUAN_H_
#include"database.h"

void hesuan_main(int *func, USER *u);
void hesuan_draw(void);
void recover_hesuan(int x1, int y1, int x2, int y2, int flag);
void lightup_hesuan(int x1, int y1, int x2, int y2, int flag);

#endif