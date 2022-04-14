#include"hz.h"
#include<stdio.h>
#include<graphics.h>
#include"tictdisp.h"
#include"queue.h"

/***********************************
FUNCTION: welcome
DESCRIPTION: »æÖÆ»¶Ó­½çÃæ
INPUT: ÎÞ
RETURN: ÎÞ
***********************************/
void welcome_page(void)
{
	
	setbkcolor(GREEN);
	setcolor(WHITE);
	puthz(220,80,"º½ÂÃ×Ýºá",48,50,7);
	puthz(220-2,80-2,"º½ÂÃ×Ýºá",48,50,8);
	//rectangle(160,60,480,110);
	ellipse(320,360,180,360,22,50);
	arc(320,360,180,360,90);

	line(230,360,230,210);
	line(298,360,298,210);
	line(298,210,230,210);

	line(410,360,410,210);
	line(342,360,342,210);
	line(342,210,410,210);
	setcolor(WHITE);
	floodfill(231,221,WHITE);


	ellipse(230,240,270,7,250,120);
	ellipse(370,230,280,5,100,50);
	line(470,225,479,225);

	ellipse(230,310,125,280,100,50);
	ellipse(230,290,135,280,60,30);
	line(170,270,185,270);

	arc(230,0,270,300,320);

	setcolor(WHITE);
	floodfill(229,331,WHITE);

	floodfill(299,331,WHITE);

	floodfill(411,320,WHITE);

//	ticket_display(0,300);

}