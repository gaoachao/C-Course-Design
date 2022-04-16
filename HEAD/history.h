#ifndef _HISTORY_H_
#define _HISTORY_H_
#include"database.h"

void history_main(int *func, USER *u);
void history_draw(void);
void recover_history(int x1, int y1, int x2, int y2, int flag);
void lightup_history(int x1, int y1, int x2, int y2, int flag);

#endif