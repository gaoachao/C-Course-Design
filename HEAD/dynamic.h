#ifndef _DYNAMIC_H_
#define _DYNAMIC_H_
#include "database.h"
#include "queue.h"

void dynamic_draw1(void);

void dynamic_draw2(void);

void lightup_dynamic(int x1, int y1, int x2, int y2, int flag);

void recoverlightup_dynamic(int x1, int y1, int x2, int y2, int flag);

void dynamic_main1(int *func); //���ݳ��к����ڲ�ѯ

void dynamic_main2(int *func); //���ݺ���Ų�ѯ

void ticket_cover_dynamic(void);

void ticket_cover_dynamic_number(void);

void ticket_display_dynamic(TNode *node, int flag, int page_rest, int mode);

#endif