#include "cpp.cpp"
#include<windows.h>
using namespace std;
string sen = "��ӭ�������MSDOS��Ϸ!";
int main()
{
    string temp;
    printf("�����������!");
    getline(cin,temp);
    player p;
    p.upName(temp);
    system("cls");
    for(int i=0;i<sen.length();i++)
    {
        cout<<sen[i];
        Sleep(100);
    }
    return 0;
}
