#include "cpp.cpp"
#include<Windows.h>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
string sen = "��ӭ�������MSDOS��Ϸ!";
int main()
{
	string temp;
	int stat;
	printf("�����������!\n");
	getline(cin,temp);
	player p;
	p.upName(temp);
	system("cls");
	for(int i=0; i<sen.length(); i++)
	{
		cout<<sen[i];
		Sleep(100);
	}
	system("cls");
	while(true)
	{
		printf("\t��ӭ����DOS-RPG!\n");
		printf("������\n1�������ȡ����\n2����������\n0���˳�\n");
		printf("���������: ");
		scanf("%d",&stat);
		if(stat == 1)
		{

		}
		else if(stat == 2)
		{

		}
		else if(stat == 0)
		{
			//�����ļ�
			exit(0);
		}
		else
		{
			printf("����Ĳ�������\n"); 
			system("pause"); 
			system("cls");
		}
	}
	return 0;
}
