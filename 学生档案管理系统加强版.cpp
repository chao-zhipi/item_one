#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//用数组保存学生信息

#define MAX 1000 //最大学生数量
#define MAX_UINT ((2*2147483647)-1)//无符号整形最大值
#define  STDOUTPUT(a) "%-10d\t%-5s\t\t%-10s\t\%-10s\t%-10s\t%-10s\t%-15s\n\n",MyStudent[a].Stu_Num,MyStudent[a].Stu_Name,MyStudent[a].Stu_Sex,MyStudent[a].Stu_Major,MyStudent[a].Stu_Naplace,MyStudent[a].Stu_Nation,MyStudent[a].Stu_Address//格式化输出 
#define _STDOUTPUT "学号\t\t姓名\t\t性别\t\t专业\t\t籍贯\t\t民族\t\t住址\n"
//fflush(stdin)的作用和getchar()相似 
#define GETS(a) fflush(stdin); gets(a)//用来输入字符串 
typedef  unsigned int UINT ;  //typedef 的作用是给已知的类型定义一个别名,此处含义是给unsigned int 类型取个别名为UINT

//声明一个student结构体模板，同时给该结构体取个别名Student
typedef struct student
{
	UINT Stu_Num; //学生学号 
	char Stu_Name[20]; //学生名字 
	char Stu_Sex[20]; //学生性别 
	char Stu_Major[20]; //学生专业
	char Stu_Naplace[20];//学生籍贯
	char Stu_Nation[20];//学生民族
	char Stu_Address[20];//学生住址 
}Student;

Student MyStudent[MAX];//全局变量,学生数组
static UINT Amount=0;//Amount变量用来保存当前学生的数量


//函数声明部分
void menu_show();//用来显示菜单
UINT get_choice(UINT a,UINT b); //用来读取一个介于a到b之间的整数值
void Student_add();  //向学生列表中增加一条新的学生信息
void Student_find();  //从当前学生列表中查询是否有这个学生 
void Student_del();   //实现学生信息的删除 
void Student_print(); //显示当前列表中的所有学生信息
void Student_change(); //学生信息的修改 
void SearchByNum(UINT num);//查询通过学号 
void SearchByName(char*);// 查询通过名字 
bool IsReiteration(UINT); //判断输入的学号是否重复


//定义主函数 
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
				printf("谢谢你的使用，再见！\n");
				system("pause");//调用系统pause命令，实现在命令行上输出一行文字，等待用户按一个键，然后返回。
				exit(0);  //正常结束程序运行
				break;
			default: printf("Error!\n"); break; 	
		}
	}
	return 0;
}



//定义menu_show();实现显示菜单 
void menu_show()
{
	printf("   欢迎来到学生档案管理系统!  \n");
	printf("=============================\n");
	printf("   1.学生信息的采集 \n");
	printf("   2.学生信息的查询 \n");
	printf("   3.学生信息的删除 \n");
	printf("   4.学生信息的显示 \n");
	printf("   5.学生信息的修改 \n");
	printf("   0.退出管理系统 \n");
	printf("=============================\n");
	printf("   请选择0-5: ");
}

/* 定义get_choice()实现用来扫描键盘输入，将一个介于a到b之间的整数值返回
若输入的值不在[a,b]之间，则显示欢迎界面，重新输入 */
UINT get_choice(UINT a,UINT b)
{
	UINT i=0;
	while(scanf("%d",&i)!=1||i<a||i>b)
	{
		system("cls");
		printf("输入错误！请输入数字\n");
		system("pause");
		system("cls");
		fflush(stdin);
		printf("请重新输入学号:");
	}
	return i;
}



//定义 SearchByNum(UINT num)实现通过学号查找学生 
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
		printf("你输入的学生学号错误!\n");
		system("pause");
		return;
	}
	else printf("\n查询到了%d个学生与你所搜素的相对应\n",count);
	system("pause"); 
}


//定义SearchByname() 实现通过名字查找学生 
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
		printf("你输入的名字错误！\n");
		system("pause");
		return;
	}
	printf("\n\n查到符合条件的%d个学生\n",count);
	system("pause");
	
} 


//定义IsReiteration(UINT)实现判断学号是否重复
bool IsReiteration(UINT p)
{
	for (UINT i=0;i<Amount;++i)
	{
		if (p==MyStudent[i].Stu_Num)
			return true;
	}
	return false;
 }  





//定义Student_add()实现成员的添加
void Student_add()
{
	while(1) 
	{
		system("cls");
		printf("学生学号:");
		char p[2];//保留用户选择 
		MyStudent[Amount].Stu_Num = get_choice(1,MAX_UINT);
		if(IsReiteration(MyStudent[Amount].Stu_Num))
		{
			printf("你输入的学号重复!\n");
			system("pause");
			return;
		}
		printf("学生姓名:");
		GETS(MyStudent[Amount].Stu_Name);
		printf("学生性别:");
		GETS(MyStudent[Amount].Stu_Sex);
		printf("学生专业:");
		GETS(MyStudent[Amount].Stu_Major);
		printf("学生籍贯:");
		GETS(MyStudent[Amount].Stu_Naplace);
		printf("学生民族:");
		GETS(MyStudent[Amount].Stu_Nation);
		printf("学生住址:");
		GETS(MyStudent[Amount].Stu_Address);
		Amount++;
		printf("添加学生信息成功\n"); 
		printf("是否继续添加y/n:");
		GETS(p);
		if(strcmp(p,"n")==0||strcmp(p,"N")==0)
			return;
	}
}


//定义Student_find()实现学生成员的查询
void Student_find()
{
	UINT choice = 0;//保存用户选择 
	UINT pnum = 0;
	char pname[40];
	while(1)
	{
		system("cls");
		printf("   学生查询\n");
		printf("=============================\n");
		printf("   1.By学号\n");
		printf("   2.By姓名\n");
		printf("   0.返回上一级\n");
		printf("请输入你的选择(0~2)[ ]\b\b");
		choice = get_choice(0,2);
		switch(choice)
		{
			case 0:
				return;
				break;
			case 1:
				system("cls");
				printf("请输入学号:");
				pnum = get_choice(1,MAX_UINT);
				SearchByNum(pnum);
				break;
			case 2:
				system("cls");
				printf("请输入名字:");
				GETS(pname);
				SearchByname(pname);
				break;
			default: printf("你输入错误!\n");
			break; 
		 } 
	} 
	system("cls");

} 


//定义Student_del()实现学生信息的删除
void Student_del()
{
	UINT num=0;
	UINT i;
	printf("请输入需要删除的学生学号:");
	num = get_choice(1,MAX_UINT); 
	for(i=0;i<Amount;++i)
	{
		if(num==MyStudent[i].Stu_Num)
			break;
		else 
		{
			printf("你输入的学号不存在\n");
			system("pause");
			return;
		}
	}
	for(UINT j=i;j<Amount-1;j++)
		MyStudent[j] = MyStudent[j+1];
	printf("删除学生档案成功\n");
	Amount--;
	system("pause");
 } 




//定义Student_print()实现显示学生的信息
void Student_print()
{
	printf(_STDOUTPUT);
	for(UINT i=0;i<Amount;++i)
		printf(STDOUTPUT(i));
	printf("共有%d个学生\n",Amount);
	system("pause");

} 



//定义Student_change()实现更改学生信息功能
void Student_change()
{
	UINT num;//暂时保存学生学号 
	UINT choice;//保留用户选择 
	UINT i;
	char p[2];
	printf("请输入学号修改该学生的相关信息:");
	num = get_choice(1,MAX_UINT);
	for(i=0;i<Amount;++i)
	{
		if(num==MyStudent[i].Stu_Num)
			break;
		else
		{
			printf("你输入的学号不存在\n");
			system("pause");
			return; 
		 } 
	}
	printf("已查到该学生\n");
	system("pause");
	system("cls");
	printf("   学生信息更改\n");
	printf("=============================\n");
	printf("1.修改该学生的专业\n");
	printf("2.修改该学生的住址\n");
	printf("3.修改该学生的籍贯\n");
	printf("4.修改该学生的民族\n");
	printf("0.返回上一级\n");
	printf("请输入你的选择[ ]\b\b");
	choice = get_choice(0,4);
	printf("是否继续y/n:");
	GETS(p);
	if(strcmp(p,"n")==0||strcmp(p,"N")==0)
		return;
	switch(choice)
	{
		case 0:
			return;
			break;
		case 1:
			printf("请输入专业以修改这个学生的专业:");
			GETS(MyStudent[i].Stu_Major);
			break; 
		case 2:
			printf("请输入地址以修改这个学生的地址:");
			GETS(MyStudent[i].Stu_Address);
			break;
		case 3:
			printf("请输入籍贯以修改这个学生的籍贯:");
			GETS(MyStudent[i].Stu_Naplace);
			break;
		case 4:
			printf("请输入民族以修改该学生的民族:");
			GETS(MyStudent[i].Stu_Nation);
			break;
		default:printf("Error!\n"); break; 
	}
	printf("修改成功!\n");
	system("pause");
 } 

