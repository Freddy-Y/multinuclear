#include<windows.h>
#include<iostream>

using namespace std;

DWORD WINAPI FunOne(LPVOID param)
{
	while (true)
	{
		Sleep(1000);
		cout << "                      Hello" << endl;
	}
	return 0;
}

DWORD WINAPI FunTwo(LPVOID param)
{
	while (true)
	{
		Sleep(1000);
		cout << "                     word" << endl;
	}
	return 0;
}


/*
int main(int argc, char *argv[])
{
	
	int input = 0;

	int flag = 0;
	HANDLE hand1 = CreateThread(NULL, 0, FunOne, (void *)&input, CREATE_SUSPENDED, NULL);
	HANDLE hand2 = CreateThread(NULL, 0, FunTwo, (void *)&input, CREATE_SUSPENDED,NULL);
	while (flag!=1)
	{
		cout << "输入线程方式：" << endl;
		cin >> input;
		cout << "输入是否结束1表示结束" << endl;
		cin >> flag;
		if (input == 1)
		{
			ResumeThread(hand1);
			ResumeThread(hand2);
		}
		else
		{
			SuspendThread(hand1);
			SuspendThread(hand2);
		}
	}
	TerminateThread(hand1,1);
	TerminateThread(hand2,1);
	system("pause");
	return 0;
}
*/