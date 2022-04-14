#ifndef _RESERVE_H_
#define _RESERVE_H_
#include"database.h"

void hotlereserve_main(int *func,Hotle *booked);
void reserve_draw(void);
void city_page(int x, int y);
void city_cover(int x, int y);
void hotlecity_read(Hotle *h);
void hotle_display(Hotle *h, int num ,int line);
void hotle_cover(void);
void city_lightup(int x1, int y1, int x2, int y2);
void city_lightup_recover(int x1, int y1, int x2, int y2);
void lightup_reserve(int x1, int y1, int x2, int y2, int flag);
void recover_reserve(int x1, int y1, int x2, int y2, int flag);

#endif