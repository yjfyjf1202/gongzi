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
	float set_salary(){
	cout<<"请输入岗位工资";cin>>gg;
	cout<<"请输入薪级工资";cin>>xg;
	cout<<"请输入职务津贴";cin>>zj;
	cout<<"请输入绩效工资";cin>>jg;
	yf=gg+xg+zj+jg;
	return yf;
	}

	float grsds(){//计算税
	//cout<<"应发工资"<<yf;

	if(yf>3500){
		s1=yf-3500;
		if(s1<500){
		shui=s1*(float)0.05;
		}
		if(s1>500||s1<2000){
			shui=s1*0.1;
		}
		if(s1>2000||s1<5000){
			shui=s1*(float)0.15;
		}
		if(s1>5000||s1<20000){
			shui=s1*0.2;
		}
		if(s1>20000||s1<40000){
			shui=s1*(float)0.25;
		}
		if(s1>40000||s1<60000){
			shui=s1*(float)0.3;
		}
		if(s1>60000||s1<80000){
			shui=s1*(float)0.35;
		}
		if(s1>80000||s1<100000){
			shui=s1*(float)0.4;
		}
		if(s1>100000){
			shui=s1*(float)0.45;
		}
		return shui;
	}
	else{shui=0;return shui;}
	sf=yf-shui;
	//cout<<"实发工资"<<sf;
	return sf;
	};

	float gg,xg,zj,jg,yf,shui,sf,s1;
	
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
	ofile<<worker.num<<"    "<<worker.name<<"    "<<worker.gg<<"    "<<worker.xg;
	ofile<<"    "<<worker.zj<<"    "<<worker.jg<<"    "<<worker.yf<<"    "<<worker.shui<<"    "<<worker.sf;
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
			cout<<"    "<<"职工工号"<<"    "<<"职工姓名"<<"    "<<"岗位工资"<<"    "<<"薪级工资"
			<<"    "<<"职务津贴"<<"    "<<"绩效工资"<<"    "<<"个人所得税"<<"    "
			<<"实发工资"<<endl;
			cout<<s<<endl;//输出职工信息
		}
		//cout<<s<<endl;//输出职工信息
		flag=false;
	}
	if(flag){
		cout<<"没有该职工信息！"<<endl;
	}
};

void Tmanage::modify(){
	Worker_salary worker[100];//存放读取到的记录
	ifstream ifile("D:\\gz.dat",ios::in);
	if(!ifile){
		cout<<"不能打开文件"<<endl;
		abort();
	}
	int i;
	cout<<setw(1)<<"职工工号"<<setw(1)<<"职工姓名"<<setw(1)<<"岗位工资";
	cout<<setw(1)<<"薪级工资"<<setw(1)<<"职务津贴"<<setw(1)<<"绩效工资";
	cout<<setw(1)<<"个人所得税"<<setw(1)<<"实发工资"<<endl;
	for(i=0;i<total;i++){//提取文件内容
		ifile>>worker[i].num>>worker[i].name>>worker[i].gg>>worker[i].xg>>worker[i].zj
			>>worker[i].jg>>worker[i].shui>>worker[i].sf;
	
	}
	ifile.close();
	ofstream ofile("D:\\gz.dat",ios::out);
	if(!ifile){
		cout<<"文件不能打开"<<endl;
		abort();
	}
	bool flag;//标记员工
	int n=1;
	char nn[20];
	float new_gg,new_xg,new_zj,new_jg;
	while(n){
		cout<<"请输入要修改信息的工号：";
		cin>>nn;
		flag=false;
		int a;
		for(int i=0;i<total;i++){
			if(strcmp(nn,worker[i].num)==0){
			 do{
				cout<<"请选择要修改的信息:"<<endl;
				cout<<"****************************************"<<endl;
				cout<<"-----------[1] 修改岗位工资-------------"<<endl;
				cout<<"-----------[2] 修改薪级工资-------------"<<endl;
				cout<<"-----------[3] 修改职务津贴-------------"<<endl;
				cout<<"-----------[4] 修改绩效工资-------------"<<endl;
				cout<<"****************************************"<<endl;
				cout<<"请选择对应数字序号进行操作:";
				cin>>a;
				if(a==1){
					cout<<"请输入新的基本工资";
					cin>>new_gg;
					for(i=0;i<total;i++){							 
						if(strcmp(worker[i].num,nn)==0){
						 worker[i].gg =new_gg;}
									 }
						}
				if(a==2){
					cout<<"请输入新的薪级工资";
					cin>>new_xg;
					for(i=0;i<total;i++){							 
						if(strcmp(worker[i].num,nn)==0){
						 worker[i].xg =new_xg;}
										}
						}
				if(a==3){
					cout<<"请输入新的职务津贴";
					cin>>new_zj;
					for(i=0;i<total;i++){							 
						if(strcmp(worker[i].num,nn)==0){
						 worker[i].zj =new_zj;}
										}
						}
				if(a==4){
					cout<<"请输入新的绩效工资";
					cin>>new_jg;
					for(i=0;i<total;i++){							 
						if(strcmp(worker[i].num,nn)==0){
						 worker[i].jg =new_gg;}
										}
						}
				flag=true;
				}while(a<1&&a>5);
			   if(!flag){//判断是否存在职工信息
                
                    cout<<"查询不到该职工的ID，无法修改！继续修改请按1 / 退出请按0:";
                    cin>>n;
                }
                else{
                
                 cout<<"继续修改请按1 / 退出请按0:";
                    cin>>n;
                }

				}//大if的括号
		
											}//大for的括号
								}//while(n)的括号
	for(int j=0;j<total;j++){
		ofile<<setw(1)<<worker[j].num<<setw(1)<<worker[j].name<<setw(1)<<worker[j].gg
			<<setw(1)<<worker[j].xg<<setw(1)<<worker[j].zj<<setw(1)<<worker[j].jg<<endl;
		ofile.close();//关闭文件
	}
			};//modify的括号

/*void Tmanage::del(){
	Worker_salary worker[100];//存放读取到的记录
	ifstream ifile("gz.dat",ios::in);
	if(!ifile){
	cout<<"文件不能打开"<<endl;
	abort();
	}
	cout<<setw(10)<<"职工工号"<<setw(10)<<"职工姓名"<<setw(10)<<"岗位工资";
	cout<<setw(10)<<"薪级工资"<<setw(10)<<"职务津贴"<<setw(10)<<"绩效工资";
	cout<<setw(10)<<"个人所得税"<<setw(10)<<"实发工资"<<endl;
	for(int i=0;i<total;i++){
	ifile>>worker[i].num>>worker[i].name>>worker[i].gg>>worker[i].xg>>worker[i].zj
			>>worker[i].jg>>worker[i].shui>>worker[i].sf;
	cout<<setw(10)<<worker[i].num<<setw(10)<<worker[i].name<<setw(10)<<worker[i].gg
		<<setw(10)<<worker[i].xg<<setw(10)<<worker[i].zj<<setw(10)<<worker[i].jg
		<<setw(10)<<worker[i].shui<<setw(10)<<worker[i].sf<<endl;
	}//提取文件内容并保存
	ifile.close();
	int n=1,q;
	while(n){
		ofstream ofile("gz.gat",ios::out);//可覆盖的形式
		if(!ofile){
		cout<<"文件不能打开"<<endl;
		abort();
		}
		bool flag;//标记员工
		char nn[20];
			cout<<"请输入要删除的员工的工号：";
			cin>>nn;
			flag=false;
			for(int i=0;i<total;i++){
				if(strcmp(nn,worker[i].num)!=0){//不是所要删除的职工
					ofile<<setw(10)<<worker[i].num<<setw(10)<<worker[i].name<<setw(10)<<worker[i].gg
						<<setw(10)<<worker[i].xg<<setw(10)<<worker[i].zj<<setw(10)<<worker[i].jg
						<<setw(10)<<worker[i].shui<<setw(10)<<worker[i].sf;

				}//if的括号
			}//for语句的括号
	}//while的括号
}//del函数的括号
			*/