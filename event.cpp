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

	cout << "Reading" << endl;
	SetEvent(evFinish);
}

void WriteThread(LPVOID param)
{
	cout << "Writing" << endl;
	SetEvent(evRead);//����evRead�¼�����Ϊtrue
}

int main(int argc,char *argv[])
{
	evRead = CreateEvent(NULL,FALSE,FALSE,NULL);  //�ڶ�������false��ʾ�Զ�
	evFinish = CreateEvent(NULL,FALSE,FALSE,NULL);

	_beginthread(ReadThread,0,NULL);  //�����߳�
	_beginthread(WriteThread, 0, NULL);

	WaitForSingleObject(evFinish,INFINITE);
	cout << "The Program is End" << endl;

	return 0;
}