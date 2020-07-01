#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�����鱣��ѧ����Ϣ

#define MAX 1000 //���ѧ������
#define MAX_UINT ((2*2147483647)-1)//�޷����������ֵ
#define  STDOUTPUT(a) "%-10d\t%-5s\t\t%-10s\t\%-10s\t%-10s\t%-10s\t%-15s\n\n",MyStudent[a].Stu_Num,MyStudent[a].Stu_Name,MyStudent[a].Stu_Sex,MyStudent[a].Stu_Major,MyStudent[a].Stu_Naplace,MyStudent[a].Stu_Nation,MyStudent[a].Stu_Address//��ʽ����� 
#define _STDOUTPUT "ѧ��\t\t����\t\t�Ա�\t\tרҵ\t\t����\t\t����\t\tסַ\n"
//fflush(stdin)�����ú�getchar()���� 
#define GETS(a) fflush(stdin); gets(a)//���������ַ��� 
typedef  unsigned int UINT ;  //typedef �������Ǹ���֪�����Ͷ���һ������,�˴������Ǹ�unsigned int ����ȡ������ΪUINT

//����һ��student�ṹ��ģ�壬ͬʱ���ýṹ��ȡ������Student
typedef struct student
{
	UINT Stu_Num; //ѧ��ѧ�� 
	char Stu_Name[20]; //ѧ������ 
	char Stu_Sex[20]; //ѧ���Ա� 
	char Stu_Major[20]; //ѧ��רҵ
	char Stu_Naplace[20];//ѧ������
	char Stu_Nation[20];//ѧ������
	char Stu_Address[20];//ѧ��סַ 
}Student;

Student MyStudent[MAX];//ȫ�ֱ���,ѧ������
static UINT Amount=0;//Amount�����������浱ǰѧ��������


//������������
void menu_show();//������ʾ�˵�
UINT get_choice(UINT a,UINT b); //������ȡһ������a��b֮�������ֵ
void Student_add();  //��ѧ���б�������һ���µ�ѧ����Ϣ
void Student_find();  //�ӵ�ǰѧ���б��в�ѯ�Ƿ������ѧ�� 
void Student_del();   //ʵ��ѧ����Ϣ��ɾ�� 
void Student_print(); //��ʾ��ǰ�б��е�����ѧ����Ϣ
void Student_change(); //ѧ����Ϣ���޸� 
void SearchByNum(UINT num);//��ѯͨ��ѧ�� 
void SearchByName(char*);// ��ѯͨ������ 
bool IsReiteration(UINT); //�ж������ѧ���Ƿ��ظ�


//���������� 
int main()
{
	UINT number;
	while(1)
	{
		system("cls");
		menu_show();
		number = get_choice(0,5);
		switch(number)
		{
			case 1:
				system("cls");
				Student_add();
				break;
			case 2:
				system("cls");
				Student_find();
				break;
			case 3:
				system("cls");
				Student_del();
				break;
			case 4:
				system("cls");
				Student_print();
				break;
			case 5:
				system("cls");
				Student_change();
				break;
			case 0:
				printf("лл���ʹ�ã��ټ���\n");
				system("pause");//����ϵͳpause���ʵ���������������һ�����֣��ȴ��û���һ������Ȼ�󷵻ء�
				exit(0);  //����������������
				break;
			default: printf("Error!\n"); break; 	
		}
	}
	return 0;
}



//����menu_show();ʵ����ʾ�˵� 
void menu_show()
{
	printf("   ��ӭ����ѧ����������ϵͳ!  \n");
	printf("=============================\n");
	printf("   1.ѧ����Ϣ�Ĳɼ� \n");
	printf("   2.ѧ����Ϣ�Ĳ�ѯ \n");
	printf("   3.ѧ����Ϣ��ɾ�� \n");
	printf("   4.ѧ����Ϣ����ʾ \n");
	printf("   5.ѧ����Ϣ���޸� \n");
	printf("   0.�˳�����ϵͳ \n");
	printf("=============================\n");
	printf("   ��ѡ��0-5: ");
}

/* ����get_choice()ʵ������ɨ��������룬��һ������a��b֮�������ֵ����
�������ֵ����[a,b]֮�䣬����ʾ��ӭ���棬�������� */
UINT get_choice(UINT a,UINT b)
{
	UINT i=0;
	while(scanf("%d",&i)!=1||i<a||i>b)
	{
		system("cls");
		printf("�����������������\n");
		system("pause");
		system("cls");
		fflush(stdin);
		printf("����������ѧ��:");
	}
	return i;
}



//���� SearchByNum(UINT num)ʵ��ͨ��ѧ�Ų���ѧ�� 
void SearchByNum(UINT num)
{
	int count = 0;
	printf(_STDOUTPUT);
	for(UINT i=0;i<Amount;++i)
	{
		if(MyStudent[i].Stu_Num==num)
		{
			printf(STDOUTPUT(i));
			++count;
		}
	}
	if(0==count)
	{
		printf("�������ѧ��ѧ�Ŵ���!\n");
		system("pause");
		return;
	}
	else printf("\n��ѯ����%d��ѧ�����������ص����Ӧ\n",count);
	system("pause"); 
}


//����SearchByname() ʵ��ͨ�����ֲ���ѧ�� 
void SearchByname(char *pname)
{
	int count = 0;
	printf(_STDOUTPUT);
	for(UINT i=0;i<Amount;++i)
	{
		if(strcmp(pname,MyStudent[i].Stu_Name )==NULL)
		{
			count++;
			printf(STDOUTPUT(i));
		}
	}
	if(count==0)
	{
		printf("����������ִ���\n");
		system("pause");
		return;
	}
	printf("\n\n�鵽����������%d��ѧ��\n",count);
	system("pause");
	
} 


//����IsReiteration(UINT)ʵ���ж�ѧ���Ƿ��ظ�
bool IsReiteration(UINT p)
{
	for (UINT i=0;i<Amount;++i)
	{
		if (p==MyStudent[i].Stu_Num)
			return true;
	}
	return false;
 }  





//����Student_add()ʵ�ֳ�Ա�����
void Student_add()
{
	while(1) 
	{
		system("cls");
		printf("ѧ��ѧ��:");
		char p[2];//�����û�ѡ�� 
		MyStudent[Amount].Stu_Num = get_choice(1,MAX_UINT);
		if(IsReiteration(MyStudent[Amount].Stu_Num))
		{
			printf("�������ѧ���ظ�!\n");
			system("pause");
			return;
		}
		printf("ѧ������:");
		GETS(MyStudent[Amount].Stu_Name);
		printf("ѧ���Ա�:");
		GETS(MyStudent[Amount].Stu_Sex);
		printf("ѧ��רҵ:");
		GETS(MyStudent[Amount].Stu_Major);
		printf("ѧ������:");
		GETS(MyStudent[Amount].Stu_Naplace);
		printf("ѧ������:");
		GETS(MyStudent[Amount].Stu_Nation);
		printf("ѧ��סַ:");
		GETS(MyStudent[Amount].Stu_Address);
		Amount++;
		printf("���ѧ����Ϣ�ɹ�\n"); 
		printf("�Ƿ�������y/n:");
		GETS(p);
		if(strcmp(p,"n")==0||strcmp(p,"N")==0)
			return;
	}
}


//����Student_find()ʵ��ѧ����Ա�Ĳ�ѯ
void Student_find()
{
	UINT choice = 0;//�����û�ѡ�� 
	UINT pnum = 0;
	char pname[40];
	while(1)
	{
		system("cls");
		printf("   ѧ����ѯ\n");
		printf("=============================\n");
		printf("   1.Byѧ��\n");
		printf("   2.By����\n");
		printf("   0.������һ��\n");
		printf("���������ѡ��(0~2)[ ]\b\b");
		choice = get_choice(0,2);
		switch(choice)
		{
			case 0:
				return;
				break;
			case 1:
				system("cls");
				printf("������ѧ��:");
				pnum = get_choice(1,MAX_UINT);
				SearchByNum(pnum);
				break;
			case 2:
				system("cls");
				printf("����������:");
				GETS(pname);
				SearchByname(pname);
				break;
			default: printf("���������!\n");
			break; 
		 } 
	} 
	system("cls");

} 


//����Student_del()ʵ��ѧ����Ϣ��ɾ��
void Student_del()
{
	UINT num=0;
	UINT i;
	printf("��������Ҫɾ����ѧ��ѧ��:");
	num = get_choice(1,MAX_UINT); 
	for(i=0;i<Amount;++i)
	{
		if(num==MyStudent[i].Stu_Num)
			break;
		else 
		{
			printf("�������ѧ�Ų�����\n");
			system("pause");
			return;
		}
	}
	for(UINT j=i;j<Amount-1;j++)
		MyStudent[j] = MyStudent[j+1];
	printf("ɾ��ѧ�������ɹ�\n");
	Amount--;
	system("pause");
 } 




//����Student_print()ʵ����ʾѧ������Ϣ
void Student_print()
{
	printf(_STDOUTPUT);
	for(UINT i=0;i<Amount;++i)
		printf(STDOUTPUT(i));
	printf("����%d��ѧ��\n",Amount);
	system("pause");

} 



//����Student_change()ʵ�ָ���ѧ����Ϣ����
void Student_change()
{
	UINT num;//��ʱ����ѧ��ѧ�� 
	UINT choice;//�����û�ѡ�� 
	UINT i;
	char p[2];
	printf("������ѧ���޸ĸ�ѧ���������Ϣ:");
	num = get_choice(1,MAX_UINT);
	for(i=0;i<Amount;++i)
	{
		if(num==MyStudent[i].Stu_Num)
			break;
		else
		{
			printf("�������ѧ�Ų�����\n");
			system("pause");
			return; 
		 } 
	}
	printf("�Ѳ鵽��ѧ��\n");
	system("pause");
	system("cls");
	printf("   ѧ����Ϣ����\n");
	printf("=============================\n");
	printf("1.�޸ĸ�ѧ����רҵ\n");
	printf("2.�޸ĸ�ѧ����סַ\n");
	printf("3.�޸ĸ�ѧ���ļ���\n");
	printf("4.�޸ĸ�ѧ��������\n");
	printf("0.������һ��\n");
	printf("���������ѡ��[ ]\b\b");
	choice = get_choice(0,4);
	printf("�Ƿ����y/n:");
	GETS(p);
	if(strcmp(p,"n")==0||strcmp(p,"N")==0)
		return;
	switch(choice)
	{
		case 0:
			return;
			break;
		case 1:
			printf("������רҵ���޸����ѧ����רҵ:");
			GETS(MyStudent[i].Stu_Major);
			break; 
		case 2:
			printf("�������ַ���޸����ѧ���ĵ�ַ:");
			GETS(MyStudent[i].Stu_Address);
			break;
		case 3:
			printf("�����뼮�����޸����ѧ���ļ���:");
			GETS(MyStudent[i].Stu_Naplace);
			break;
		case 4:
			printf("�������������޸ĸ�ѧ��������:");
			GETS(MyStudent[i].Stu_Nation);
			break;
		default:printf("Error!\n"); break; 
	}
	printf("�޸ĳɹ�!\n");
	system("pause");
 } 

