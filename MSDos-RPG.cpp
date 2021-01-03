#include "includeme.h"
#define fin cin
#define fout cout
using namespace std;
void GameInit();
bool ctrlhandler(DWORD);
void GameExit();
void setPos(int, int);
void rands();
void listQuest();
void intomap();
const int events = 2;
string title;
string sen = "��ӭ�������MSDOS��Ϸ!";
player p;
int *ip = NULL; //����item��getAdds��getSpecails
int main()
{
	GameInit();
	string temps;
	int tempi;
	int stat;
	printf("�����������!\n");
	getline(cin, temps);
	//p.setName(temps);
	p.name = temps;
	ifstream fin("gamefile/SAVE.file");
	getline(fin, temps);
	p.name = temps;
	//p.setName(temps);
	while (fin >> tempi)
	{
		p.newQuest(tempi);
	}
	fin.close();
#define fin cin
	system("cls");
	setPos(32, 32);
	for (int i = 0; i < sen.length(); i++)
	{
		cout << sen[i];
		Sleep(100);
	}
	setPos(32, 25);
	system("pause");
	system("cls");
	while (true)
	{
		p.setState(1);
		setPos(32, 0);
		printf("\t��ӭ����%s!\n",title.c_str());
		cout << "�����:" << p.name << endl;
		printf("������\n1����������\n2�������ȡ����\n3�������ͼ\n0���˳�\n");
		printf("���������: ");
		scanf("%d", &stat);
		if (stat == 1)
		{
			listQuest();
		}
		else if (stat == 2)
		{
			rands();
		}
		else if (stat == 3)
		{
			intomap();
		}
		else if (stat == 0)
		{
			//�����ļ�
			/*ofstream fout("SAVE.file");
			fout << p.name << endl;
			for (int i = 0; i < 15; i++)
			{
				fout << p.questf(i) << " ";
			}
			fout.close();
			#define fout cout
			exit(0);*/
			GameExit();
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
	tempi = rdm % 10;
	p.newQuest(tempi);
	cout << "����ȡ����: " << tempi << ":" << p.questName(tempi) << endl;
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
	int tempi;
	unsigned rdm;
	enemy monster(p);
	system("cls");
	printf("-1������\n0������������");
	scanf("%d", &stat);
	if (stat == -1)
	{
		//������Ե�ͼ
		printf("0���˳�\n1��ǰ\n2����\n3����\n4����\n");
		printf("���������");
		scanf("%d", &stat);
		if (stat == 0)
		{
			return;
		}
		else if (!(stat > 4))
		{
			//ˢ��
			srand(time(NULL));
			rdm = rand();
			tempi = rdm % events;
		}
		else
		{
			printf("����Ĳ�������");
		}
	}
	else if (stat == 0)
	{
		system("cls");
		return;
	}
	else
	{
		printf("�޸õ�ͼ��\n");
	}
}

void GameInit()
{
	ifstream inSets("settings.ini");
	getline(inSets,title);
	string temps="title ";
	temps += title;
	system("mode con cols=100 lines=30");
	system(temps.c_str());
	printf("����������Ϸ...\n");
	Sleep(500);
	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)ctrlhandler, true))
	{
		/*
        printf( "\nthe control handler is installed.\n" ); 
        printf( "\n -- now try pressing ctrl+c or ctrl+break, or" ); 
        printf( "\n try logging off or closing the console...\n" ); 
        printf( "\n(...waiting in a loop for events...)\n\n" );
        */
		/*while( 1 ){ Sleep(100);}*/
		printf("Control Hanler�����ɹ�!\n");
		Sleep(300);
		system("cls");
	}
	else
	{
		MessageBox(NULL, TEXT("\nFatal��������:�޷����ÿؼ��������(Control Handler)\n"), TEXT(title.c_str()), MB_OK | MB_ICONERROR);
		system("pause");
		exit(1);
	}
}

bool ctrlhandler(DWORD fdwctrltype)
{
	switch (fdwctrltype)
	{
	// handle the ctrl-c signal.
	case CTRL_C_EVENT:
		//printf( "ctrl-c event\n\n" );
		//GameExit();
		MessageBox(NULL, TEXT("�벻Ҫʹ��Ctrl-C�ر���Ϸ��"), TEXT(title.c_str()), MB_OK | MB_ICONWARNING);
		return false;

	// ctrl-close: confirm that the user wants to exit.
	case CTRL_CLOSE_EVENT:
		//printf( "ctrl-close event\n\n" );
		GameExit();
		return true;

	// pass other signals to the next handler.
	case CTRL_BREAK_EVENT:
		//printf( "ctrl-break event\n\n" );
		//GameExit();
		MessageBox(NULL, TEXT("�벻Ҫǿ���˳���Ϸ��"), TEXT(title.c_str()), MB_OK | MB_ICONWARNING);
		return false;

	case CTRL_LOGOFF_EVENT:
		//printf( "ctrl-logoff event\n\n" );
		GameExit();
		return false;

	case CTRL_SHUTDOWN_EVENT:
		//printf( "ctrl-shutdown event\n\n" );
		GameExit();
		return false;

	default:
		return false;
	}
}

void setPos(int x, int y) //���ù��λ��
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

void GameExit()
{
	MessageBox(NULL, TEXT("�����˳���Ϸ..."), TEXT(title.c_str()), MB_OK | MB_ICONINFORMATION);
	//�����ļ�
	ofstream fout("gamefile/SAVE.file");
	fout << p.name << endl;
	for (int i = 0; i < 15; i++)
	{
		fout << p.questf(i) << " ";
	}
	fout.close();
#define fout cout
	exit(0);
}
