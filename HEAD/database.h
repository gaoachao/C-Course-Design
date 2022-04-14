#ifndef _DATA_H_
#define _DATA_H_
//#include"database.h"
typedef struct userinfo
{
	char name[16];		  //用户名
	char id[20];		  // 18位身份证明
	char password[16];	  // 6-15位密码
	char bank[20];		  // 19位银行账户
	char bankpassword[7]; // 6位银行账户密码
	char health_code[2];  //健康码状态  1代表绿码，2代表黄码，3代表红码;
	char hesuan[2];
	char mileage[5];
} USER;					  //用户信息

typedef struct ticket
{
	char number[7];			//航班号
	char company[10];		//航空公司
	char city1[10];			//出发地
	char city2[10];			//目的地
	char weather1[10];		//出发地天气
	char weather2[10];		//目的地天气
	char launch_time[6];	//起飞时间
	char land_time[6];		//到达时间
	char tower[8];			//航站楼
	char economy_price[5];	//经济舱票价
	char business_price[5]; //商务舱票价
	char distance[6];		//航程
	char rate[6];			//准点概率
	char date[3];			//日期
} Ticket;

typedef struct city
{
	char city_name[10]; //城市名
	char level[10];		//风险评估
} City;

typedef struct hotle_info
{
	char hotle_city[5];	  //酒店所在城市名
	char hotle_name[10];  //酒店名
	char hotle_class[10]; //房间类型
	char price[5];		  //房价
} Hotle;

typedef struct ticket_hold //持有且未出行的机票
{
	char number[7];		//航班号
	char company[10];	//航空公司
	char city1[10];		//出发地
	char city2[10];		//目的地
	char price[5];		//票价
	char sort[8];		//经济舱还是商务舱
	char distance[6];	//航程
	char ticket_num[2]; //购票数
	char date[3];   //日期
} Hold;

typedef struct ticket_histroy //历史购票记录
{
	char number[7];	  //航班号
	char company[10]; //航空公司
	char city1[10];	  //出发地
	char city2[10];	  //目的地
	char price[5];	  //票价
	char distance[6]; //航程
} History;

typedef struct hotle_hold //已经订购的酒店信息
{
	char city[5];			//酒店所在城市
	char name[10];		//酒店名字
	char price[5];		//房价
	char class[10];		//房间类型
	char day[2];			//居住的天数
	char checkin[5];	//办理入住的日期
	char checkout[5]; //办理离开的日期
} Live;


#endif