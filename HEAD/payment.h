#ifndef _PAYMENT_H_
#define _PAYMENT_H_
#include"database.h"

void payment_main(int *func, USER *u, Live *L);
void payment_draw(void);
void payment_info(USER *u, Live *L);
void recover_payment(int x1, int y1, int x2, int y2, int flag);
void lightup_payment(int x1, int y1, int x2, int y2, int flag);
void inputbankpassword(char *id, int x1, int y1, int charnum, int color);
void inputlive_database(USER *u, Live *L);

#endif
