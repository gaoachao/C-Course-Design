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
		case 0: //登录
		{
			//htinfo_main(&func, &u, &L);
			login_main(&func, &u);
			break;
		}

		case 1:
			exit(0); //退出
			break;

		case 2: //注册
		{
			register_main(&func, &u);
			break;
		}

		case 3: //修改密码
		{
			change_main(&func);
			break;
		}

		case 4: //机票显示界面
		{
			buypage_main(&func, &t);
			break;
		}
		case 5: //个人信息显示页面
		{
			userpage_main(&func, &u);
			break;
		}
		case 6: //密码修改界面
		{
			change2_main(&func, &u);
			break;
		}
		case 7: //酒店查询界面
		{
			prevent_main(&func, &u);
			break;
		}
		case 8: //疫情防控界面
		{
			prevent_main(&func, &u);
			break;
		}

		case 9: //机票信息确认界面
		{
			purchace_confirm_main(&func, &u, t);
			break;
		}

		case 10: //购票界面
		{

			purchace_main(&func, u, t);
			break;
		}
		case 11: //酒店预订界面
		{
			hotlereserve_main(&func, &h);
			break;
		}
		case 12: //酒店支付界面
		{
			booked_main(&func, &u, &h, &L);
			break;
		}
		case 13: // 我的卡包界面
		{
			mycard_main(&func, &u);
			break;
		}
		case 14: //银行卡修改界面
		{
			cardchange_main(&func, &u);
			break;
		}
		case 15: //动态查询界面
		{
			dynamic_main1(&func);
			break;
		}
		case 16:
		{
			dynamic_main2(&func);
			break;
		}
		case 17: //实时位置查询
		{
			state_consult_main(&func, &t, &flag);
			break;
		}
		case 18: //酒店支付结算
		{
			payment_main(&func, &u, &L);
			break;
		}
		case 19: //酒店扫码支付结算
		{
			scanpay_main(&func, &u, &L);
			break;
		}
		case 20: //健康码上传
		{
			upload_main(&func, &u);
			break;
		}
		case 21: //显示健康码
		{
			up_main(&func, &u);
			break;
		}
		case 22: //实时位置详细信息
		{
			detail_consult_main(&func, t, flag);
			break;
		}
		case 23: //已订购酒店信息查询
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