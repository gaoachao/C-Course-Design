#ifndef _USERPAGE_H_
#define _USERPAGE_H_
#include"database.h"


void userpage_main(int *func,USER* u);
void userpage_draw(void);
void get_userinfo(USER* u);
void input_healthcode(USER* u,char* health_code);
void lightup_userpage(int x1, int y1, int x2, int y2, int flag);
void recover_usepage(int x1, int y1, int x2, int y2, int flag);


#endif