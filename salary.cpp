/************************************************************************************************************
FileName:main.cpp
Author: 俞剑锋     Version: 1.0     Date: 2018.6.29
Description: 本系统为工资管理系统包含增、删、查、改的功能
Version: 1.0
Function List:
1. add();            输入职工工资数据函数
2. read();           读取职工工资数据函数
3. write(int);       保存职工工资数据函数
4. find();           查询职工工资数据函数
5. list();           浏览职工工资数据函数
6. modify();         修改职工工资数据函数
7. del();            删除职工工资数据函数
8. grsds(int);       计算个人所得税函数
9. menu();           主页菜单
*************************************************************************************************************/
#include<stdio.h>      
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#define count 100        //系统容量
int read();            //读取职工工资数据函数
void write(int);       //保存职工工资数据函数
void find();           //查询职工工资数据函数
void list();           //浏览职工工资数据函数
void modify();         //修改职工工资数据函数
void del();            //删除职工工资数据函数
void add();            //添加职工工资数据函数
void grsds(int);       //计算个人所得税函数
void menu();           //主页菜单
struct workers        //职工数据结构体
{
	char number[10];      //1~10位数字
	char name[10];        //1~10个字母或1~5个汉字
	float gg;           //岗位工资                   
	float xg;           //薪级工资                   
	float zj;           //职务津贴                  
	float jg;           //绩效工资                   
	float yf;           //应发工资                   
	float tax;            //个人所得税
	float sf;           //实发工资   
	float s1;			//计算个人所得税的中间变量

}zggz[count];

void menu()    //======================菜单模块======================
{

	printf("\n\n         ###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统 ###\n");
	printf("\n\n         请选择<1 - 7> ：\n");
	printf("         =================================================================\n");
	printf("         |       1. 查询职工工资记录                                     |\n");
	printf("         |       2. 修改职工工资记录                                     |\n");
	printf("         |       3. 添加职工工资记录                                     |\n");
	printf("         |       4. 删除职工工资记录                                     |\n");
	printf("         |       5. 保存数据到文件                                       |\n");
	printf("         |       6. 浏览职工记录                                         |\n");
	printf("         |       0. 退出程序                                             |\n");
	printf("         =================================================================\n");
}

//======================主函数========================
int main()
{
	int n, flag, y = 1;
	FILE *fp;
	fp = fopen("gz.dat", "a");
	if (fp == NULL){
		fp = fopen("gz.dat", "a+");
	}
	else
	{
		while (y == 1)
		{
			do
			{
				int m = read();            //输出当前职工数
				menu();
				printf("         当前共有");
				printf("%d", m);
				printf("位职工\n\n");
				printf("         您的选择是:[ ]\b\b");
				scanf("%d", &n);
				if (n >= 0 && n <= 6)
				{
					flag = 1;
					break;
				}
				else
				{
					flag = 0;
					printf("请输入正确选项！\n");
				}
			} while (flag == 0);
			switch (n)
			{

			case 1:
			{
					  find();
					  break;
			}
			case 2:
			{
					  modify();
					  break;
			}
			case 3:
			{
					  add();
					  break;
			}
			case 4:
			{
					  del();
					  break;
			}
			case 5:
			{
					  printf("文件保存成功");
					  system("cls");
					  getchar();
					  break;
			}
			case 6:
			{
					  list();
					  break;
			}
			case 0:
			{
					  system("cls");
					  printf("*****谢谢使用*****");
					  exit(0);
					  y = 0;
			}             //退出系统
			}
		}
	};
	system("cls");
	system("pause");
	return 0;

};

/*======================税务模块======================
计算个人所得税
被函数list、find、del、modify调用
3500为起征点
*/
void grsds(int i)
{
	zggz[i].yf = zggz[i].gg + zggz[i].xg + zggz[i].zj + zggz[i].jg;      //计算应付工资
	float b, t;
	b = zggz[i].yf;
	if (b>3500)
	{
		zggz[i].s1 = b - 3500;
		t = zggz[i].s1;
		if (t<500)
		{
			zggz[i].tax = t*(float)0.05;
		}
		if (t>500 && t<2000)
		{
			zggz[i].tax = t*(float)0.1;
		}
		if (t>2000 && t<5000)
		{
			zggz[i].tax = t*(float)0.15;
		}
		if (t>5000 && t<20000)
		{
			zggz[i].tax = t*(float)0.2;
		}
		if (t>20000 && t<40000)
		{
			zggz[i].tax = t*(float)0.25;
		}
		if (t>40000 && t<60000)
		{
			zggz[i].tax = t*(float)0.3;
		}
		if (t>60000 && t<80000){
			zggz[i].tax = t*(float)0.35;
		}
		if (t>80000 && t<100000)
		{
			zggz[i].tax = t*(float)0.4;
		}
		if (t>100000)
		{
			zggz[i].tax = t*(float)0.45;
		}

	}
	else{ zggz[i].tax = 0; }
	zggz[i].sf = b - zggz[i].tax;
}

/*======================保存模块======================
被函数del、modify调用
*/
void write(int m)
{
	int i;
	FILE *fp;
	if ((fp = fopen("gz.dat", "wb")) == NULL)
	{
		printf("无法打开文件\n");
		exit(0);
	}
	for (i = 0; i<m; i++)                                          
	{
		if (fwrite(&zggz[i], sizeof(struct workers), 1, fp) != 1)   //如果没有正确写入
		{
			printf("写入失败\n");
		}
	}
	fclose(fp);
}
/*======================读取模块======================
函数返回一个局部变量n，用于统计当前职工人数
被函数list调用取得返回值n
返回值被函数list、del、modify、find调用
*/
int read()
{
	FILE *fp;
	int i = 0;
	int n = 0;                   //员工人数
	if ((fp = fopen("gz.dat", "rb")) == NULL)
	{
		printf("无法打开文件，请先创建文件或加入职工\n");
		//exit(0);
	}
	else
	{
		do
		{
			fread(&zggz[i], sizeof(struct workers), 1, fp);
			i++;
			n = i - 1;             //减去多出的1
		} while (feof(fp) == 0);    //当文件指针指到文件尾部
	}

	fclose(fp);
	return n;                  //返回当前职工人数
}

/*======================浏览模块======================
调用
*/
void list()
{
	system("cls");
	int i;
	int m = read();
	printf("----------------------------------------------------------------------------------\n");
	printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
	for (i = 0; i<m; i++)
	{
		printf("%s\t", zggz[i].number);
		//printf("\t");
		printf("%s\t", zggz[i].name);
		//printf("\t");
		printf("%-0.1f\t\t", zggz[i].gg);
		//printf("\t");
		printf("%-0.1f\t\t", zggz[i].xg);
		//printf("\t");
		printf("%-0.1f\t\t", zggz[i].zj);
		//printf("\t");
		printf("%-0.1f\t\t", zggz[i].jg);
		//printf("\t");
		grsds(i);              //计算输出应发工资，税率及实付工资
		printf("%-0.1f\t\t", zggz[i].yf);
		//printf("\t");
		printf("%-0.1f\t\t", zggz[i].tax);
		//printf("\t");
		printf("%-0.1f\t\t", zggz[i].sf);
		//printf("\t");
		printf("\n");
	}
	printf("----------------------------------------------------------------------------------\n");
	printf("按任意键继续");
	getchar();
	getchar();
	system("cls");
}

//======================查询模块======================
void find()
{
	system("cls");
	int t, i;
	int m = read();
	char gonghao[11];
	printf("请输入想要查询的职工工号\n");
	scanf("%s", gonghao);
	for (i = 0; i<m; i++)
	{
		if (strcmp(zggz[i].number, gonghao) == 0)
		{
			printf("---------------------------------------------------------------------------------\n");
			printf("你要查询的是：\n");
			printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
			printf("%s\t", zggz[i].number);
			//printf("\t");
			printf("%s\t", zggz[i].name);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].gg);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].xg);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].zj);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].jg);
			//printf("\t");
			grsds(i);              //计算输出应发工资，税率及实付工资
			printf("%-0.1f\t\t", zggz[i].yf);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].tax);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].sf);
			//printf("\t");
			printf("\n");
			printf("---------------------------------------------------------------------------------\n");
			break;
		}
	}
	if (i == m)
	{
		printf("查无此人\n");
	}
	printf("继续查询请按1，返回请按2\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:find();
		break;
	case 2: system("cls");
		break;
	default:break;

	}

}

//======================删除模块======================
void del()
{
	system("cls");
	int m = read();
	int i, j, n, t, flag;
	char gonghao[11];
	printf("当前职工信息：\n");
	list();
	printf("\n");
	printf("请输入要删除的职工工号：");
	scanf("%s", gonghao);
	for (flag = 1, i = 0; flag&&i<m; i++)
	{
		if (strcmp(zggz[i].number, gonghao) == 0)
		{
			printf("---------------------------------------------------------------------------------\n");
			printf("要删除的职工信息：\n");
			printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n\n");
			printf("\n%s\t", zggz[i].number);
			//printf("\t");
			printf("%s\t", zggz[i].name);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].gg);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].xg);
			//printf("\t");
			printf("%-0.1f\t", zggz[i].zj);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].jg);
			//printf("\t");
			grsds(i);              //计算输出应发工资，税率及实付工资
			printf("%-0.1f\t\t", zggz[i].yf);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].tax);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].sf);
			//printf("\t");
			printf("\n");
			printf("---------------------------------------------------------------------------------\n");
			printf("确认删除请按1，放弃删除请按0\n");
			scanf("%d", &n);
			if (n == 1)
			{
				for (j = i; j<m; j++)
				{
					zggz[j] = zggz[j + 1];             //职工向前覆盖达到删除的效果
				}
			}
			flag = 0;
		}
	}
	if (!flag)
	{
		m = m - 1;
		printf("删除成功\n\n");
	}
	else
	{
		printf("查无此人\n");
	}
	printf("当前所有职工信息\n");
	write(m);
	list();
	printf("继续删除请按1，不再删除请按2\n");
	printf("%d", &t);
	switch (t)
	{
	case 1:del();
		break;
	case 2:break;
	default:break;
	}
	system("cls");
}

//======================修改模块======================
void modify()
{
	system("cls");
	char num[10];    //1~10位数字
	char nam[10];      //1~10个字母或1~5个汉字
	float new_gg;         //岗位工资                   
	float new_xg;         //薪级工资                   
	float new_zj;         //职务津贴                  
	float new_jg;         //绩效工资                                    
	int b, c, i, n, t, k = 0;	       //选项变量
	int m = read();
	char gonghao[10];
	printf("当前职工信息：\n");
	list();
	printf("请输入要修改的职工工号：\n\n");
	scanf("%s", gonghao);
	for (i = 0; i<m; i++)
	{
		if (strcmp(zggz[i].number, gonghao) == 0)
		{
			printf("-----------------------------------------------------------------------------------\n");
			printf("要修改的职工信息：\n");
			printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n\n");
			printf("%s\t", zggz[i].number);
			//printf("\t");
			printf("%s\t", zggz[i].name);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].gg);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].xg);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].zj);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].jg);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].yf);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].tax);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].sf);
			//printf("\t");
			printf("\n");
			grsds(i); //计算输出应发工资，税率及实付工资
			printf("\n");
			k = i;
			printf("-----------------------------------------------------------------------------------\n");
			printf("确认要修改这名职工请按1，放弃修改请按0\n");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("请输入要修改的选项：1.工号 2.姓名 3.岗位工资  4.薪级工资 5.职务津贴  6.绩效工资 \n");
				scanf("%d", &c);
				if (c>6 || c<1)
				{
					printf("选择错误请重新输入\n");
				}
			}
			//flag=0;
		}
	}
	if (k == m)
	{
		printf("查无此人\n\n");
	}
	do
	{
		switch (c)                   //当找到第i个职工时,for语句后i自加了1,所以下面的应该把改后的信息赋值给第i-1个人
		{
		case 1:
			printf("工号改为：");
			scanf("%s", &num);
			strcpy(zggz[k].number, num);
			break;
		case 2:
			printf("姓名改为：");
			scanf("%s", &nam[i - 1]);
			strcpy(zggz[k].name, &nam[i - 1]);
			break;
		case 3:
			printf("岗位工资改为：");
			scanf("%f", &new_gg);
			zggz[k].gg = new_gg;
			break;
		case 4:
			printf("薪级工资改为：");
			scanf("%f", &new_xg);
			zggz[k].xg = new_xg;
			break;
		case 5:
			printf("职务津贴改为：");
			scanf("%f", &new_zj);
			zggz[k].zj = new_zj;
			break;
		case 6:
			printf("绩效工资改为：");
			scanf("%f", &new_jg);
			zggz[k].jg = new_jg;
			break;
		}
		printf("\n");
		printf("确认请按1，重新修改请按2\n");
		scanf("%d", &b);
	} while (b == 2);
	{
		printf("修改后的所有职工信息为：\n");
		write(m);
		list();
	}
	printf("继续修改请按1,返回请按任意键");
	scanf("%d", &t);
	switch (t)
	{
	case 1:modify();
		break;
	default:break;
	}
	system("cls");
}

//======================添加模块======================
void add()
{
	system("cls");
	FILE *fp;
	int n = 0, i, k = 1;
	int l;
	char gh[10];
	if ((fp = fopen("gz.dat", "ab+")) == NULL)
	{
		printf("无法打开gz文件\n");
		exit(0);
	}
	printf("职工号：");
	scanf("%s", &gh);
	if (strcmp(zggz[n].number, gh) == 0)
	{
		printf("工号已存在");
		printf("返回请按0");
		scanf("%d",&l);
		switch (l){
		case 1:{
				   system("cls");
				   main();
		}

		}
		
		
	}
	else
	{
	
	while (k){
		printf("职工号：");
		scanf("%s", &zggz[n].number);
		printf("姓名：");
		scanf("%s", &zggz[n].name);
		printf("岗位工资：");
		scanf("%f", &zggz[n].gg);
		printf("薪级工资：");
		scanf("%f", &zggz[n].xg);
		printf("职务津贴：");
		scanf("%f", &zggz[n].zj);
		printf("绩效工资：");
		scanf("%f", &zggz[n].jg);
		fwrite(&zggz[n], sizeof(struct workers), 1, fp);    //写入文件尾部
		printf("添加成功\n");
		printf("继续请输入1退出请输入0\n");
		scanf("%d", &k);
		if (k == 0){ break; };
	};
	}
	getchar();
	system("cls");
	fclose(fp);
}
