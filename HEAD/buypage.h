#ifndef _BUYPAGE_H_
#define _BUYPAGE_H_
#include "database.h"
#include "queue.h"

#define Key_Up 0x4800	 // 向上方向键 　　
#define Key_Down 0x5000	 // 向下方向键
#define Key_Right 0x4d00 // 向右方向键
#define Key_Left 0x4b00	 // 向左方向键

void buypage_draw(void);
void buypage_count(int *page_num, int *page_rest, int len); //,int *state);
void buypage_main(int *func, Ticket *t);
void ticket_display(TNode *node, int flag, int page_rest);
void ticket_cover(void);
void city_select_page(int x, int y);
void city_select_lightup(int x1, int y1, int x2, int y2);
void city_select_lightup_recover(int x1, int y1, int x2, int y2);
void date_select_page(int x, int y);
// void date_select(int i,int j,char *date);

#endif