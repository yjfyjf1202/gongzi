#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
static int total=0;
typedef struct zggz
{
	char ID[10];  //Ա������
	char name[20];//Ա������
	float gg,xg,zj,jg,yf,tax,sf,s1;
}worker;

int j=0;
char k;
FILE *fp;
//FILE *fr;

void Input();   //
void Add();     //
void find();    //
void write();   // ��������
void modify();  //
void Del();
void print();     //

worker wrk[50];
int main()   //������ϵͳ
{
	char ch;
	system("cls");
    printf("\n\t\t\t\tְ������ϵͳ\n\n");
    printf("\n\t\t\t\t�༶��\n");
	printf("\n\n\t\t\t\t�����ˣ�\n");
	printf("\n\n\t\t\t\tѧ�ţ�n\n\n");
	system("pause");
	system("cls");

	do
	{
	     printf ("\n\t\t\t��ӭ����ְ������ϵͳ\n\n\n");
         printf ("\n\t\t\t 1.����ְ����Ϣ\n");
	     printf ("\n\t\t\t 2.����ְ����Ϣ\n");
    	 printf ("\n\t\t\t 3.ɾ��ְ����Ϣ\n");
		 printf ("\n\t\t\t 4.��ѯְ������\n");
		 printf ("\n\t\t\t 5.����ְ����Ϣ\n");
		 printf ("\n\t\t\t 6.����ְ����Ϣ\n");
	     printf ("\n\t\t\t 0.�˳�ְ������ϵͳ\n");
		 printf ("\n\n\n����������Ҫѡ������֣�");
		 scanf("%d", &ch);
		 switch(ch)
		 {
		// case 6:system("cls");Input();break;
		 case 1:system("cls");Add();break;
		 case 2:system("cls");modify();break;
		 case 3:system("cls");Del();break;
		 case 4:system("cls");find();break;
		 case 5:system("cls");write();break;
		 case 0:system("cls");printf("\t\t��лʹ��ְ������ϵͳ\n");exit(0);
		 default:printf("����������������0��6֮������\n");
		 }
	}while(1);
	fflush(stdin);
	return 0;
}

/*void Input()   //����ְ����Ϣ
{
	
	do
	{
	     printf("\n\t\t\t������ְ������Ϣ��\n");
		 printf("\n\t\t\tְ�����ţ�");
	     scanf("%s", &wrk[j].ID);
		 printf("\n\t\t\tְ��������");
		 scanf("%s", wrk[j].name);
		 printf("\n\t\t\t��λ���ʣ�");
		 scanf("%f", &wrk[j].gg);
		 printf("\n\t\t\tн�����ʣ�");
		 scanf("%f", &wrk[j].xg);
		 printf("\n\t\t\tְ�������");
		 scanf("%f", &wrk[j].zj);
		 printf("\n\t\t\t��Ч���ʣ�");
		 scanf("%f", &wrk[j].jg);

		 wrk[j].yf = wrk[j].gg + wrk[j].xg + wrk[j].zj+wrk[j].jg;
         printf("\n\t\t\tְ��ʵ�ʹ��ʣ�%d\n", wrk[j].yf);
		 j++;
		 total=j;
		  printf("\n\n\n\n�Ƿ������\n���밴1;���밴0.\n\n��ѡ��");
		  fflush(stdin);
		 while(1)
		 {
			 fflush(stdin);
	         scanf("%c", &k);
		     if(k == '0' || k == '1')	 
			     break;
	         printf("��������\n���������룺");
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
	//cout<<"ʵ������"<<sf;
};

int read()
{
	
	int i=0;
	int n=0;                   //Ա������
	if((fp=fopen("gz.dat","rb"))==NULL)
	{
		printf("�޷����ļ������ȴ����ļ������ְ��\n");
		//exit(0);
	}
	else
	{
		do
		{
			fread(&wrk[i],sizeof(struct zggz),1,fp);
			i++;
			n=i-1;             //��ȥ�����1
		}
		while(feof(fp)==0);    //���ļ�ָ��ָ���ļ�β��
	}
	
	fclose(fp);
	return n;                  //���ص�ǰְ������
}

void Add()  //���ְ����Ϣ
{
	
	do
	{
		printf("��ǰ��%d��ְ������Ϣ\n",total);
		printf("������Ҫ���ӵ�ְ������Ϣ��");
		printf("\n\t\t\t������ְ������Ϣ��\n");
		 printf("\n\t\t\tְ�����ţ�");
	     scanf("%s", &wrk[j].ID);
		 printf("\n\t\t\tְ��������");
		 scanf("%s", wrk[j].name);
		 printf("\n\t\t\t��λ���ʣ�");
		 scanf("%f", &wrk[j].gg);
		 printf("\n\t\t\tн�����ʣ�");
		 scanf("%f", &wrk[j].xg);
		 printf("\n\t\t\tְ�������");
		 scanf("%f", &wrk[j].zj);
		 printf("\n\t\t\t��Ч���ʣ�");
		 scanf("%f", &wrk[j].jg);
		 wrk[j].yf = wrk[j].gg + wrk[j].xg + wrk[j].zj+wrk[j].jg;
		 grsds();
		 printf("\n\t\t\tְ��Ӧ����%f\n", wrk[j].yf);
		 printf("\n\t\t\tְ����������˰��%f\n", wrk[j].tax);
		 printf("\n\t\t\tְ��Ӧ�����ʣ�%f\n", wrk[j].sf);
		 
		j++;
		total += j;
		printf("�Ƿ������\n���밴1;���밴0.\n\n��ѡ��");
		fflush(stdin);
		while(1)
		{
			
	        scanf("%c",&k);
		    if(k =='0' || k == '1')	 
			     break;
	        printf("��������\n���������룺");
		}
	
	}while(k=='1');

    fflush(stdin);
	return;
}

/*void print(){
	int i,j;
	fp = fread("gz.dat","r");
	if(fp==NULL){
	printf("�ļ���ʧ��\n");
	}
		printf("ְ�����ţ�%s\t",wrk[j].ID);
		printf("ְ��������%s\t",wrk[j].name);
		printf("ְ����λ���ʣ�%f\t",wrk[j].gg);
		printf("ְ��н�����ʣ�%f\t",wrk[j].xg);
		printf("ְ��ְ�������%f\t",wrk[j].zj);
		printf("ְ����Ч���ʣ�%f\t",wrk[j].jg);
		printf("ְ��Ӧ�����ʣ�%f\t",wrk[j].yf);
		printf("ְ����������˰��%f\t",wrk[j].tax);
		printf("ְ��ʵ�����ʣ�%f\t",wrk[j].sf);


	
}*/
void write()         //ְ����Ϣ����
{
	fp = fopen("gz.dat","a+");
	//fr = fread("gz.dat","r");
	assert(fp);
	for(j = 0; j < total; j++)
	{
		fprintf(fp,"%s%s%f%f%f%f%f%f%f \n",wrk[j].ID,wrk[j].name,wrk[j].gg,wrk[j].xg,wrk[j].zj,wrk[j].jg,wrk[j].yf,wrk[j].tax,wrk[j].sf);
	}
	printf("ְ����Ϣ����ɹ�\n");
	system("pause");

	fclose(fp);

	return ;
}




void modify()   //����ְ����Ϣ
{
	char ch[10];
	fflush(stdin);
    printf("\n\t\t\t\t����ְ����Ϣ\n");
	printf("������ְ����������");
	do
	{
		scanf("%s", &ch);
		for(j = 0; j < total; j++)
		{
			if(!strcmp(wrk[j].name,ch))
			{	
				printf("������ְ�����ţ�");
				fflush(stdin);
				scanf("%s", &wrk[j].ID);
				printf("������ְ��������");
				fflush(stdin);
				gets(wrk[j].name);
                printf("\n\t\t\t��λ���ʣ�");
                scanf("%f", &wrk[j].gg);
				printf("\n\t\t\tн�����ʣ�");
				scanf("%f", &wrk[j].xg);
				printf("\n\t\t\tְ�������");
				scanf("%f", &wrk[j].zj);
				printf("\n\t\t\t��Ч���ʣ�");
				scanf("%f", &wrk[j].jg);
				wrk[j].yf = wrk[j].gg + wrk[j].xg + wrk[j].zj+wrk[j].jg;
                printf("\n\t\t\tְ��Ӧ����%f\n", wrk[j].yf);
		        printf("\n\t\t\tְ����������˰��%f\n", wrk[j].tax);
			    printf("\n\t\t\tְ��Ӧ�����ʣ�%f\n", wrk[j].sf);
				printf("�Ƿ������\n���밴1;���밴0.\n\n��ѡ��");
				fflush(stdin);
			}
                while(1)
				{
			         
	                 scanf("%c",&k);
		             if(k=='1' || k=='0')	 
			             break;
	                 printf("��������\n���������룺");
				}
			
		}
		
	}
	while(k=='1');
	fflush(stdin);
    system("pause");
	system("cls");
	return;
}

void Del()    //ɾ��ְ����Ϣ
{
	char ch[10];
	do
	{
		printf("\n\t\t\t\tɾ��ְ����Ϣ\n");
		printf("������ְ��������");
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
		printf("�Ƿ������\n���밴1;���밴0.\n\n��ѡ��");
		fflush(stdin);
		while(1)
		{
			   
	           scanf("%c",&k);
		       if(k=='1' || k=='0')
			   {	 
			          break;
			   }
	           printf("��������\n���������룺");
		}
		
	}while(k=='1');
	fflush(stdin);
	return;
}

void find()    //��ѯְ����Ϣ
{
	fp = fopen("gz.dat","rb");
	int m=read();
	char ch[4];
	fflush(stdin);
	do
	{
		printf("\n\t\t\t��ѯְ����Ϣ\n");
		printf("������ְ��������");
		
		fflush(stdin);
		gets(ch);
		for(flag = 1,j = 0; j < m; j++)
		{
			if(strcmp(wrk[j].ID,ch)==0)
			{
				printf("ְ�����ţ�%s\n",wrk[j].ID);
				printf("ְ��������%s\n",wrk[j].name);
				printf("ְ����λ���ʣ�%f\n",wrk[j].gg);
				printf("ְ��н�����ʣ�%f\n",wrk[j].xg);
				printf("ְ��ְ�������%f\n",wrk[j].zj);
				printf("ְ����Ч���ʣ�%f\n",wrk[j].jg);
				printf("ְ��Ӧ�����ʣ�%f\n",wrk[j].yf);
				printf("ְ����������˰��%f\n",wrk[j].tax);
				printf("ְ��ʵ�����ʣ�%f\n",wrk[j].sf);
			
			}
			
			printf("�Ƿ������\n���밴y;���밴n.\n\n��ѡ��");
			fflush(stdin);
		    while(1)
			{
			     
	             scanf("%c",&k);
		         if(k == 'y' || k == 'n')
			          break;
				 printf("��������\n���������룺");
			}
		}
		
	}while(k=='y');
	fclose(fp);
	fflush(stdin);
	system("pause");
	system("cls");
	return;
}