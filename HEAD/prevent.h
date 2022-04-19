#ifndef _PREVENT_H_
#define _PREVENT_H_
#include "database.h"

// µœ÷¡¥±Ì
typedef struct list
{
  char data[30];
  int cur;
}StaticLinkList;


void prevent_main(int *func, USER *u);
void prevent_draw(void);
void city_read(City *c);
void get_cityinfo(City *c);
void lightup_prevent(int x1, int y1, int x2, int y2, int flag);
void recover_prevent(int x1, int y1, int x2, int y2, int flag);
void getinfo_List(StaticLinkList *space);
void InitList(StaticLinkList *space);
void printtips(StaticLinkList *space);
void tips_cover(void);
void List_next(int *flag, StaticLinkList *space);
void get_h_min_second(int *h, int *min, int *sec);

#endif