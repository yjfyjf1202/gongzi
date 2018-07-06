/************************************************************************************************************
FileName:main.cpp
Author: �ὣ��     Version: 1.0     Date: 2018.6.29
Description: ��ϵͳΪ���ʹ���ϵͳ��������ɾ���顢�ĵĹ���
Version: 1.0
Function List:
1. add();            ����ְ���������ݺ���
2. read();           ��ȡְ���������ݺ���
3. write(int);       ����ְ���������ݺ���
4. find();           ��ѯְ���������ݺ���
5. list();           ���ְ���������ݺ���
6. modify();         �޸�ְ���������ݺ���
7. del();            ɾ��ְ���������ݺ���
8. grsds(int);       �����������˰����
9. menu();           ��ҳ�˵�
*************************************************************************************************************/
#include<stdio.h>      
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#define count 100        //ϵͳ����
int read();            //��ȡְ���������ݺ���
void write(int);       //����ְ���������ݺ���
void find();           //��ѯְ���������ݺ���
void list();           //���ְ���������ݺ���
void modify();         //�޸�ְ���������ݺ���
void del();            //ɾ��ְ���������ݺ���
void add();            //���ְ���������ݺ���
void grsds(int);       //�����������˰����
void menu();           //��ҳ�˵�
struct workers        //ְ�����ݽṹ��
{
	char number[10];      //1~10λ����
	char name[10];        //1~10����ĸ��1~5������
	float gg;           //��λ����                   
	float xg;           //н������                   
	float zj;           //ְ�����                  
	float jg;           //��Ч����                   
	float yf;           //Ӧ������                   
	float tax;            //��������˰
	float sf;           //ʵ������   
	float s1;			//�����������˰���м����

}zggz[count];

void menu()    //======================�˵�ģ��======================
{

	printf("\n\n         ###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ ###\n");
	printf("\n\n         ��ѡ��<1 - 7> ��\n");
	printf("         =================================================================\n");
	printf("         |       1. ��ѯְ�����ʼ�¼                                     |\n");
	printf("         |       2. �޸�ְ�����ʼ�¼                                     |\n");
	printf("         |       3. ���ְ�����ʼ�¼                                     |\n");
	printf("         |       4. ɾ��ְ�����ʼ�¼                                     |\n");
	printf("         |       5. �������ݵ��ļ�                                       |\n");
	printf("         |       6. ���ְ����¼                                         |\n");
	printf("         |       0. �˳�����                                             |\n");
	printf("         =================================================================\n");
}

//======================������========================
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
				int m = read();            //�����ǰְ����
				menu();
				printf("         ��ǰ����");
				printf("%d", m);
				printf("λְ��\n\n");
				printf("         ����ѡ����:[ ]\b\b");
				scanf("%d", &n);
				if (n >= 0 && n <= 6)
				{
					flag = 1;
					break;
				}
				else
				{
					flag = 0;
					printf("��������ȷѡ�\n");
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
					  printf("�ļ�����ɹ�");
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
					  printf("*****ллʹ��*****");
					  exit(0);
					  y = 0;
			}             //�˳�ϵͳ
			}
		}
	};
	system("cls");
	system("pause");
	return 0;

};

/*======================˰��ģ��======================
�����������˰
������list��find��del��modify����
3500Ϊ������
*/
void grsds(int i)
{
	zggz[i].yf = zggz[i].gg + zggz[i].xg + zggz[i].zj + zggz[i].jg;      //����Ӧ������
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

/*======================����ģ��======================
������del��modify����
*/
void write(int m)
{
	int i;
	FILE *fp;
	if ((fp = fopen("gz.dat", "wb")) == NULL)
	{
		printf("�޷����ļ�\n");
		exit(0);
	}
	for (i = 0; i<m; i++)                                          
	{
		if (fwrite(&zggz[i], sizeof(struct workers), 1, fp) != 1)   //���û����ȷд��
		{
			printf("д��ʧ��\n");
		}
	}
	fclose(fp);
}
/*======================��ȡģ��======================
��������һ���ֲ�����n������ͳ�Ƶ�ǰְ������
������list����ȡ�÷���ֵn
����ֵ������list��del��modify��find����
*/
int read()
{
	FILE *fp;
	int i = 0;
	int n = 0;                   //Ա������
	if ((fp = fopen("gz.dat", "rb")) == NULL)
	{
		printf("�޷����ļ������ȴ����ļ������ְ��\n");
		//exit(0);
	}
	else
	{
		do
		{
			fread(&zggz[i], sizeof(struct workers), 1, fp);
			i++;
			n = i - 1;             //��ȥ�����1
		} while (feof(fp) == 0);    //���ļ�ָ��ָ���ļ�β��
	}

	fclose(fp);
	return n;                  //���ص�ǰְ������
}

/*======================���ģ��======================
����
*/
void list()
{
	system("cls");
	int i;
	int m = read();
	printf("----------------------------------------------------------------------------------\n");
	printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
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
		grsds(i);              //�������Ӧ�����ʣ�˰�ʼ�ʵ������
		printf("%-0.1f\t\t", zggz[i].yf);
		//printf("\t");
		printf("%-0.1f\t\t", zggz[i].tax);
		//printf("\t");
		printf("%-0.1f\t\t", zggz[i].sf);
		//printf("\t");
		printf("\n");
	}
	printf("----------------------------------------------------------------------------------\n");
	printf("�����������");
	getchar();
	getchar();
	system("cls");
}

//======================��ѯģ��======================
void find()
{
	system("cls");
	int t, i;
	int m = read();
	char gonghao[11];
	printf("��������Ҫ��ѯ��ְ������\n");
	scanf("%s", gonghao);
	for (i = 0; i<m; i++)
	{
		if (strcmp(zggz[i].number, gonghao) == 0)
		{
			printf("---------------------------------------------------------------------------------\n");
			printf("��Ҫ��ѯ���ǣ�\n");
			printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
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
			grsds(i);              //�������Ӧ�����ʣ�˰�ʼ�ʵ������
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
		printf("���޴���\n");
	}
	printf("������ѯ�밴1�������밴2\n");
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

//======================ɾ��ģ��======================
void del()
{
	system("cls");
	int m = read();
	int i, j, n, t, flag;
	char gonghao[11];
	printf("��ǰְ����Ϣ��\n");
	list();
	printf("\n");
	printf("������Ҫɾ����ְ�����ţ�");
	scanf("%s", gonghao);
	for (flag = 1, i = 0; flag&&i<m; i++)
	{
		if (strcmp(zggz[i].number, gonghao) == 0)
		{
			printf("---------------------------------------------------------------------------------\n");
			printf("Ҫɾ����ְ����Ϣ��\n");
			printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n\n");
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
			grsds(i);              //�������Ӧ�����ʣ�˰�ʼ�ʵ������
			printf("%-0.1f\t\t", zggz[i].yf);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].tax);
			//printf("\t");
			printf("%-0.1f\t\t", zggz[i].sf);
			//printf("\t");
			printf("\n");
			printf("---------------------------------------------------------------------------------\n");
			printf("ȷ��ɾ���밴1������ɾ���밴0\n");
			scanf("%d", &n);
			if (n == 1)
			{
				for (j = i; j<m; j++)
				{
					zggz[j] = zggz[j + 1];             //ְ����ǰ���Ǵﵽɾ����Ч��
				}
			}
			flag = 0;
		}
	}
	if (!flag)
	{
		m = m - 1;
		printf("ɾ���ɹ�\n\n");
	}
	else
	{
		printf("���޴���\n");
	}
	printf("��ǰ����ְ����Ϣ\n");
	write(m);
	list();
	printf("����ɾ���밴1������ɾ���밴2\n");
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

//======================�޸�ģ��======================
void modify()
{
	system("cls");
	char num[10];    //1~10λ����
	char nam[10];      //1~10����ĸ��1~5������
	float new_gg;         //��λ����                   
	float new_xg;         //н������                   
	float new_zj;         //ְ�����                  
	float new_jg;         //��Ч����                                    
	int b, c, i, n, t, k = 0;	       //ѡ�����
	int m = read();
	char gonghao[10];
	printf("��ǰְ����Ϣ��\n");
	list();
	printf("������Ҫ�޸ĵ�ְ�����ţ�\n\n");
	scanf("%s", gonghao);
	for (i = 0; i<m; i++)
	{
		if (strcmp(zggz[i].number, gonghao) == 0)
		{
			printf("-----------------------------------------------------------------------------------\n");
			printf("Ҫ�޸ĵ�ְ����Ϣ��\n");
			printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n\n");
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
			grsds(i); //�������Ӧ�����ʣ�˰�ʼ�ʵ������
			printf("\n");
			k = i;
			printf("-----------------------------------------------------------------------------------\n");
			printf("ȷ��Ҫ�޸�����ְ���밴1�������޸��밴0\n");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("������Ҫ�޸ĵ�ѡ�1.���� 2.���� 3.��λ����  4.н������ 5.ְ�����  6.��Ч���� \n");
				scanf("%d", &c);
				if (c>6 || c<1)
				{
					printf("ѡ���������������\n");
				}
			}
			//flag=0;
		}
	}
	if (k == m)
	{
		printf("���޴���\n\n");
	}
	do
	{
		switch (c)                   //���ҵ���i��ְ��ʱ,for����i�Լ���1,���������Ӧ�ðѸĺ����Ϣ��ֵ����i-1����
		{
		case 1:
			printf("���Ÿ�Ϊ��");
			scanf("%s", &num);
			strcpy(zggz[k].number, num);
			break;
		case 2:
			printf("������Ϊ��");
			scanf("%s", &nam[i - 1]);
			strcpy(zggz[k].name, &nam[i - 1]);
			break;
		case 3:
			printf("��λ���ʸ�Ϊ��");
			scanf("%f", &new_gg);
			zggz[k].gg = new_gg;
			break;
		case 4:
			printf("н�����ʸ�Ϊ��");
			scanf("%f", &new_xg);
			zggz[k].xg = new_xg;
			break;
		case 5:
			printf("ְ�������Ϊ��");
			scanf("%f", &new_zj);
			zggz[k].zj = new_zj;
			break;
		case 6:
			printf("��Ч���ʸ�Ϊ��");
			scanf("%f", &new_jg);
			zggz[k].jg = new_jg;
			break;
		}
		printf("\n");
		printf("ȷ���밴1�������޸��밴2\n");
		scanf("%d", &b);
	} while (b == 2);
	{
		printf("�޸ĺ������ְ����ϢΪ��\n");
		write(m);
		list();
	}
	printf("�����޸��밴1,�����밴�����");
	scanf("%d", &t);
	switch (t)
	{
	case 1:modify();
		break;
	default:break;
	}
	system("cls");
}

//======================���ģ��======================
void add()
{
	system("cls");
	FILE *fp;
	int n = 0, i, k = 1;
	int l;
	char gh[10];
	if ((fp = fopen("gz.dat", "ab+")) == NULL)
	{
		printf("�޷���gz�ļ�\n");
		exit(0);
	}
	printf("ְ���ţ�");
	scanf("%s", &gh);
	if (strcmp(zggz[n].number, gh) == 0)
	{
		printf("�����Ѵ���");
		printf("�����밴0");
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
		printf("ְ���ţ�");
		scanf("%s", &zggz[n].number);
		printf("������");
		scanf("%s", &zggz[n].name);
		printf("��λ���ʣ�");
		scanf("%f", &zggz[n].gg);
		printf("н�����ʣ�");
		scanf("%f", &zggz[n].xg);
		printf("ְ�������");
		scanf("%f", &zggz[n].zj);
		printf("��Ч���ʣ�");
		scanf("%f", &zggz[n].jg);
		fwrite(&zggz[n], sizeof(struct workers), 1, fp);    //д���ļ�β��
		printf("��ӳɹ�\n");
		printf("����������1�˳�������0\n");
		scanf("%d", &k);
		if (k == 0){ break; };
	};
	}
	getchar();
	system("cls");
	fclose(fp);
}
