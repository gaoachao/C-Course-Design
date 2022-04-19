#ifndef _AREA_H_
#define _AREA_H_
#include "database.h"

void area_main(int *func, USER *u);
void area_draw(void);
void get_username(USER *u);
void get_city_dangerlevel(Hold *h_list, City *c, int len);

#endif