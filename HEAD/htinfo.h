#ifndef _HTINFO_H_
#define _HTINFO_H_
#include"database.h"

void htinfo_main(int *func, USER *u,Live *L);
void htinfo_draw(void);
void get_htinfo(USER *u);
void recover_htinfo(int x1, int y1, int x2, int y2, int flag);
void lightup_htinfo(int x1, int y1, int x2, int y2, int flag);

#endif