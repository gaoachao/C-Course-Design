#ifndef _BOOKED_H_
#define _BOOKED_H_
#include "database.h"

void booked_main(int *func, USER *u, Hotle *h, Live *L);
void hotle_booked_draw(char *name, char *hotle_city,char *hotle_name,char *hotle_class,char *price);
void lightup_booked(int x1, int y1, int x2, int y2, int flag);
void recover_booked(int x1, int y1, int x2, int y2, int flag);

#endif