#ifndef _SCANPAY_H_
#define _SCANPAY_H_
#include "database.h"

void scanpay_main(int *func, USER *u, Live *L);
void scanpay_draw(void);
void scanpay_scan(void);
void lightup_scanpay(int x1, int y1, int x2, int y2, int flag);
void recover_scanpay(int x1, int y1, int x2, int y2, int flag);

#endif