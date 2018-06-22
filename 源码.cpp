#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include"Tworkers.h"
using namespace std;

void menu()//主界面
{
 cout<<"***********************************************************************"<<endl;
 cout<<"**------------------------职工工资管理系统---------------------------**"<<endl;
 cout<<"***********************************************************************"<<endl;
 cout<<"**                        1. 添加职工信息                            **"<<endl;
 cout<<"**                        2. 显示职工工资                            **"<<endl;
 cout<<"**                        3. 删除职工信息                            **"<<endl;
 cout<<"**                        4. 查询职工工资                            **"<<endl;
 cout<<"**                        5. 修改职工信息                            **"<<endl;
 cout<<"**                        6. 统计职工信息                            **"<<endl;
 cout<<"**                        7. 浏览职工信息                            **"<<endl;
 cout<<"**                        0. 退出系统                                **"<<endl;
 cout<<"***********************************************************************"<<endl;
}



int main()
{
     Tmanage aa;
     int a;
     while(1)
     {
            menu();
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"------------------------请输入序号选择对应功能-------------------------"<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout << "请输入菜单选项：";
            cin >> a;
            switch(a)
		    {
		        case 1:
				{
				    system("cls");
					aa.add();
					break;
				}
			      case 2:system("cls");aa.print();break;
			    case 5:system("cls");aa.modify();break;
               /* case 3:system("cls");aa.del();break;
                case 4:system("cls");aa.find();break;
			
			    case 6:system("cls");aa.add();break;
			    case 7:system("cls");aa.add();break;
			
                */
             //   case 0:system("cls");printf("*****谢谢使用*****");exit(0);
            }
        system("pause");
        system("cls");
        }
        return 0;
}

