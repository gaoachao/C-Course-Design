#ifndef _PURCHACE_H_
#define _PURCHACE_H_
#include "database.h"
#include "queue.h"

void purchace_confirm_draw(USER *u, Ticket t); //��Ʊ��Ϣȷ���������

void lightup_purchace_confirm(int x1, int y1, int x2, int y2, int flag);

void recoverbuttom_purchace_confirm(int x1, int y1, int x2, int y2, int flag);

void purchace_confirm_main(int *func, USER *u, Ticket t); //��Ʊ��Ϣȷ��������

int info_check(char *health_code); //�жϽ���״̬�Ƿ���Թ�Ʊ

void purchace_draw(char *name,char *id, Ticket t); //��Ʊ�������

void purchace_main(int *func,USER u, Ticket t); //��Ʊ������

#endif