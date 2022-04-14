#include<stdio.h>
#include<graphics.h>
//#include<passwording.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include"hz.h"
#include"mouse.h"
#include"database.h"
#include"login.h"
#include"register.h"
#include"change.h"

/***********************************
FUNCTION: change_main
DESCRIPTION: 忘记密码主函数
INPUT: *func
RETURN: 无
***********************************/
void change_main(int *func)
{
	int num=0;
	USER *u;
	int state1=0;
	int state2=0;
	int state3=0;
	int state4=0;
	static int flag=0;
	int password_flag=0,password_flag_record=0;

	char name[16];//输入的用户名
	char id[20];//输入的身份证号码
	char password[16];//密码
	char str[16];//第二次输入密码

	int flag1;

	memset(name,'\0',sizeof(name));
	memset(id,'\0',sizeof(id));
	memset(password,'\0',sizeof(password));
	memset(str,'\0',sizeof(str));

	clrmous(MouseX,MouseY);
	delay(10);
	cleardevice();

	change_page();
	exit_buttom();

	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);

		//账号栏
		if(MouseX>120&&MouseX<520&&MouseY>120&&MouseY<150)
		{
			if(mouse_press(120,120,520,150)==2)//账号输入框未点击
			{
				MouseS=2;
				if(num==0&&state1==0)
				{
					lightup_change(120,120,520,150,1);
					num=1;
				}
				continue;
			}
			else if(mouse_press(120,120,520,150)==1)//账号输入栏点击
			{
				lightup_change(120,120,520,150,1);
				memset(name,'\0',sizeof(name));//用户名清除
				inputadmin(name,120,120,15,7);//输入用户名
				if(strlen(name)==0)
				{
					state1=0;
				}
				else state1=1;
			}
		}

		//输入身份证号栏
		if(MouseX>120&&MouseX<520&&MouseY>190&&MouseY<220)
		{
			if(mouse_press(120,190,520,220)==2)//输入身份证号未点击
			{
				MouseS=2;
				if(num==0&&state2==0)
				{
					lightup_change(120,190,520,220,1);
					num=1;
				}
				continue;
			}
			else if(mouse_press(120,190,520,220)==1)//身份证号输入栏点击
			{
				lightup_change(120,190,520,220,1);
				memset(id,'\0',sizeof(id));//身份证号清除
				inputadmin(id,120,190,18,7);//输入身份证号
				if(strlen(id)==0)
				{
					state2=0;
				}
				else state2=1;
			}
		}

		//新密码栏
		if(MouseX>120&&MouseX<520&&MouseY>260&&MouseY<290)
		{
			if(mouse_press(120,260,520,290)==2)//新密码框未点击
			{
				MouseS=2;
				if(num==0&&state3==0)
				{
					lightup_change(120,260,520,290,1);
					num=1;
				}
				continue;
			}
			else if(mouse_press(120,260,520,290)==1)//新密码输入栏点击
			{
				lightup_change(120,260,520,290,1);
				memset(password,'\0',sizeof(password));//确定密码清除
				inputadmin(password,120,260,15,7);//输入新密码
				if(strlen(password)==0)
				{
					state3=0;
				}
				else state3=1;
			}
		}

		//确认密码栏
		if(MouseX>120&&MouseX<520&&MouseY>330&&MouseY<360)
		{
			if(mouse_press(120,330,520,360)==2)//确认密码栏未点击
			{
				MouseS=2;
				if(num==0&&state4==0)
				{
					lightup_change(120,330,520,360,1);
					num=1;
				}
				continue;
			}
			else if(mouse_press(120,330,520,360)==1)//确认密码输入栏点击
			{
				lightup_change(120,330,520,360,1);
				memset(str,'\0',sizeof(str));//确认密码清除
				inputadmin(str,120,330,15,7);//输入确认密码
				if(strlen(str)==0)
				{
					state4=0;
				}
				else state4=1;
			}
		}

		//检查两次输入密码是否相同
		if(state3==1&&state4==1)
		{
			password_flag=confirm_password(password,str);
			if(flag==0)
			{
				confilm_password_state(360,360,password_flag);
				password_flag_record=password_flag;
				flag++;
			}
			else
			{
				if(password_flag!=password_flag_record)
				{
					if(password_flag==1)
					{
						confilm_password_state(360,360,1);
					}
					else
					{
						confilm_password_state(360,360,0);
					}
					password_flag_record=password_flag;
				}
			}

		}

		//更改密码键
		if(MouseX>120&&MouseX<400&&MouseY>250&&MouseY<430)
		{
			if(mouse_press(120,400,250,430)==2)//更改密码键未点击
			{
				MouseS=1;
				if(num==0)
				{
					lightup_change(120,400,250,430,2);
					num=2;
				}
				continue;
			}
			else if(mouse_press(120,400,250,430)==1)//更改密码键点击
			{
				lightup_change(120,400,250,430,2);
				if(change_complete_judge(name,id,password,str,u)==1)
				{
					puthz(230,380,"更改密码成功",24,30,GREEN);	
					delay(3000);
					*func=0;
					return;
				}
				else continue;

			}
		}

		//返回键
		if(MouseX>390&&MouseX<520&&MouseY>250&&MouseY<430)
		{
			if(mouse_press(390,400,520,430)==2)//返回键未点击
			{
				MouseS=1;
				if(num==0)
				{
					lightup_change(390,400,520,430,3);
					num=3;
				}
				continue;
			}
			else if(mouse_press(390,400,520,430)==1)//返回键点击
			{
				lightup_change(390,400,520,430,3);
				*func=0;
				return;
			}
		}

		//退出键
		if(MouseX>595&&MouseX<640&&MouseY>0&&MouseY<20)
		{
			if(mouse_press(595,0,640,20)==1){
			    *func=1;
	    		return;
			}
		}

		//输入框及按键点亮恢复
		if(num!=0)
		{
			MouseS=0;
			if(state1==0)
			{
				recoverbuttom_change(120,120,520,150,1);
			}
			if(state2==0)
			{
				recoverbuttom_change(120,190,520,220,1);
			}
			if(state3==0)
			{
				recoverbuttom_change(120,260,520,290,1);
			}
			if(state4==0)
			{
				recoverbuttom_change(120,330,520,360,1);
			}
			if(num==2)
			{
				recoverbuttom_change(120,400,250,430,2);
			}
			if(num==3)
			{
				recoverbuttom_change(390,400,520,430,3);
			}

			num=0;
		}

		if(MouseS!=0) MouseS=0;

	}
}

/***********************************
FUNCTION: change_complete_judge
DESCRIPTION: 检测是否可以修改密码
INPUT: *name,*id,*password,*str,*u
RETURN: 1(可以修改密码)/0(不可以修改密码)
***********************************/
int change_complete_judge(char *name,char *id,char *password,char*str,USER *u)
{
	int state=0;
	int state1=0;//用户名信息检测
	int state2=0;//身份证号信息检测
	int state3=0;//密码信息检测/
	int state4=0;//确认密码信息检测
	int i=0;

	state+=input_judge(name,522,120);
	state+=input_judge(id,522,190);

    //printf("state=%d",state);

	state1=name_search(name,u,520,120,&i);

	if(state==2)
	{
		
		if(state1==1)
		{
			state2=name_id_judge(id,u,520,190);
		}
	//	state3=change_password_judge(password,520,260);
	//	state4=change_confilm_judge(password,str,520,330);
	}

	state+=input_judge(password,522,260);
	state+=input_judge(str,522,330);
	state3=change_password_judge(password,520,260);
	state4=change_confilm_judge(password,str,520,330);

	if(state1==1&&state2==1&&state3==1&&state4==1)
	{
		password_write(u,password,i);
		return 1;
	}
	else return 0;

}

/***********************************
FUNCTION: password_write
DESCRIPTION: 写入新密码
INPUT: *u,*password,i
RETURN: 无
***********************************/
void password_write(USER *u,char *password,int i)
{
	FILE *fp;
	strcpy(u->password,password);
	if((fp=fopen("database\\userdata.dat","rb+"))==NULL)
	{
		printf("cannot open file userbase\n");
		delay(3000);
		exit(1);
	}
	fseek(fp,i*sizeof(USER),SEEK_SET);
	fwrite(u,sizeof(USER),1,fp);
	if(fclose(fp)!=0)
    {
        printf("cannot close database\n");
        delay(2000);
        exit(1);
    }
}


/***********************************
FUNCTION: name_search
DESCRIPTION: 搜索用户名
INPUT: *name,*u,x,y
RETURN: 1(找到需要修改的用户)/0(未找到)
***********************************/
int name_search(char *name,USER *u,int x,int y,int *i)
{
	FILE *fp;
	USER *utemp;
	int len;
	int j;

	memset(utemp,'\0',sizeof(USER));

	if((fp=fopen("database\\userdata.dat","rb+"))==NULL)
	{
		printf("cannot open file userbase\n");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);
	len=ftell(fp)/sizeof(USER);//用户数量
	for(j=0;j<len;j++)
	{
		if((utemp=(USER*)malloc(sizeof(USER)))==NULL)
		{
			printf("malloc runs wrong\n");
			delay(3000);
			exit(1);
		}
		fseek(fp,j*sizeof(USER),SEEK_SET);
		fread(utemp,sizeof(USER),1,fp);
	  //	printf("%s %s",utemp->name,name);
		if(strcmp(name,utemp->name)==0)//找到匹配的用户
		{

           // printf("%s %s\n",utemp->name,utemp->id);

			//遮挡已有文字
			clrmous(MouseX,MouseY);
        	delay(10);
	    	setfillstyle(SOLID_FILL,LIGHTCYAN);
    		bar(x+2,y,x+2+130,y+30);

			//画对勾
			setcolor(GREEN);
	    	setlinestyle(SOLID_LINE, 0, 3);
     		line(x+2 + 3, y + 10, x+2 + 13, y + 20);
    		line(x+2 + 13, y + 20, x+2 + 23, y);

			//读出该用户信息
			strcpy(u->name,utemp->name);
			strcpy(u->password,utemp->password);
			strcpy(u->id,utemp->id);
			strcpy(u->bank,utemp->bank);
			strcpy(u->bankpassword,utemp->bankpassword);
		   //	strcpy(u->nextUser,utemp->nextUser);

		   *i=j;

			//退出
			if(utemp!=NULL)
			{
				free(utemp);
				utemp=NULL;
			}
			if(fclose(fp)!=0)
			{
				printf("database can't be closed\n");
				delay(3000);
				exit(1);
			}
			return 1;
		}
		free(utemp);
		utemp=NULL;
	}
	if(j==len&&strlen(name)!=0)//未找到用户
	{
		//遮挡已有文字
			clrmous(MouseX,MouseY);
			delay(10);
			setfillstyle(SOLID_FILL,LIGHTCYAN);
			bar(x+2,y,x+2+120,y+30);

			puthz(x+2,y,"用户名不存在",16,18,RED);

			//退出
			if(utemp!=NULL)
			{
				free(utemp);
				utemp=NULL;
			}
			if(fclose(fp)!=0)
			{
				printf("database can't be closed\n");
				delay(3000);
				exit(1);
			}
			return 0;
	}
}

/***********************************
FUNCTION: name_id_judge
DESCRIPTION: 判断用户名和身份证号码是否匹配
INPUT: jd,*u,x,y
RETURN: 1(匹配)/0(不匹配)
***********************************/
int name_id_judge(char *id,USER *u,int x,int y)
{
	int flag=strcmp(id,u->id);
	if(flag==0)//用户名和身份证号码匹配
	{
		//printf("flag=%d\n",flag);
		//遮挡已有文字
		clrmous(MouseX,MouseY);
		delay(10);
		setfillstyle(SOLID_FILL,LIGHTCYAN);
		bar(x+2,y,x+2+120,y+30);

		//画对勾
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x+2 + 3, y + 10, x+2 + 13, y + 20);
		line(x+2 + 13, y + 20, x+2 + 23, y);

		return 1;
	}
	else 
	{
		//printf("flag=%d\n",flag);
		//遮挡已有文字
		clrmous(MouseX,MouseY);
        delay(10);
	    setfillstyle(SOLID_FILL,LIGHTCYAN);
    	bar(x+2,y,x+2+120,y+30);

		puthz(x+2,y,"身份证号错误",16,18,RED);
		return 0;
	}
}

/***********************************
FUNCTION: change_password_judge
DESCRIPTION: 判断密码是否大于等于6位
INPUT: *password,x,y
RETURN: 1/0
***********************************/
int change_password_judge(char *password,int x,int y)
{
	int len=strlen(password);
	if(len>=6)//密码大于等于6位
	{
		//遮挡已有文字
		clrmous(MouseX,MouseY);
        delay(10);
	    setfillstyle(SOLID_FILL,LIGHTCYAN);
    	bar(x+2,y,x+2+120,y+30);

		//画对勾
		setcolor(GREEN);
	    setlinestyle(SOLID_LINE, 0, 3);
    	line(x+2 + 3, y + 10, x+2 + 13, y + 20);
    	line(x+2 + 13, y + 20, x+2 + 23, y);

		return 1;
	}
	else if(len>0&&len<6)
	{
		//遮挡已有文字
		clrmous(MouseX,MouseY);
        delay(10);
	    setfillstyle(SOLID_FILL,LIGHTCYAN);
    	bar(x+2,y,x+2+120,y+30);

		puthz(x+2,y,"输入过短",16,18,RED);
		return 0;
	}
}

/***********************************
FUNCTION: change_confilm_judge
DESCRIPTION: 判断密码与确认密码是否一致
INPUT: *password,str,x,y
RETURN: 1/0
***********************************/
int change_confilm_judge(char *password,char *str,int x,int y)
{
	if(confirm_password(password,str)==1&&strlen(str)!=0)//密码与确认密码一致
	{
		//遮挡已有文字
		clrmous(MouseX,MouseY);
        delay(10);
	    setfillstyle(SOLID_FILL,LIGHTCYAN);
		bar(x+2,y,x+2+120,y+30);

		//画对勾
		setcolor(GREEN);
	    setlinestyle(SOLID_LINE, 0, 3);
    	line(x+2 + 3, y + 10, x+2 + 13, y + 20);
    	line(x+2 + 13, y + 20, x+2 + 23, y);

		return 1;
	}
	else return 0;
}

/***********************************
FUNCTION: lightup_change
DESCRIPTION: 重置密码界面按钮点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_change(int x1,int y1,int x2,int y2,int flag)
{
	clrmous(MouseX,MouseY);
	delay(10);
	setcolor(LIGHTRED);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, LIGHTGRAY);
	
	bar(x1,y1,x2,y2);//填充内部
	rectangle(x1-1,y1-1,x2+1,y2+1);//画边框
	switch (flag)
	{
	case 1:break;

	case 2:
	{
		puthz(129,404,"重置密码",24,30,RED);
		break;
	}

	case 3:
	{
		puthz(420,404,"返回",24,46,RED);
		break;
	}

	default:
		printf("something wrong in loghtup_register\n");
		break;
	}
}

/***********************************
FUNCTION: recoverbuttom_change
DESCRIPTION: 注册界面按钮点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void recoverbuttom_change(int x1,int y1,int x2,int y2,int flag)
{
	clrmous(MouseX,MouseY);
	delay(10);

	setcolor(LIGHTCYAN);
	setfillstyle(SOLID_FILL,WHITE);
	rectangle(x1-1,y1-1,x2+1,y2+1);
	bar(x1,y1,x2,y2);

	switch (flag)
	{
	case 1:
		break;

	case 2:
	{
		puthz(129,404,"重置密码",24,30,DARKGRAY);
		break;
	}

	case 3:
	{
		puthz(420,404,"返回",24,46,DARKGRAY);
		break;
	}

	default:
	{
		printf("something wrong in recoverbuttom_change\n");
		closegraph();
		exit(1);
	}
	}
}

/***********************************
FUNCTION: change_page
DESCRIPTION: 绘制更改密码界面
INPUT: 无
RETURN: 无
***********************************/
void change_page(void)
{
	//画背景
	clrmous(MouseX,MouseY);
	delay(10);

	setbkcolor(LIGHTCYAN);

	setcolor(YELLOW);
	ellipse(320,360,180,360,22,50);
	arc(320,360,180,360,90);

	line(230,360,230,210);
	line(298,360,298,210);
	line(298,210,230,210);

	line(410,360,410,210);
	line(342,360,342,210);
	line(342,210,410,210);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(231,221,YELLOW);


	ellipse(230,240,270,7,250,120);
	ellipse(370,230,280,5,100,50);
	line(470,225,479,225);

	ellipse(230,310,125,280,100,50);
	ellipse(230,290,135,280,60,30);
	line(170,270,185,270);

	arc(230,0,270,300,320);

	floodfill(229,331,YELLOW);

	floodfill(299,331,YELLOW);

	floodfill(411,320,YELLOW);

	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	line(0,100,100,0);
	line(0,150,150,0);
	line(0,150,0,100);
	line(100,0,150,0);

	line(0,180,180,0);
	line(0,230,230,0);
	line(0,180,0,230);
	line(180,0,230,0);

	setfillstyle(9,BROWN);
	floodfill(1,100,LIGHTCYAN);
	floodfill(1,180,LIGHTCYAN);

	setfillstyle(SOLID_FILL,WHITE);
	puthz(120,90,"账号",24,34,LIGHTBLUE);
	bar(120,120,520,150);

	puthz(120,160,"身份证号",24,34,LIGHTBLUE);
	bar(120,190,520,220);

	puthz(120,230,"密码",24,34,LIGHTBLUE);
	bar(120,260,520,290);
	puthz(320,292,"密码包含的字符至少为",16,18,LIGHTRED);
	setcolor(LIGHTRED);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	outtextxy(502,288,"6");

	puthz(120,300,"确认密码",24,34,LIGHTBLUE);
	bar(120,330,520,360);
	//puthz(360,292,"两次输入密码不一致",16,18,LIGHTRED);

	/*puthz(120,300,"身份证号",24,34,LIGHTBLUE);
	bar(120,330,520,360);*/

	bar(120,400,250,430);
	puthz(129,404,"重置密码",24,30,8);

	bar(390,400,520,430);
	puthz(420,404,"返回",24,46,8);
}