#ifndef _HISTORY_H_
#define _HISTORY_H_
#include"database.h"
#define MaxSize 8

typedef struct HoldNode
{
    Hold *hold_info;
    int front;
    int rear;
}HNode;



void history_main(int *func, USER *u);
void history_draw(void);
void recover_history(int x1, int y1, int x2, int y2, int flag);
void lightup_history(int x1, int y1, int x2, int y2, int flag);
void enqueue_history(HNode *node, Hold *h_list, int prepage);
int holdinfo_read(USER *u, Hold *h_list);
void InitQueue(HNode *node);
void page_count(int *page_num, int *page_rest, int len) ;
void hold_cover(void);
void hold_display(HNode *node, int flag, int page_rest ,int page_num);

#endif