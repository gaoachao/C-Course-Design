#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>
#include "hz.h"
#include "database.h"
#include "queue.h"

/***********************************
FUNCTION: initQueue
DESCRIPTION: 初始化队列
INPUT: *node
RETURN: 无
***********************************/
void initQueue(TNode *node)
{
	node->ticket_info = (Ticket *)malloc((MaxSize + 1) * sizeof(Ticket));
	if (!node->ticket_info)
	{
		printf("malloc runs wrong in initQueue\n");
		delay(3000);
		exit(1);
	}
	memset(node->ticket_info, '\0', (MaxSize + 1) * sizeof(Ticket));
	node->front = 0;
	node->rear = 0;
}

/***********************************
FUNCTION: ticketinfo_read
DESCRIPTION: 将机票信息读取到机票列表t_list里
INPUT: *t_list,*city1,*city2
RETURN: i(读入机票数)
***********************************/
int ticketinfo_read(Ticket *t_list, char *city1, char *city2, char *date)
{
	FILE *fp;
	Ticket t;
	char file_head[] = "database\\";
	char file_tail[] = ".dat";
	char file[30];
	int i = 0;
	memset(t_list, '\0', List_len * sizeof(Ticket));
	memset(file, '\0', sizeof(file));

	strcpy(file, file_head);
	strcat(file, date);
	strcat(file, file_tail);

	setcolor(RED);

	if ((fp = fopen(file, "rb+")) == NULL)
	{
		printf("cannot open file ticket\n");
		delay(3000);
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) //(ch = fgetc(fp)) != EOF)
	{
		memset(&t, '\0', sizeof(Ticket));
		fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", t.number, t.company, t.city1, t.city2, t.weather1, t.weather2, t.launch_time, t.land_time, t.tower, t.economy_price, t.business_price, t.distance, t.rate);
		if (strcmp(t.city1, city1) == 0 && strcmp(t.city2, city2) == 0 && i < List_len)
		{
			strcpy(t_list[i].number, t.number);
			strcpy(t_list[i].company, t.company);
			strcpy(t_list[i].city1, t.city1);
			strcpy(t_list[i].city2, t.city2);
			strcpy(t_list[i].weather1, t.weather1);
			strcpy(t_list[i].weather2, t.weather2);
			strcpy(t_list[i].launch_time, t.launch_time);
			strcpy(t_list[i].land_time, t.land_time);
			strcpy(t_list[i].tower, t.tower);
			strcpy(t_list[i].economy_price, t.economy_price);
			strcpy(t_list[i].business_price, t.business_price);
			strcpy(t_list[i].distance, t.distance);
			strcpy(t_list[i].rate, t.rate);
			strcpy(t_list[i].date, date);
			i++;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("cannot close file ticket");
		delay(2000);
		exit(1);
	}

	return i;
}

/***********************************
FUNCTION: ticketinfo_read_number
DESCRIPTION: 将机票信息读取到机票列表t_list里
INPUT: *t_list,*number
RETURN: i(读入机票数)
***********************************/
int ticketinfo_read_number(Ticket *t_list, char *number)
{
	FILE *fp;
	Ticket t;
	char file_head[] = "database\\";
	char file_tail[] = ".dat";
	char file[30];
	char date[3];
	int i = 0, j;
	//	memset(t, '\0', sizeof(Ticket));
	memset(t_list, '\0', List_len_dynamic * sizeof(Ticket));
	memset(date, '\0', sizeof(date));

	for (j = 1; j <= 28; j++)
	{
		memset(file, '\0', sizeof(file));
		itoa(j, date, 10);
		strcpy(file, file_head);
		strcat(file, date);
		strcat(file, file_tail);

		if ((fp = fopen(file, "rb+")) == NULL)
		{
			printf("cannot open file ticket\n");
			delay(3000);
			exit(1);
		}

		fseek(fp, 0, SEEK_SET);
		while (!feof(fp))
		{
			memset(&t, '\0', sizeof(Ticket));
			fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", t.number, t.company, t.city1, t.city2, t.weather1, t.weather2, t.launch_time, t.land_time, t.tower, t.economy_price, t.business_price, t.distance, t.rate);
			if (strcmp(t.number, number) == 0 && i < List_len_dynamic)
			{
				strcpy(t_list[i].number, t.number);
				strcpy(t_list[i].company, t.company);
				strcpy(t_list[i].city1, t.city1);
				strcpy(t_list[i].city2, t.city2);
				strcpy(t_list[i].weather1, t.weather1);
				strcpy(t_list[i].weather2, t.weather2);
				strcpy(t_list[i].launch_time, t.launch_time);
				strcpy(t_list[i].land_time, t.land_time);
				strcpy(t_list[i].tower, t.tower);
				strcpy(t_list[i].economy_price, t.economy_price);
				strcpy(t_list[i].business_price, t.business_price);
				strcpy(t_list[i].distance, t.distance);
				strcpy(t_list[i].rate, t.rate);
				strcpy(t_list[i].date, date);
				i++;
			}
			//			break;
		}
		if (fclose(fp) != 0)
		{
			printf("cannot close file ticket");
			delay(2000);
			exit(1);
		}
		delay(30);
	}
	return i;
}

/***********************************
FUNCTION: enqueue
DESCRIPTION: 数据入队
INPUT: *node,*t_list,prepage
RETURN: 无
***********************************/
void enqueue(TNode *node, Ticket *t_list, int prepage)
{
	int i;
	if ((node->rear + 1) % (MaxSize + 1) == node->front) //判断队列是否排满
	{
		return;
	}
	//    node->ticket_info=(Ticket*)malloc(MaxSize*sizeof(Ticket));
	for (i = 0; i < MaxSize; i++)
	{
		strcpy(node->ticket_info[node->rear].number, t_list[MaxSize * prepage + i].number);
		strcpy(node->ticket_info[node->rear].company, t_list[MaxSize * prepage + i].company);
		strcpy(node->ticket_info[node->rear].city1, t_list[MaxSize * prepage + i].city1);
		strcpy(node->ticket_info[node->rear].city2, t_list[MaxSize * prepage + i].city2);
		strcpy(node->ticket_info[node->rear].weather1, t_list[MaxSize * prepage + i].weather1);
		strcpy(node->ticket_info[node->rear].weather2, t_list[MaxSize * prepage + i].weather2);
		strcpy(node->ticket_info[node->rear].launch_time, t_list[MaxSize * prepage + i].launch_time);
		strcpy(node->ticket_info[node->rear].land_time, t_list[MaxSize * prepage + i].land_time);
		strcpy(node->ticket_info[node->rear].tower, t_list[MaxSize * prepage + i].tower);
		strcpy(node->ticket_info[node->rear].economy_price, t_list[MaxSize * prepage + i].economy_price);
		strcpy(node->ticket_info[node->rear].business_price, t_list[MaxSize * prepage + i].business_price);
		strcpy(node->ticket_info[node->rear].distance, t_list[MaxSize * prepage + i].distance);
		strcpy(node->ticket_info[node->rear].rate, t_list[MaxSize * prepage + i].rate);
		strcpy(node->ticket_info[node->rear].date, t_list[MaxSize * prepage + i].date);

		node->rear = (node->rear + 1) % (MaxSize);
	}
}

/***********************************
FUNCTION: enqueue_delay
DESCRIPTION: 数据入队
INPUT: *node,*t_list,prepage
RETURN: 无
***********************************/
void enqueue_delay(TNode *node, Ticket *t_list, int prepage,int *delay_list)
{
	int i;
	if ((node->rear + 1) % (MaxSize + 1) == node->front) //判断队列是否排满
	{
		return;
	}
	//    node->ticket_info=(Ticket*)malloc(MaxSize*sizeof(Ticket));
	for (i = 0; i < MaxSize; i++)
	{
		strcpy(node->ticket_info[node->rear].number, t_list[MaxSize * prepage + i].number);
		strcpy(node->ticket_info[node->rear].company, t_list[MaxSize * prepage + i].company);
		strcpy(node->ticket_info[node->rear].city1, t_list[MaxSize * prepage + i].city1);
		strcpy(node->ticket_info[node->rear].city2, t_list[MaxSize * prepage + i].city2);
		strcpy(node->ticket_info[node->rear].weather1, t_list[MaxSize * prepage + i].weather1);
		strcpy(node->ticket_info[node->rear].weather2, t_list[MaxSize * prepage + i].weather2);
		strcpy(node->ticket_info[node->rear].launch_time, t_list[MaxSize * prepage + i].launch_time);
		strcpy(node->ticket_info[node->rear].land_time, t_list[MaxSize * prepage + i].land_time);
		strcpy(node->ticket_info[node->rear].tower, t_list[MaxSize * prepage + i].tower);
		strcpy(node->ticket_info[node->rear].economy_price, t_list[MaxSize * prepage + i].economy_price);
		strcpy(node->ticket_info[node->rear].business_price, t_list[MaxSize * prepage + i].business_price);
		strcpy(node->ticket_info[node->rear].distance, t_list[MaxSize * prepage + i].distance);
		strcpy(node->ticket_info[node->rear].rate, t_list[MaxSize * prepage + i].rate);
		strcpy(node->ticket_info[node->rear].date, t_list[MaxSize * prepage + i].date);

		node->t_delay[node->rear]=delay_list[MaxSize * prepage + i];

		node->rear = (node->rear + 1) % (MaxSize);
	}
}



/***********************************
FUNCTION: queue_down
DESCRIPTION: 向下翻页
INPUT: *prepage,page_num
RETURN: 无
***********************************/
void queue_down(int *prepage, int page_num)
{
	(*prepage) = ((*prepage) + 1 + page_num) % page_num;
}

/***********************************
FUNCTION: queue_up
DESCRIPTION: 向上翻页
INPUT: *prepage,page_num
RETURN: 无
***********************************/
void queue_up(int *prepage, int page_num)
{
	(*prepage) = ((*prepage) - 1 + page_num) % page_num;
	//	printf("prepage=%d\n",*prepage);
}

/*void clearqueue(TNode *node)
{

}*/

/*    FILE *fp;
	int i=0,m=0;
//	int len=0;
//	int item=1;
//	char number[10],company[20],city1[20], city2[20],weather1[10],weather2[10],launch_time[10],land_time[10],tower[10],price[10],distance[10],rate[10];
	Ticket *t;

	memset(t,'\0',sizeof(Ticket));

	if((fp=fopen("database\\ticket.txt","rt+"))==NULL)
	{
		printf("cannot open file ticket\n");
		delay(3000);
		exit(1);
	}

	fseek(fp,0,SEEK_SET);

	for(i=0;i<4;i++)
	{
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",t.number,t.company,t.city1,t.city2,t.weather1,t.weather2,t.launch_time,t.land_time,t.tower,t.price,t.distance,t.rate);
		strcpy(node->ticket_info[node->rear].number,t.number);
		strcpy(node->ticket_info[node->rear].company,t.company);
		strcpy(node->ticket_info[node->rear].city1,t.city1);
		strcpy(node->ticket_info[node->rear].city2,t.city2);
		strcpy(node->ticket_info[node->rear].weather1,t.weather1);
		strcpy(node->ticket_info[node->rear].weather2,t.weather2);
		strcpy(node->ticket_info[node->rear].launch_time,t.launch_time);
		strcpy(node->ticket_info[node->rear].land_time,t.land_time);
		strcpy(node->ticket_info[node->rear].tower,t.tower);
		strcpy(node->ticket_info[node->rear].price,t.price);
		strcpy(node->ticket_info[node->rear].distance,t.distance);
		strcpy(node->ticket_info[node->rear].rate,t.rate);

		node->rear=(node->rear+1)%MaxSize;
	}
	// node->rear++;
   if (fclose(fp) != 0)
	{
		printf("cannot close ticket");
		delay(2000);
		exit(1);
	}
}
   //	printf("1\n");
	fseek(fp,prelen,SEEK_SET);

	while(ch!='\n')
	{
		fseek(fp,i*sizeof(char)+prelen,SEEK_SET);
		fread(&ch,sizeof(char),1,fp);
		i++;
		len++;//计算一行数据的长度（字符数）
		if(len==1)
		{
			printf("ch%d=%c\n",len,ch);
		}
	}
   //	printf("2\n");
	fseek(fp,prelen,SEEK_SET);

	for(i=0;i<len;i++)
	{
	//    fseek(fp, i * sizeof(char), SEEK_SET);
		fread(&ch,sizeof(char),1,fp);
		if(ch != '\t' && ch != '\n' && ch != '\r' && ch != ' ')
		{
			switch (item)
			{
			case 1:
			 node->ticket_info[node->rear].number[m]=ch;
			 break;

			case 2:
			 node->ticket_info[node->rear].company[m]=ch;
			 break;

			case 3:
			 node->ticket_info[node->rear].city1[m]=ch;
			 break;

			case 4:
			 node->ticket_info[node->rear].city2[m]=ch;
			 break;

			case 5:
			 node->ticket_info[node->rear].weather1[m]=ch;
			 break;

			case 6:
			 node->ticket_info[node->rear].weather2[m]=ch;
			 break;

			case 7:
			 node->ticket_info[node->rear].launch_time[m]=ch;
			 break;

			case 8:
			 node->ticket_info[node->rear].land_time[m]=ch;
			 break;

			case 9:
			 node->ticket_info[node->rear].tower[m]=ch;
			 break;

			case 10:
			 node->ticket_info[node->rear].price[m]=ch;
			 break;

			case 11:
			node->ticket_info[node->rear].distance[m]=ch;
			break;

			case 12:
			node->ticket_info[node->rear].rate[m]=ch;
			break;

			default:
			 break;
			}
		}
		m++;
		if(ch=='\t')
		{
			m=0;
			item++;
		}

		else if((ch=='\n'||ch=='\r'||i==len)&&item==12)
		{
			break;
		}
	}*/
