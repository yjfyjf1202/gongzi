#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
static int total=0;//ְ������
class workers{
public:
    void set_workers(){
	cout<<"������Ա�����"; cin>>num;
	cout<<"������Ա������"; cin>>name;
	}

char num[10],name[10];
//float gg,xg,zj,jg,yf,shui,sf;

};

class salary{
public:
	void set_salary(){
	cout<<"�������λ����";cin>>gg;
	cout<<"������н������";cin>>xg;
	cout<<"������ְ�����";cin>>zj;
	cout<<"�����뼨Ч����";cin>>jg;
	yf=gg+xg+zj+jg;
	}
	void grsds(){//����˰
	cout<<"Ӧ������"<<yf;

	if(yf>3500){
		s1=yf-3500;
		if(s1<500){
		shui=s1*0.05;
		}
		if(s1>500||s1<2000){
			shui=s1*0.1;
		}
		if(s1>2000||s1<5000){
			shui=s1*0.15;
		}
		if(s1>5000||s1<20000){
			shui=s1*0.2;
		}
		if(s1>20000||s1<40000){
			shui=s1*0.25;
		}
		if(s1>40000||s1<60000){
			shui=s1*0.3;
		}
		if(s1>60000||s1<80000){
			shui=s1*0.35;
		}
		if(s1>80000||s1<100000){
			shui=s1*0.4;
		}
		if(s1>100000){
			shui=s1*0.45;
		}
	}
	else{shui=0;}
	sf=yf-shui;
	cout<<"ʵ������"<<sf;
	
	};

	double gg,xg,zj,jg,yf,shui,sf,s1;
};

class Worker_salary : public workers,public salary{
	public:
     friend class Tmanage;//��Ϊ��Ԫ�������� 
     void set_work_salary()
        {
       set_workers();
       set_salary();
  }
};

class Tmanage
{
 public:
  int add();//����ְ���ĸ�����Ϣ
  void print();//���ְ����Ϣ
  void modify();//�޸�ְ����Ϣ
  void find();//����ְ����Ϣ
  void del();//ɾ��ְ����Ϣ
  void read();//��ȡְ������
  void list();//���ְ����������

  Worker_salary worker;
};

int Tmanage::add(){
ofstream ofile("D:\\gz.dat",ios::app);
if(!ofile){
cout<<"�ļ����ܴ�"<<endl;
return 0;
}
int n=1;
while(n){
	worker.set_work_salary();//����ְ����Ϣ
	ofile<<setw(10)<<worker.num<<setw(10)<<worker.name<<setw(10)<<worker.gg<<setw(10)<<worker.xg;
	ofile<<setw(10)<<worker.zj<<setw(10)<<worker.jg<<setw(10)<<worker.yf<<setw(10)<<worker.shui<<setw(10)<<worker.sf;
	cout<<"����ɹ�"<<endl;
	total++;
	cout<<"���������밴1/�˳��밴0"<<endl;
	cin>>n;
}
ofile.close();
return 0;
}

void Tmanage::print(){
	ifstream ifile("D:\\gz.dat",ios::in);
	if(!ifile){
		cout<<"�ļ����ܴ�"<<endl;
		abort();
	}
	bool flag=true;//�������
	string s;
	
	while(getline(ifile,s)){
		if(flag){
			cout<<"ְ������"<<" "<<"ְ������"<<" "<<"��λ����"<<" "<<"н������";
			cout<<" "<<"ְ�����"<<" "<<"��Ч����"<<" "<<"Ӧ������"<<" "<<"��������˰";
			cout<<"ʵ������"<<endl;
		}
		cout<<s<<endl;//���ְ����Ϣ
		flag=false;
	}
	if(flag){
		cout<<"û�и�ְ����Ϣ��"<<endl;
	}
};

/*void modify(){
	workers worker[100];//��Ŷ�ȡ���ļ�¼
	ifstream ifile("gz.gat",ios::in);
	if(!ifile){
		cout<<"���ܴ��ļ�"<<endl;
		abort();
	}
	cout<<setw(10)<<"ְ������"<<setw(10)<<"ְ������"<<setw(10)<<"��λ����";
	cout<<setw(10)<<"н������"<<setw(10)<<"ְ����"<<setw(10)<<"��Ч����";
	cout<<setw(10)<<"��������˰"<<setw(10)<<"ʵ������"<<endl;
	/*for(int i,i<total,i++){
	
	}
}*/