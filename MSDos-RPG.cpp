#include "includeme.h"
#define fin cin
#define fout cout
using namespace std;
void rands();
void listQuest();
void intomap();
string sen = "��ӭ�������MSDOS��Ϸ!";
player p;
int* ip = NULL;		//����item��getAdds��getSpecails
int main()
{
	string temps;
	int tempi;
	int stat;
	printf("�����������!\n");
	getline(cin,temps);
	//p.setName(temps);
	p.name = temps;
	ifstream fin("SAVE.file");
	getline(fin,temps);
	p.name = temps;
	//p.setName(temps);
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
		p.setState(1);
		printf("\t��ӭ����DOS-RPG!\n");
		cout<<"�����:"<<p.name<<endl;
		printf("������\n1����������\n2�������ȡ����\n3�������ͼ\n0���˳�\n");
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
		else if(stat == 3)
		{
			intomap();
		}
		else if(stat == 0)
		{
			//�����ļ�
			ofstream fout("SAVE.file");
			fout<<p.name<<endl;
			for(int i=0;i<15;i++)
			{
				fout<<p.questf(i)<<" ";
			}
			fout.close();
			#define fout cout
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

void intomap()
{
	int stat;
	system("cls");
	printf("-1������\n0������������");
	scanf("%d",&stat);
	if(stat == -1)
	{
		//������Ե�ͼ
	}
	else if(stat == 0)
	{
		system("cls");
		return;
	}
	else
	{
		printf("�޸õ�ͼ��\n");
	}
}