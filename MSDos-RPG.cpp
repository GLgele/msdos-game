#include "includeme.h"
#define fin cin
#define fout cout
using namespace std;
void rands();
void listQuest();
string sen = "��ӭ�������MSDOS��Ϸ!";
player p;
int main()
{
	string temps;
	int tempi;
	int stat;
	printf("�����������!\n");
	getline(cin,temps);
	p.upName(temps);
	ifstream fin("SAVE.file");
	//fin>>temps;
	//p.upName(temps);
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
		p.upState(1);
		printf("\t��ӭ����DOS-RPG!\n");
		//cout<<"�����:"<<p.name<<endl;
		printf("������\n1����������\n2�������ȡ����\n0���˳�\n");
		printf("���������: ");
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
			//�����ļ�
			ofstream fout("SAVE.file");
			//fout<<p.name<<endl;
			for(int i=0;i<15;i++)
			{
				fout<<p.questf(i)<<" ";
			}
			fout.close();
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
	cout<<"����ȡ����: "<<tempi<<":"<<p.questName(tempi)<<endl;
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
