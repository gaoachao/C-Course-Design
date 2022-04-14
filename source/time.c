#include <time.h>
#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"

/***********************************
FUNCTION: display_time
DESCRIPTION: 实时显示时间
INPUT: x,y 显示时间的位置,*ttemp
RETURN: 无
***********************************/
void display_time(int x, int y, char *ttemp)
{
	char time_str[40] = "\0"; //,ttemp[40];

	get_time(time_str);

	if (strcmp(ttemp, time_str) != 0) //每过了一秒覆盖原时间，显示新时间
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
DESCRIPTION: 获取实时时间
INPUT: *time_str
RETURN: 无
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
	ptr = localtime(&lt); //获取本地时间

	strftime(year, 5, "%Y", ptr);
	strcat(time_str, year);
	strcat(time_str, "."); //将年份写入时间字符串

	strftime(mon, 5, "%m", ptr);
	strcat(time_str, mon);
	strcat(time_str, "."); //将月份写入时间字符串

	strftime(day, 5, "%d", ptr);
	strcat(time_str, day);
	strcat(time_str, "  "); //将日期写入时间字符串

	strftime(weekday, 5, "%a", ptr);
	strcat(time_str, weekday);
	strcat(time_str, "  "); //将星期写入时间字符串

	strftime(moment, 10, "%X", ptr);
	strcat(time_str, moment); //将时间（精确到秒）写入时间字符串
}