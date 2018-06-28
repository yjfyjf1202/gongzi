#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
static int total=0;
typedef struct zggz
{
	char ID[10];  //员工工号
	char name[20];//员工姓名
	float gg,xg,zj,jg,yf,tax,sf,s1;
}worker;

int j=0;
char k;
FILE *fp;
//FILE *fr;

void Input();   //
void Add();     //
void find();    //
void write();   // 保存数据
void modify();  //
void Del();
void print();     //

worker wrk[50];
int main()   //主界面系统
{
	char ch;
	system("cls");
    printf("\n\t\t\t\t职工工资系统\n\n");
    printf("\n\t\t\t\t班级：\n");
	printf("\n\n\t\t\t\t制作人：\n");
	printf("\n\n\t\t\t\t学号：n\n\n");
	system("pause");
	system("cls");

	do
	{
	     printf ("\n\t\t\t欢迎进入职工管理系统\n\n\n");
         printf ("\n\t\t\t 1.输入职工信息\n");
	     printf ("\n\t\t\t 2.更改职工信息\n");
    	 printf ("\n\t\t\t 3.删除职工信息\n");
		 printf ("\n\t\t\t 4.查询职工工资\n");
		 printf ("\n\t\t\t 5.保存职工信息\n");
		 printf ("\n\t\t\t 6.输入职工信息\n");
	     printf ("\n\t\t\t 0.退出职工管理系统\n");
		 printf ("\n\n\n请输入你需要选项的数字：");
		 scanf("%d", &ch);
		 switch(ch)
		 {
		// case 6:system("cls");Input();break;
		 case 1:system("cls");Add();break;
		 case 2:system("cls");modify();break;
		 case 3:system("cls");Del();break;
		 case 4:system("cls");find();break;
		 case 5:system("cls");write();break;
		 case 0:system("cls");printf("\t\t感谢使用职工管理系统\n");exit(0);
		 default:printf("输入有误，请在数字0—6之间输入\n");
		 }
	}while(1);
	fflush(stdin);
	return 0;
}

/*void Input()   //输入职工信息
{
	
	do
	{
	     printf("\n\t\t\t请输入职工的信息：\n");
		 printf("\n\t\t\t职工工号：");
	     scanf("%s", &wrk[j].ID);
		 printf("\n\t\t\t职工姓名：");
		 scanf("%s", wrk[j].name);
		 printf("\n\t\t\t岗位工资：");
		 scanf("%f", &wrk[j].gg);
		 printf("\n\t\t\t薪级工资：");
		 scanf("%f", &wrk[j].xg);
		 printf("\n\t\t\t职务津贴：");
		 scanf("%f", &wrk[j].zj);
		 printf("\n\t\t\t绩效工资：");
		 scanf("%f", &wrk[j].jg);

		 wrk[j].yf = wrk[j].gg + wrk[j].xg + wrk[j].zj+wrk[j].jg;
         printf("\n\t\t\t职工实际工资：%d\n", wrk[j].yf);
		 j++;
		 total=j;
		  printf("\n\n\n\n是否继续？\n是请按1;否请按0.\n\n请选择：");
		  fflush(stdin);
		 while(1)
		 {
			 fflush(stdin);
	         scanf("%c", &k);
		     if(k == '0' || k == '1')	 
			     break;
	         printf("输入有误\n请重新输入：");
		 }
		
	}while(k=='1');
	fflush(stdin);
	return;
}*/
void grsds(){
	if (wrk[j].yf>3500){
		wrk[j].s1 = wrk[j].yf - 3500;
		if (wrk[j].s1<500){
			wrk[j].tax = wrk[j].s1*(float)0.05;
		}
		if (wrk[j].s1>500 || wrk[j].s1<2000){
			wrk[j].tax = wrk[j].s1*(float)0.1;
		}
		if (wrk[j].s1>2000 || wrk[j].s1<5000){
			wrk[j].tax = wrk[j].s1*(float)0.15;
		}
		if (wrk[j].s1>5000 || wrk[j].s1<20000){
			wrk[j].tax = wrk[j].s1*(float)0.2;
		}
		if (wrk[j].s1>20000 || wrk[j].s1<40000){
			wrk[j].tax = wrk[j].s1*(float)0.25;
		}
		if (wrk[j].s1>40000 || wrk[j].s1<60000){
			wrk[j].tax = wrk[j].s1*(float)0.3;
		}
		if (wrk[j].s1>60000 || wrk[j].s1<80000){
			wrk[j].tax = wrk[j].s1*(float)0.35;
		}
		if (wrk[j].s1>80000 || wrk[j].s1<100000){
			wrk[j].tax = wrk[j].s1*(float)0.4;
		}
		if (wrk[j].s1>100000){
			wrk[j].tax = wrk[j].s1*(float)0.45;
		}
		
	}
	else{ wrk[j].tax = 0; }
	wrk[j].sf = wrk[j].yf - wrk[j].tax;
	//cout<<"实发工资"<<sf;
};

int read()
{
	
	int i=0;
	int n=0;                   //员工人数
	if((fp=fopen("gz.dat","rb"))==NULL)
	{
		printf("无法打开文件，请先创建文件或加入职工\n");
		//exit(0);
	}
	else
	{
		do
		{
			fread(&wrk[i],sizeof(struct zggz),1,fp);
			i++;
			n=i-1;             //减去多出的1
		}
		while(feof(fp)==0);    //当文件指针指到文件尾部
	}
	
	fclose(fp);
	return n;                  //返回当前职工人数
}

void Add()  //添加职工信息
{
	
	do
	{
		printf("当前有%d个职工的信息\n",total);
		printf("请输入要增加的职工的信息：");
		printf("\n\t\t\t请输入职工的信息：\n");
		 printf("\n\t\t\t职工工号：");
	     scanf("%s", &wrk[j].ID);
		 printf("\n\t\t\t职工姓名：");
		 scanf("%s", wrk[j].name);
		 printf("\n\t\t\t岗位工资：");
		 scanf("%f", &wrk[j].gg);
		 printf("\n\t\t\t薪级工资：");
		 scanf("%f", &wrk[j].xg);
		 printf("\n\t\t\t职务津贴：");
		 scanf("%f", &wrk[j].zj);
		 printf("\n\t\t\t绩效工资：");
		 scanf("%f", &wrk[j].jg);
		 wrk[j].yf = wrk[j].gg + wrk[j].xg + wrk[j].zj+wrk[j].jg;
		 grsds();
		 printf("\n\t\t\t职工应发：%f\n", wrk[j].yf);
		 printf("\n\t\t\t职工个人所得税：%f\n", wrk[j].tax);
		 printf("\n\t\t\t职工应发工资：%f\n", wrk[j].sf);
		 
		j++;
		total += j;
		printf("是否继续？\n是请按1;否请按0.\n\n请选择：");
		fflush(stdin);
		while(1)
		{
			
	        scanf("%c",&k);
		    if(k =='0' || k == '1')	 
			     break;
	        printf("输入有误\n请重新输入：");
		}
	
	}while(k=='1');

    fflush(stdin);
	return;
}

/*void print(){
	int i,j;
	fp = fread("gz.dat","r");
	if(fp==NULL){
	printf("文件打开失败\n");
	}
		printf("职工工号：%s\t",wrk[j].ID);
		printf("职工姓名：%s\t",wrk[j].name);
		printf("职工岗位工资：%f\t",wrk[j].gg);
		printf("职工薪级工资：%f\t",wrk[j].xg);
		printf("职工职务津贴：%f\t",wrk[j].zj);
		printf("职工绩效工资：%f\t",wrk[j].jg);
		printf("职工应发工资：%f\t",wrk[j].yf);
		printf("职工个人所得税：%f\t",wrk[j].tax);
		printf("职工实发工资：%f\t",wrk[j].sf);


	
}*/
void write()         //职工信息保存
{
	fp = fopen("gz.dat","a+");
	//fr = fread("gz.dat","r");
	assert(fp);
	for(j = 0; j < total; j++)
	{
		fprintf(fp,"%s%s%f%f%f%f%f%f%f \n",wrk[j].ID,wrk[j].name,wrk[j].gg,wrk[j].xg,wrk[j].zj,wrk[j].jg,wrk[j].yf,wrk[j].tax,wrk[j].sf);
	}
	printf("职工信息保存成功\n");
	system("pause");

	fclose(fp);

	return ;
}




void modify()   //更改职工信息
{
	char ch[10];
	fflush(stdin);
    printf("\n\t\t\t\t更改职工信息\n");
	printf("请输入职工的姓名：");
	do
	{
		scanf("%s", &ch);
		for(j = 0; j < total; j++)
		{
			if(!strcmp(wrk[j].name,ch))
			{	
				printf("请输入职工工号：");
				fflush(stdin);
				scanf("%s", &wrk[j].ID);
				printf("请输入职工姓名：");
				fflush(stdin);
				gets(wrk[j].name);
                printf("\n\t\t\t岗位工资：");
                scanf("%f", &wrk[j].gg);
				printf("\n\t\t\t薪级工资：");
				scanf("%f", &wrk[j].xg);
				printf("\n\t\t\t职务津贴：");
				scanf("%f", &wrk[j].zj);
				printf("\n\t\t\t绩效工资：");
				scanf("%f", &wrk[j].jg);
				wrk[j].yf = wrk[j].gg + wrk[j].xg + wrk[j].zj+wrk[j].jg;
                printf("\n\t\t\t职工应发：%f\n", wrk[j].yf);
		        printf("\n\t\t\t职工个人所得税：%f\n", wrk[j].tax);
			    printf("\n\t\t\t职工应发工资：%f\n", wrk[j].sf);
				printf("是否继续？\n是请按1;否请按0.\n\n请选择：");
				fflush(stdin);
			}
                while(1)
				{
			         
	                 scanf("%c",&k);
		             if(k=='1' || k=='0')	 
			             break;
	                 printf("输入有误\n请重新输入：");
				}
			
		}
		
	}
	while(k=='1');
	fflush(stdin);
    system("pause");
	system("cls");
	return;
}

void Del()    //删除职工信息
{
	char ch[10];
	do
	{
		printf("\n\t\t\t\t删除职工信息\n");
		printf("请输入职工姓名：");
		fflush(stdin);
		gets(ch);
		for(j = 0; j < total; j++)
		{
			if(!strcmp(wrk[j].name,ch))
			{	
				
				for(j = j; j < total; j++)
				{
					wrk[j] = wrk[j+1];
				}
			}
		}
		printf("是否继续？\n是请按1;否请按0.\n\n请选择：");
		fflush(stdin);
		while(1)
		{
			   
	           scanf("%c",&k);
		       if(k=='1' || k=='0')
			   {	 
			          break;
			   }
	           printf("输入有误\n请重新输入：");
		}
		
	}while(k=='1');
	fflush(stdin);
	return;
}

void find()    //查询职工信息
{
	fp = fopen("gz.dat","rb");
	int m=read();
	char ch[4];
	fflush(stdin);
	do
	{
		printf("\n\t\t\t查询职工信息\n");
		printf("请输入职工姓名：");
		
		fflush(stdin);
		gets(ch);
		for(flag = 1,j = 0; j < m; j++)
		{
			if(strcmp(wrk[j].ID,ch)==0)
			{
				printf("职工工号：%s\n",wrk[j].ID);
				printf("职工姓名：%s\n",wrk[j].name);
				printf("职工岗位工资：%f\n",wrk[j].gg);
				printf("职工薪级工资：%f\n",wrk[j].xg);
				printf("职工职务津贴：%f\n",wrk[j].zj);
				printf("职工绩效工资：%f\n",wrk[j].jg);
				printf("职工应发工资：%f\n",wrk[j].yf);
				printf("职工个人所得税：%f\n",wrk[j].tax);
				printf("职工实发工资：%f\n",wrk[j].sf);
			
			}
			
			printf("是否继续？\n是请按y;否请按n.\n\n请选择：");
			fflush(stdin);
		    while(1)
			{
			     
	             scanf("%c",&k);
		         if(k == 'y' || k == 'n')
			          break;
				 printf("输入有误\n请重新输入：");
			}
		}
		
	}while(k=='y');
	fclose(fp);
	fflush(stdin);
	system("pause");
	system("cls");
	return;
}