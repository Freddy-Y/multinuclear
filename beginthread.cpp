//#include"stdafx.h"
#include<windows.h>
#include<process.h> //������Cִ��ʱ�����ӿ⺯��_beginthread.�����﷨hThread=_beginthread(void (_cdecl * start_address)(void *),unsigned stack_size,void *arglist); ����Ϊ�̺߳������߳�ջ�Ĵ�С���̲߳���
//�����߳̿�����win32�������ṩ���̴߳�����������ΪHANDEL CreateThread������������������
#include<iostream>
#include<fstream>

using namespace std;


int min = 0;
int sec = 0;
void ThreadFunc1(PVOID param)
{
	while (1)
	{
		Sleep(500);
		cout << "This is ThreadFunc1" << endl;
	}
}

void ThreadFunc2(PVOID param)
{
	while (1)
	{
		Sleep(1000);
		cout << "This is ThreadFunc2" ;
	}
}

void ThreadFunc3(PVOID param)
{
	while (1)
	{
		Sleep(1000);
		if (sec < 59)
		{
			sec++;
		}
		else
		{
			sec = 0;
		}
	}
}
void ThreadFunc4(PVOID param)
{
	while (1)
	{
		Sleep(60000);
		if (min < 60)
		{
			min++;
		}
		else
		{
			min = 0;
		}
	}
}
/*
�����ܽ᣺�ڴ����̺߳󣬱�������һֱ���ڣ��ӿ�ʼִ�У�������߳�һ�����ݣ����̶߳�sleep��ʱ�䵽ʱ����̶߳�������
�������չ���߳�һ�����ʱ���̶߳������ӣ�

*/


/*
int main()
{
	int i = 0;
	_beginthread(ThreadFunc3, 0, NULL);
	_beginthread(ThreadFunc4, 0, NULL);
	while (1)
	{
		Sleep(1000);
		cout << min << "�֣�" << sec << "��" << endl;
	}
	system("pause");
	return 0;

}
*/