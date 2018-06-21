#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
static int total=0;//职工总数
class workers{
public:
    void set_workers(){
	cout<<"请输入员工编号"; cin>>num;
	cout<<"请输入员工姓名"; cin>>name;
	}

char num[10],name[10];
//float gg,xg,zj,jg,yf,shui,sf;

};

class salary{
public:
	void set_salary(){
	cout<<"请输入岗位工资";cin>>gg;
	cout<<"请输入薪级工资";cin>>xg;
	cout<<"请输入职务津贴";cin>>zj;
	cout<<"请输入绩效工资";cin>>jg;
	yf=gg+xg+zj+jg;
	}
	void grsds(){//计算税
	cout<<"应发工资"<<yf;

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
	cout<<"实发工资"<<sf;
	
	};

	double gg,xg,zj,jg,yf,shui,sf,s1;
};

class Worker_salary : public workers,public salary{
	public:
     friend class Tmanage;//作为友元函数访问 
     void set_work_salary()
        {
       set_workers();
       set_salary();
  }
};

class Tmanage
{
 public:
  int add();//输入职工的个人信息
  void print();//输出职工信息
  void modify();//修改职工信息
  void find();//查找职工信息
  void del();//删除职工信息
  void read();//读取职工工资
  void list();//浏览职工工资数据

  Worker_salary worker;
};

int Tmanage::add(){
ofstream ofile("D:\\gz.dat",ios::app);
if(!ofile){
cout<<"文件不能打开"<<endl;
return 0;
}
int n=1;
while(n){
	worker.set_work_salary();//输入职工信息
	ofile<<setw(10)<<worker.num<<setw(10)<<worker.name<<setw(10)<<worker.gg<<setw(10)<<worker.xg;
	ofile<<setw(10)<<worker.zj<<setw(10)<<worker.jg<<setw(10)<<worker.yf<<setw(10)<<worker.shui<<setw(10)<<worker.sf;
	cout<<"输入成功"<<endl;
	total++;
	cout<<"继续输入请按1/退出请按0"<<endl;
	cin>>n;
}
ofile.close();
return 0;
}

void Tmanage::print(){
	ifstream ifile("D:\\gz.dat",ios::in);
	if(!ifile){
		cout<<"文件不能打开"<<endl;
		abort();
	}
	bool flag=true;//做个标记
	string s;
	
	while(getline(ifile,s)){
		if(flag){
			cout<<"职工工号"<<" "<<"职工姓名"<<" "<<"岗位工资"<<" "<<"薪级工资";
			cout<<" "<<"职务津贴"<<" "<<"绩效工资"<<" "<<"应发工资"<<" "<<"个人所得税";
			cout<<"实发工资"<<endl;
		}
		cout<<s<<endl;//输出职工信息
		flag=false;
	}
	if(flag){
		cout<<"没有该职工信息！"<<endl;
	}
};

/*void modify(){
	workers worker[100];//存放读取到的记录
	ifstream ifile("gz.gat",ios::in);
	if(!ifile){
		cout<<"不能打开文件"<<endl;
		abort();
	}
	cout<<setw(10)<<"职工工号"<<setw(10)<<"职工姓名"<<setw(10)<<"岗位工资";
	cout<<setw(10)<<"薪级工资"<<setw(10)<<"职务工资"<<setw(10)<<"绩效工资";
	cout<<setw(10)<<"个人所得税"<<setw(10)<<"实发工资"<<endl;
	/*for(int i,i<total,i++){
	
	}
}*/