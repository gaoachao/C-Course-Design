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
DESCRIPTION: ��������������
INPUT: *func
RETURN: ��
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

	char name[16];//������û���
	char id[20];//��������֤����
	char password[16];//����
	char str[16];//�ڶ�����������

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

		//�˺���
		if(MouseX>120&&MouseX<520&&MouseY>120&&MouseY<150)
		{
			if(mouse_press(120,120,520,150)==2)//�˺������δ���
			{
				MouseS=2;
				if(num==0&&state1==0)
				{
					lightup_change(120,120,520,150,1);
					num=1;
				}
				continue;
			}
			else if(mouse_press(120,120,520,150)==1)//�˺����������
			{
				lightup_change(120,120,520,150,1);
				memset(name,'\0',sizeof(name));//�û������
				inputadmin(name,120,120,15,7);//�����û���
				if(strlen(name)==0)
				{
					state1=0;
				}
				else state1=1;
			}
		}

		//�������֤����
		if(MouseX>120&&MouseX<520&&MouseY>190&&MouseY<220)
		{
			if(mouse_press(120,190,520,220)==2)//�������֤��δ���
			{
				MouseS=2;
				if(num==0&&state2==0)
				{
					lightup_change(120,190,520,220,1);
					num=1;
				}
				continue;
			}
			else if(mouse_press(120,190,520,220)==1)//���֤�����������
			{
				lightup_change(120,190,520,220,1);
				memset(id,'\0',sizeof(id));//���֤�����
				inputadmin(id,120,190,18,7);//�������֤��
				if(strlen(id)==0)
				{
					state2=0;
				}
				else state2=1;
			}
		}

		//��������
		if(MouseX>120&&MouseX<520&&MouseY>260&&MouseY<290)
		{
			if(mouse_press(120,260,520,290)==2)//�������δ���
			{
				MouseS=2;
				if(num==0&&state3==0)
				{
					lightup_change(120,260,520,290,1);
					num=1;
				}
				continue;
			}
			else if(mouse_press(120,260,520,290)==1)//���������������
			{
				lightup_change(120,260,520,290,1);
				memset(password,'\0',sizeof(password));//ȷ���������
				inputadmin(password,120,260,15,7);//����������
				if(strlen(password)==0)
				{
					state3=0;
				}
				else state3=1;
			}
		}

		//ȷ��������
		if(MouseX>120&&MouseX<520&&MouseY>330&&MouseY<360)
		{
			if(mouse_press(120,330,520,360)==2)//ȷ��������δ���
			{
				MouseS=2;
				if(num==0&&state4==0)
				{
					lightup_change(120,330,520,360,1);
					num=1;
				}
				continue;
			}
			else if(mouse_press(120,330,520,360)==1)//ȷ���������������
			{
				lightup_change(120,330,520,360,1);
				memset(str,'\0',sizeof(str));//ȷ���������
				inputadmin(str,120,330,15,7);//����ȷ������
				if(strlen(str)==0)
				{
					state4=0;
				}
				else state4=1;
			}
		}

		//����������������Ƿ���ͬ
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

		//���������
		if(MouseX>120&&MouseX<400&&MouseY>250&&MouseY<430)
		{
			if(mouse_press(120,400,250,430)==2)//���������δ���
			{
				MouseS=1;
				if(num==0)
				{
					lightup_change(120,400,250,430,2);
					num=2;
				}
				continue;
			}
			else if(mouse_press(120,400,250,430)==1)//������������
			{
				lightup_change(120,400,250,430,2);
				if(change_complete_judge(name,id,password,str,u)==1)
				{
					puthz(230,380,"��������ɹ�",24,30,GREEN);	
					delay(3000);
					*func=0;
					return;
				}
				else continue;

			}
		}

		//���ؼ�
		if(MouseX>390&&MouseX<520&&MouseY>250&&MouseY<430)
		{
			if(mouse_press(390,400,520,430)==2)//���ؼ�δ���
			{
				MouseS=1;
				if(num==0)
				{
					lightup_change(390,400,520,430,3);
					num=3;
				}
				continue;
			}
			else if(mouse_press(390,400,520,430)==1)//���ؼ����
			{
				lightup_change(390,400,520,430,3);
				*func=0;
				return;
			}
		}

		//�˳���
		if(MouseX>595&&MouseX<640&&MouseY>0&&MouseY<20)
		{
			if(mouse_press(595,0,640,20)==1){
			    *func=1;
	    		return;
			}
		}

		//����򼰰��������ָ�
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
DESCRIPTION: ����Ƿ�����޸�����
INPUT: *name,*id,*password,*str,*u
RETURN: 1(�����޸�����)/0(�������޸�����)
***********************************/
int change_complete_judge(char *name,char *id,char *password,char*str,USER *u)
{
	int state=0;
	int state1=0;//�û�����Ϣ���
	int state2=0;//���֤����Ϣ���
	int state3=0;//������Ϣ���/
	int state4=0;//ȷ��������Ϣ���
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
DESCRIPTION: д��������
INPUT: *u,*password,i
RETURN: ��
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
DESCRIPTION: �����û���
INPUT: *name,*u,x,y
RETURN: 1(�ҵ���Ҫ�޸ĵ��û�)/0(δ�ҵ�)
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
	len=ftell(fp)/sizeof(USER);//�û�����
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
		if(strcmp(name,utemp->name)==0)//�ҵ�ƥ����û�
		{

           // printf("%s %s\n",utemp->name,utemp->id);

			//�ڵ���������
			clrmous(MouseX,MouseY);
        	delay(10);
	    	setfillstyle(SOLID_FILL,LIGHTCYAN);
    		bar(x+2,y,x+2+130,y+30);

			//���Թ�
			setcolor(GREEN);
	    	setlinestyle(SOLID_LINE, 0, 3);
     		line(x+2 + 3, y + 10, x+2 + 13, y + 20);
    		line(x+2 + 13, y + 20, x+2 + 23, y);

			//�������û���Ϣ
			strcpy(u->name,utemp->name);
			strcpy(u->password,utemp->password);
			strcpy(u->id,utemp->id);
			strcpy(u->bank,utemp->bank);
			strcpy(u->bankpassword,utemp->bankpassword);
		   //	strcpy(u->nextUser,utemp->nextUser);

		   *i=j;

			//�˳�
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
	if(j==len&&strlen(name)!=0)//δ�ҵ��û�
	{
		//�ڵ���������
			clrmous(MouseX,MouseY);
			delay(10);
			setfillstyle(SOLID_FILL,LIGHTCYAN);
			bar(x+2,y,x+2+120,y+30);

			puthz(x+2,y,"�û���������",16,18,RED);

			//�˳�
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
DESCRIPTION: �ж��û��������֤�����Ƿ�ƥ��
INPUT: jd,*u,x,y
RETURN: 1(ƥ��)/0(��ƥ��)
***********************************/
int name_id_judge(char *id,USER *u,int x,int y)
{
	int flag=strcmp(id,u->id);
	if(flag==0)//�û��������֤����ƥ��
	{
		//printf("flag=%d\n",flag);
		//�ڵ���������
		clrmous(MouseX,MouseY);
		delay(10);
		setfillstyle(SOLID_FILL,LIGHTCYAN);
		bar(x+2,y,x+2+120,y+30);

		//���Թ�
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x+2 + 3, y + 10, x+2 + 13, y + 20);
		line(x+2 + 13, y + 20, x+2 + 23, y);

		return 1;
	}
	else 
	{
		//printf("flag=%d\n",flag);
		//�ڵ���������
		clrmous(MouseX,MouseY);
        delay(10);
	    setfillstyle(SOLID_FILL,LIGHTCYAN);
    	bar(x+2,y,x+2+120,y+30);

		puthz(x+2,y,"���֤�Ŵ���",16,18,RED);
		return 0;
	}
}

/***********************************
FUNCTION: change_password_judge
DESCRIPTION: �ж������Ƿ���ڵ���6λ
INPUT: *password,x,y
RETURN: 1/0
***********************************/
int change_password_judge(char *password,int x,int y)
{
	int len=strlen(password);
	if(len>=6)//������ڵ���6λ
	{
		//�ڵ���������
		clrmous(MouseX,MouseY);
        delay(10);
	    setfillstyle(SOLID_FILL,LIGHTCYAN);
    	bar(x+2,y,x+2+120,y+30);

		//���Թ�
		setcolor(GREEN);
	    setlinestyle(SOLID_LINE, 0, 3);
    	line(x+2 + 3, y + 10, x+2 + 13, y + 20);
    	line(x+2 + 13, y + 20, x+2 + 23, y);

		return 1;
	}
	else if(len>0&&len<6)
	{
		//�ڵ���������
		clrmous(MouseX,MouseY);
        delay(10);
	    setfillstyle(SOLID_FILL,LIGHTCYAN);
    	bar(x+2,y,x+2+120,y+30);

		puthz(x+2,y,"�������",16,18,RED);
		return 0;
	}
}

/***********************************
FUNCTION: change_confilm_judge
DESCRIPTION: �ж�������ȷ�������Ƿ�һ��
INPUT: *password,str,x,y
RETURN: 1/0
***********************************/
int change_confilm_judge(char *password,char *str,int x,int y)
{
	if(confirm_password(password,str)==1&&strlen(str)!=0)//������ȷ������һ��
	{
		//�ڵ���������
		clrmous(MouseX,MouseY);
        delay(10);
	    setfillstyle(SOLID_FILL,LIGHTCYAN);
		bar(x+2,y,x+2+120,y+30);

		//���Թ�
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
DESCRIPTION: ����������水ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_change(int x1,int y1,int x2,int y2,int flag)
{
	clrmous(MouseX,MouseY);
	delay(10);
	setcolor(LIGHTRED);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, LIGHTGRAY);
	
	bar(x1,y1,x2,y2);//����ڲ�
	rectangle(x1-1,y1-1,x2+1,y2+1);//���߿�
	switch (flag)
	{
	case 1:break;

	case 2:
	{
		puthz(129,404,"��������",24,30,RED);
		break;
	}

	case 3:
	{
		puthz(420,404,"����",24,46,RED);
		break;
	}

	default:
		printf("something wrong in loghtup_register\n");
		break;
	}
}

/***********************************
FUNCTION: recoverbuttom_change
DESCRIPTION: ע����水ť�����ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
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
		puthz(129,404,"��������",24,30,DARKGRAY);
		break;
	}

	case 3:
	{
		puthz(420,404,"����",24,46,DARKGRAY);
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
DESCRIPTION: ���Ƹ����������
INPUT: ��
RETURN: ��
***********************************/
void change_page(void)
{
	//������
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
	puthz(120,90,"�˺�",24,34,LIGHTBLUE);
	bar(120,120,520,150);

	puthz(120,160,"���֤��",24,34,LIGHTBLUE);
	bar(120,190,520,220);

	puthz(120,230,"����",24,34,LIGHTBLUE);
	bar(120,260,520,290);
	puthz(320,292,"����������ַ�����Ϊ",16,18,LIGHTRED);
	setcolor(LIGHTRED);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	outtextxy(502,288,"6");

	puthz(120,300,"ȷ������",24,34,LIGHTBLUE);
	bar(120,330,520,360);
	//puthz(360,292,"�����������벻һ��",16,18,LIGHTRED);

	/*puthz(120,300,"���֤��",24,34,LIGHTBLUE);
	bar(120,330,520,360);*/

	bar(120,400,250,430);
	puthz(129,404,"��������",24,30,8);

	bar(390,400,520,430);
	puthz(420,404,"����",24,46,8);
}