#ifndef _DATA_H_
#define _DATA_H_
//#include"database.h"
typedef struct userinfo
{
	char name[16];		  //�û���
	char id[20];		  // 18λ���֤��
	char password[16];	  // 6-15λ����
	char bank[20];		  // 19λ�����˻�
	char bankpassword[7]; // 6λ�����˻�����
	char health_code[2];  //������״̬  1�������룬2������룬3�������;
	char hesuan[2];
	char mileage[5];
} USER;					  //�û���Ϣ

typedef struct ticket
{
	char number[7];			//�����
	char company[10];		//���չ�˾
	char city1[10];			//������
	char city2[10];			//Ŀ�ĵ�
	char weather1[10];		//����������
	char weather2[10];		//Ŀ�ĵ�����
	char launch_time[6];	//���ʱ��
	char land_time[6];		//����ʱ��
	char tower[8];			//��վ¥
	char economy_price[5];	//���ò�Ʊ��
	char business_price[5]; //�����Ʊ��
	char distance[6];		//����
	char rate[6];			//׼�����
	char date[3];			//����
} Ticket;

typedef struct city
{
	char city_name[10]; //������
	char level[10];		//��������
} City;

typedef struct hotle_info
{
	char hotle_city[5];	  //�Ƶ����ڳ�����
	char hotle_name[10];  //�Ƶ���
	char hotle_class[10]; //��������
	char price[5];		  //����
} Hotle;

typedef struct ticket_hold //������δ���еĻ�Ʊ
{
	char number[7];		//�����
	char company[10];	//���չ�˾
	char city1[10];		//������
	char city2[10];		//Ŀ�ĵ�
	char price[5];		//Ʊ��
	char sort[8];		//���òջ��������
	char distance[6];	//����
	char ticket_num[2]; //��Ʊ��
	char date[3];   //����
} Hold;

typedef struct ticket_histroy //��ʷ��Ʊ��¼
{
	char number[7];	  //�����
	char company[10]; //���չ�˾
	char city1[10];	  //������
	char city2[10];	  //Ŀ�ĵ�
	char price[5];	  //Ʊ��
	char distance[6]; //����
} History;

typedef struct hotle_hold //�Ѿ������ľƵ���Ϣ
{
	char city[5];			//�Ƶ����ڳ���
	char name[10];		//�Ƶ�����
	char price[5];		//����
	char class[10];		//��������
	char day[2];			//��ס������
	char checkin[5];	//������ס������
	char checkout[5]; //�����뿪������
} Live;


#endif