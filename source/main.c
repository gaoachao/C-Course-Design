#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <graphics.h>
#include "mouse.h"
#include "hz.h"
#include "login.h"
#include "register.h"
#include "change.h"
#include "change2.h"
#include "welcome.h"
#include "buypage.h"
#include "database.h"
#include "queue.h"
#include "purchase.h"
#include "prevent.h"
#include "userpage.h"
#include "reserve.h"
#include "dynamic.h"
#include "flgstate.h"
#include "booked.h"
#include "mycard.h"
#include "cardch.h"
#include "up.h"
#include "upload.h"
#include "scanpay.h"
#include "payment.h"

int main()
{
	int gd = VGA;
	int gm = VGAHI;
	int func = 0;
	int flag = 2;

	USER u;
	Ticket t;
	Hotle h;
	Live L;

	initgraph(&gd, &gm, "C:\\code\\BGI");
	welcome_page();
	// detail_consult_draw();

	delay(500);

	mouseinit();
	delay(1000);
	while (1)
	{
		switch (func)
		{
		case 0: //��¼
		{
			//htinfo_main(&func, &u, &L);
			login_main(&func, &u);
			break;
		}

		case 1:
			exit(0); //�˳�
			break;

		case 2: //ע��
		{
			register_main(&func, &u);
			break;
		}

		case 3: //�޸�����
		{
			change_main(&func);
			break;
		}

		case 4: //��Ʊ��ʾ����
		{
			buypage_main(&func, &t);
			break;
		}
		case 5: //������Ϣ��ʾҳ��
		{
			userpage_main(&func, &u);
			break;
		}
		case 6: //�����޸Ľ���
		{
			change2_main(&func, &u);
			break;
		}
		case 7: //�Ƶ��ѯ����
		{
			prevent_main(&func, &u);
			break;
		}
		case 8: //������ؽ���
		{
			prevent_main(&func, &u);
			break;
		}

		case 9: //��Ʊ��Ϣȷ�Ͻ���
		{
			purchace_confirm_main(&func, &u, t);
			break;
		}

		case 10: //��Ʊ����
		{

			purchace_main(&func, u, t);
			break;
		}
		case 11: //�Ƶ�Ԥ������
		{
			hotlereserve_main(&func, &h);
			break;
		}
		case 12: //�Ƶ�֧������
		{
			booked_main(&func, &u, &h, &L);
			break;
		}
		case 13: // �ҵĿ�������
		{
			mycard_main(&func, &u);
			break;
		}
		case 14: //���п��޸Ľ���
		{
			cardchange_main(&func, &u);
			break;
		}
		case 15: //��̬��ѯ����
		{
			dynamic_main1(&func);
			break;
		}
		case 16:
		{
			dynamic_main2(&func);
			break;
		}
		case 17: //ʵʱλ�ò�ѯ
		{
			state_consult_main(&func, &t, &flag);
			break;
		}
		case 18: //�Ƶ�֧������
		{
			payment_main(&func, &u, &L);
			break;
		}
		case 19: //�Ƶ�ɨ��֧������
		{
			scanpay_main(&func, &u, &L);
			break;
		}
		case 20: //�������ϴ�
		{
			upload_main(&func, &u);
			break;
		}
		case 21: //��ʾ������
		{
			up_main(&func, &u);
			break;
		}
		case 22: //ʵʱλ����ϸ��Ϣ
		{
			detail_consult_main(&func, t, flag);
			break;
		}
		case 23: //�Ѷ����Ƶ���Ϣ��ѯ
		{
			htinfo_main(&func, &u, &L);
			break;
		}
		default:
		{
			break;
		}
		}
	}
}