#include<windows.h>
#include<process.h>
#include<iostream>
#include<fstream>

using namespace std;

HANDLE evRead, evFinish;
void ReadThread(LPVOID param)
{
	WaitForSingleObject(evRead,INFINITE);//ʼ��δ����
	/*���ָ��һ������ֵ���������ڵȴ�״ֱ̬��hHandle��ǵĶ��󱻴���������ʱ�䵽�ˡ�
	���dwMillisecondsΪ0������û�б������źţ������������һ���ȴ�״̬���������������ء�
	���dwMillisecondsΪINFINITE�����󱻴����źź󣬺����Ż᷵�ء�*/

	cout << "Reading......" << endl;
	Sleep(2000);
	SetEvent(evFinish);
}

void WriteThread(LPVOID param)
{
	cout << "Writing......" << endl;
	Sleep(3000);
	SetEvent(evRead);//д�������,����evRead�¼�����Ϊtrue��������ִ�ж�����
}
/*
int main(int argc,char *argv[])
{
	evRead = CreateEvent(NULL,FALSE,FALSE,NULL);  //�ڶ�������false��ʾ�Զ�
	evFinish = CreateEvent(NULL,FALSE,FALSE,NULL);

	_beginthread(ReadThread,0,NULL);  //�����߳�
	_beginthread(WriteThread, 0, NULL);

	WaitForSingleObject(evFinish,INFINITE);
	cout << "The Program is End" << endl;
	system("pause");

	return 0;
}
*/