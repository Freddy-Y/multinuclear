#include<windows.h>
#include<iostream>
#include<process.h>
#include<fstream>
#include<time.h>
#include<math.h>

using namespace std;

int array[10];
bool flag;
bool YN = false;
HANDLE sEvent, eEvent;
HANDLE handle[5];
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void WINAPI Sing(LPVOID param)
{
	//WaitForSingleObject(sEvent, INFINITE);
	int a = (int)param;
	int b = a / 2 + 1;
	cout <<"传进的参数"<< a << "  要排序的书"<<array[a]<<array[a+1]<<endl;
	if (array[a] > array[a + 1])
	{
		swap(&array[a], &array[a + 1]);
		YN = false;
	}
	cout << "  排序后的数" << array[a] << array[a + 1] << endl;
	SuspendThread(handle[b]);
	//SetEvent(eEvent);
}

void WINAPI Even(LPVOID param)
{
	//WaitForSingleObject(eEvent, INFINITE);
	int a = (int)param;
	int b = a / 2 + 1;
	cout <<a <<endl;
	if (array[a] > array[a + 1])
	{
		swap(&array[a], &array[a + 1]);
		YN = false;
	}
	SuspendThread(handle[b]);
	//SetEvent(sEvent);
}

int main(int argc, char *argv[])
{
	
	//sEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	//eEvent = CreateEvent(NULL, FALSE, TRUE, NULL);
	srand(time(NULL));		//生成随机数
	for (int i = 0; i < 10; i++)
	{
		array[i] = (int)rand()/1000;
		cout << "数列为："<<array[i] << " ";
	}

	Sleep(1000);
	
	while (!YN)
	{
		YN = true;
		for (int i = 0,j=0; i < 10; i+=2,j++)
		{
			cout <<"要传的参数"<< i << endl;
			handle[j] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Sing, (LPVOID)i, NULL, NULL);
			CloseHandle(handle[j]);
		}
		
		for (int i = 1, j = 0; j<4; i += 2, j++)
		{
			handle[j] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Even, (LPVOID)i, NULL, NULL);
			CloseHandle(handle[j]);
		}
		

		for (int j = 0; j < 10; j++)
		{
			cout << array[j] << endl;
		}
		cout << "----------------------------------------------" << endl;
		/*if (!flag)
		{
			break;y
		}*/
	}
	cout << "**********************************" << endl;
	for (int j = 0; j < 10; j++)
	{
		cout << array[j] << endl;
	}
	system("pause");
	return 0;
}
