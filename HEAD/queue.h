#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"database.h"
#define MaxSize 8//ÿһҳ�����ʾ��Ʊ����?
#define List_len 26
#define List_len_dynamic 30

typedef struct _TicketNode//��Ʊ����
{
    Ticket *ticket_info;
    int t_delay[List_len];
    int front;
    int rear;
}TNode;

void initQueue(TNode *node);//��ʼ������

int ticketinfo_read(Ticket *t_list,char *city1,char *city2,char *date);

int ticketinfo_read_number(Ticket *t_list, char *number);

void enqueue(TNode *node,Ticket *t_list,int prepage);

void enqueue_delay(TNode *node, Ticket *t_list, int prepage,int *delay_list);

void queue_down(int *prepage,int page_num);

void queue_up(int *prepage,int page_num);

#endif
