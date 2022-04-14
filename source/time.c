#include <time.h>
#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"

/***********************************
FUNCTION: display_time
DESCRIPTION: ʵʱ��ʾʱ��
INPUT: x,y ��ʾʱ���λ��,*ttemp
RETURN: ��
***********************************/
void display_time(int x, int y, char *ttemp)
{
	char time_str[40] = "\0"; //,ttemp[40];

	get_time(time_str);

	if (strcmp(ttemp, time_str) != 0) //ÿ����һ�븲��ԭʱ�䣬��ʾ��ʱ��
	{
		setfillstyle(1, WHITE);
		bar(x - 2, y - 5, x + 200, y + 10);
		outtextxy(x, y, time_str);
		strcpy(ttemp, time_str);
	}
	else
		return;
}

/***********************************
FUNCTION: get_time
DESCRIPTION: ��ȡʵʱʱ��
INPUT: *time_str
RETURN: ��
***********************************/
void get_time(char *time_str)
{
	time_t lt;
	struct tm *ptr;
	char year[5], mon[5], day[5], weekday[5], moment[10];

	setcolor(BLUE);
	settextstyle(2, 0, 5);
	settextjustify(LEFT_TEXT, CENTER_TEXT);

	lt = time(NULL);
	ptr = localtime(&lt); //��ȡ����ʱ��

	strftime(year, 5, "%Y", ptr);
	strcat(time_str, year);
	strcat(time_str, "."); //�����д��ʱ���ַ���

	strftime(mon, 5, "%m", ptr);
	strcat(time_str, mon);
	strcat(time_str, "."); //���·�д��ʱ���ַ���

	strftime(day, 5, "%d", ptr);
	strcat(time_str, day);
	strcat(time_str, "  "); //������д��ʱ���ַ���

	strftime(weekday, 5, "%a", ptr);
	strcat(time_str, weekday);
	strcat(time_str, "  "); //������д��ʱ���ַ���

	strftime(moment, 10, "%X", ptr);
	strcat(time_str, moment); //��ʱ�䣨��ȷ���룩д��ʱ���ַ���
}