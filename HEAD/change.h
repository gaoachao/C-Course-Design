#ifndef _CHANGE_H_
#define _CHANGE_H_

void change_main(int *func);                                                         //��������������
int change_complete_judge(char *name, char *id, char *password, char *str, USER *u); //����Ƿ�����޸�����
int name_search(char *name, USER *u, int x, int y, int *i);                          //�����û�������ȡ
int name_id_judge(char *id, USER *u, int x, int y);                                  //�ж��û��������֤�����Ƿ�ƥ��
int change_password_judge(char *password, int x, int y);                             //�ж������Ƿ���ڵ���6λ
int change_confilm_judge(char *password, char *str, int x, int y);                   //�ж�������ȷ�������Ƿ�һ��
void password_write(USER *u, char *password, int i);                                 //д��������
void lightup_change(int x1, int y1, int x2, int y2, int flag);                       //����������水������
void recoverbuttom_change(int x1, int y1, int x2, int y2, int flag);                 //����������水�������ָ�
void change_page(void);                                                              //���Ƹ����������

#endif