#include "includeme.h"
#include<Windows.h>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<ctime>
#include<fstream>
using namespace std;
void rands();
void listQuest();
string sen = "欢迎来到这个MSDOS游戏!";
player p;
int main()
{
	#define fin cin
	#define fout cout
	string temps;
	int tempi;
	int stat;
	printf("请输入玩家名!\n");
	getline(cin,temps);
	p.upName(temps);
	ifstream fin("SAVE.file");
	fin>>temps;
	p.upName(temps);
	while(fin>>tempi)
	{
		p.newQuest(tempi);
	}
	fin.close();
	#define fin cin
	system("cls");
	for(int i=0; i<sen.length(); i++)
	{
		cout<<sen[i];
		Sleep(100);
	}
	system("cls");
	while(true)
	{
		printf("\t欢迎来到DOS-RPG!\n");
		cout<<"玩家名:"<<p.name<<endl;
		printf("操作：\n1、任务中心\n2、随机领取任务\n0、退出\n");
		printf("请输入操作: ");
		scanf("%d",&stat);
		if(stat == 1)
		{
			listQuest();
		}
		else if(stat == 2)
		{
			rands();
		}
		else if(stat == 0)
		{
			//保存文件
			ofstream fout("SAVE.file");
			fout<<p.name<<endl;
			for(int i=0;i<15;i++)
			{
				fout<<p.questf(i)<<"　";
			}
			fout.close();
			exit(0);
		}
		else
		{
			printf("错误的操作符！\n"); 
			system("pause"); 
			system("cls");
		}
	}
	return 0;
}

void rands()
{
	unsigned rdm;
	int tempi = 1;
	srand(time(NULL));
	rdm = rand();
	//cout << rand() << endl; 
	//p.newQuest(1);
	//cout<< rdm <<endl;
	tempi = rdm%10;
	p.newQuest(tempi);
	cout<<"已领取任务: "<<tempi<<":"<<p.questName(tempi)<<endl;
	p.checkQuest(tempi);
	system("pause");
	system("cls");
	return;
}

void listQuest()
{
	p.listQuest();
	system("pause");
	system("cls");
	return;
}
