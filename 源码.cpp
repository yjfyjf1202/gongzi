#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include"Tworkers.h"
using namespace std;
void menu()//������
{
 cout<<"***********************************************************************"<<endl;
 cout<<"**------------------------ְ�����ʹ���ϵͳ---------------------------**"<<endl;
 cout<<"***********************************************************************"<<endl;
 cout<<"**                        1. ����ְ����Ϣ                            **"<<endl;
 cout<<"**                        2. ��ʾְ������                            **"<<endl;
    cout<<"**                        3. ɾ��ְ����Ϣ                            **"<<endl;
    cout<<"**                        4. ��ѯְ������                            **"<<endl;
 cout<<"**                        5. �޸�ְ����Ϣ                            **"<<endl;
 cout<<"**                        6. ͳ��ְ����Ϣ                            **"<<endl;
 cout<<"**                        0. �˳�ϵͳ                                **"<<endl;
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
        cout<<"------------------------���������ѡ���Ӧ����-------------------------"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"������˵�ѡ�";
        cin>>a;
        switch(a)
  {
            case 1:system("cls");aa.add();break;
            case 2:system("cls");aa.print();break;
           /* case 3:system("cls");aa.del();break;
            case 4:system("cls");aa.find();break;
            case 5:system("cls");aa.modify();break;*/
           
            case 0:system("cls");printf("*****ллʹ��*****");exit(0);
  }
  system("pause");
  system("cls");
 }
 return 0;
}

