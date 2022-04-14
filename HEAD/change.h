#ifndef _CHANGE_H_
#define _CHANGE_H_

void change_main(int *func);                                                         //重置密码主函数
int change_complete_judge(char *name, char *id, char *password, char *str, USER *u); //检测是否可以修改密码
int name_search(char *name, USER *u, int x, int y, int *i);                          //搜索用户名并读取
int name_id_judge(char *id, USER *u, int x, int y);                                  //判断用户名和身份证号码是否匹配
int change_password_judge(char *password, int x, int y);                             //判断密码是否大于等于6位
int change_confilm_judge(char *password, char *str, int x, int y);                   //判断密码与确认密码是否一致
void password_write(USER *u, char *password, int i);                                 //写入新密码
void lightup_change(int x1, int y1, int x2, int y2, int flag);                       //重置密码界面按键点亮
void recoverbuttom_change(int x1, int y1, int x2, int y2, int flag);                 //重置密码界面按键点亮恢复
void change_page(void);                                                              //绘制更改密码界面

#endif