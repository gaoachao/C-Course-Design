#ifndef _MYCARD_H_
#define _MYCARD_H_
#include"database.h"



void mycard_main(int *func, USER *u);
void mycard_draw(void);
void get_cardinfo(USER *u);
void recover_cardinfo_draw(USER *u);
void recover_cardinfo(USER *u);


#endif