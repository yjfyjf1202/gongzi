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
	float set_salary(){
	cout<<"�������λ����";cin>>gg;
	cout<<"������н������";cin>>xg;
	cout<<"������ְ�����";cin>>zj;
	cout<<"�����뼨Ч����";cin>>jg;
	yf=gg+xg+zj+jg;
	return yf;
	}

	float grsds(){//����˰
	//cout<<"Ӧ������"<<yf;

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
	//cout<<"ʵ������"<<sf;
	return sf;
	};

	float gg,xg,zj,jg,yf,shui,sf,s1;
	
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
	ofile<<worker.num<<"    "<<worker.name<<"    "<<worker.gg<<"    "<<worker.xg;
	ofile<<"    "<<worker.zj<<"    "<<worker.jg<<"    "<<worker.yf<<"    "<<worker.shui<<"    "<<worker.sf;
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
			cout<<"    "<<"ְ������"<<"    "<<"ְ������"<<"    "<<"��λ����"<<"    "<<"н������"
			<<"    "<<"ְ�����"<<"    "<<"��Ч����"<<"    "<<"��������˰"<<"    "
			<<"ʵ������"<<endl;
			cout<<s<<endl;//���ְ����Ϣ
		}
		//cout<<s<<endl;//���ְ����Ϣ
		flag=false;
	}
	if(flag){
		cout<<"û�и�ְ����Ϣ��"<<endl;
	}
};

void Tmanage::modify(){
	Worker_salary worker[100];//��Ŷ�ȡ���ļ�¼
	ifstream ifile("D:\\gz.dat",ios::in);
	if(!ifile){
		cout<<"���ܴ��ļ�"<<endl;
		abort();
	}
	int i;
	cout<<setw(1)<<"ְ������"<<setw(1)<<"ְ������"<<setw(1)<<"��λ����";
	cout<<setw(1)<<"н������"<<setw(1)<<"ְ�����"<<setw(1)<<"��Ч����";
	cout<<setw(1)<<"��������˰"<<setw(1)<<"ʵ������"<<endl;
	for(i=0;i<total;i++){//��ȡ�ļ�����
		ifile>>worker[i].num>>worker[i].name>>worker[i].gg>>worker[i].xg>>worker[i].zj
			>>worker[i].jg>>worker[i].shui>>worker[i].sf;
	
	}
	ifile.close();
	ofstream ofile("D:\\gz.dat",ios::out);
	if(!ifile){
		cout<<"�ļ����ܴ�"<<endl;
		abort();
	}
	bool flag;//���Ա��
	int n=1;
	char nn[20];
	float new_gg,new_xg,new_zj,new_jg;
	while(n){
		cout<<"������Ҫ�޸���Ϣ�Ĺ��ţ�";
		cin>>nn;
		flag=false;
		int a;
		for(int i=0;i<total;i++){
			if(strcmp(nn,worker[i].num)==0){
			 do{
				cout<<"��ѡ��Ҫ�޸ĵ���Ϣ:"<<endl;
				cout<<"****************************************"<<endl;
				cout<<"-----------[1] �޸ĸ�λ����-------------"<<endl;
				cout<<"-----------[2] �޸�н������-------------"<<endl;
				cout<<"-----------[3] �޸�ְ�����-------------"<<endl;
				cout<<"-----------[4] �޸ļ�Ч����-------------"<<endl;
				cout<<"****************************************"<<endl;
				cout<<"��ѡ���Ӧ������Ž��в���:";
				cin>>a;
				if(a==1){
					cout<<"�������µĻ�������";
					cin>>new_gg;
					for(i=0;i<total;i++){							 
						if(strcmp(worker[i].num,nn)==0){
						 worker[i].gg =new_gg;}
									 }
						}
				if(a==2){
					cout<<"�������µ�н������";
					cin>>new_xg;
					for(i=0;i<total;i++){							 
						if(strcmp(worker[i].num,nn)==0){
						 worker[i].xg =new_xg;}
										}
						}
				if(a==3){
					cout<<"�������µ�ְ�����";
					cin>>new_zj;
					for(i=0;i<total;i++){							 
						if(strcmp(worker[i].num,nn)==0){
						 worker[i].zj =new_zj;}
										}
						}
				if(a==4){
					cout<<"�������µļ�Ч����";
					cin>>new_jg;
					for(i=0;i<total;i++){							 
						if(strcmp(worker[i].num,nn)==0){
						 worker[i].jg =new_gg;}
										}
						}
				flag=true;
				}while(a<1&&a>5);
			   if(!flag){//�ж��Ƿ����ְ����Ϣ
                
                    cout<<"��ѯ������ְ����ID���޷��޸ģ������޸��밴1 / �˳��밴0:";
                    cin>>n;
                }
                else{
                
                 cout<<"�����޸��밴1 / �˳��밴0:";
                    cin>>n;
                }

				}//��if������
		
											}//��for������
								}//while(n)������
	for(int j=0;j<total;j++){
		ofile<<setw(1)<<worker[j].num<<setw(1)<<worker[j].name<<setw(1)<<worker[j].gg
			<<setw(1)<<worker[j].xg<<setw(1)<<worker[j].zj<<setw(1)<<worker[j].jg<<endl;
		ofile.close();//�ر��ļ�
	}
			};//modify������

/*void Tmanage::del(){
	Worker_salary worker[100];//��Ŷ�ȡ���ļ�¼
	ifstream ifile("gz.dat",ios::in);
	if(!ifile){
	cout<<"�ļ����ܴ�"<<endl;
	abort();
	}
	cout<<setw(10)<<"ְ������"<<setw(10)<<"ְ������"<<setw(10)<<"��λ����";
	cout<<setw(10)<<"н������"<<setw(10)<<"ְ�����"<<setw(10)<<"��Ч����";
	cout<<setw(10)<<"��������˰"<<setw(10)<<"ʵ������"<<endl;
	for(int i=0;i<total;i++){
	ifile>>worker[i].num>>worker[i].name>>worker[i].gg>>worker[i].xg>>worker[i].zj
			>>worker[i].jg>>worker[i].shui>>worker[i].sf;
	cout<<setw(10)<<worker[i].num<<setw(10)<<worker[i].name<<setw(10)<<worker[i].gg
		<<setw(10)<<worker[i].xg<<setw(10)<<worker[i].zj<<setw(10)<<worker[i].jg
		<<setw(10)<<worker[i].shui<<setw(10)<<worker[i].sf<<endl;
	}//��ȡ�ļ����ݲ�����
	ifile.close();
	int n=1,q;
	while(n){
		ofstream ofile("gz.gat",ios::out);//�ɸ��ǵ���ʽ
		if(!ofile){
		cout<<"�ļ����ܴ�"<<endl;
		abort();
		}
		bool flag;//���Ա��
		char nn[20];
			cout<<"������Ҫɾ����Ա���Ĺ��ţ�";
			cin>>nn;
			flag=false;
			for(int i=0;i<total;i++){
				if(strcmp(nn,worker[i].num)!=0){//������Ҫɾ����ְ��
					ofile<<setw(10)<<worker[i].num<<setw(10)<<worker[i].name<<setw(10)<<worker[i].gg
						<<setw(10)<<worker[i].xg<<setw(10)<<worker[i].zj<<setw(10)<<worker[i].jg
						<<setw(10)<<worker[i].shui<<setw(10)<<worker[i].sf;

				}//if������
			}//for��������
	}//while������
}//del����������
			*/