
#include<windows.h>
#include<iostream>
#include<process.h>
#include<fstream>
#include<time.h>
#include<math.h>

using namespace std;

float  m=10000;
float n=2;
float count1,count2;
HANDLE evList[2];

DWORD WINAPI CreatePoint1(LPVOID param)
{
	cout << "线程1正字执行~" << endl;
	float x, y;
	count1 = 0;
	float num = m / n;
	srand(time(0));
	for (int i = 0; i <num ; i++)
	{		
		x = (float)rand() / RAND_MAX;
		y = (float)rand() / RAND_MAX;
		cout << pow(x, 2) + pow(y, 2) << endl;
		if (pow(x, 2) + pow(y, 2)<=1)
		{
			count1++;
		}
	}
	SetEvent(evList[0]);
	return 0;
}
DWORD WINAPI CreatePoint2(LPVOID param)
{
	cout << "线程2正字执行~" << endl;
	float x, y;
	count2 = 0;
	float num = m / n;
	srand(time(0));
	for (int i = 0; i <num; i++)
	{
		x = (float)rand() / RAND_MAX;
		y = (float)rand() / RAND_MAX;
		cout << pow(x, 2) + pow(y, 2) << endl;
		if (pow(x,2)+pow(y,2)<=1)
		{
			count2 ++;
		}
	}
	SetEvent(evList[1]);
	return 0;
}
/*
int main()
{
	float count = 0;
	float res;
	evList[0]=CreateEvent(NULL,false,false,NULL);
	evList[1] = CreateEvent(NULL, false, false, NULL);
	HANDLE hand1 = CreateThread(NULL, 0, CreatePoint1, NULL, NULL, NULL);
	HANDLE hand2 = CreateThread(NULL, 0, CreatePoint2, NULL, NULL, NULL);
	WaitForMultipleObjects(2,evList,TRUE,INFINITE);
	count = count1 + count2;
	res = count /m *4;
	cout << "完毕" << endl;
	cout << count << endl;
	cout << res;

	system("pause");
	return 0;
}
*/