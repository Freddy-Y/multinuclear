/*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<iostream>
#include<windows.h>

using namespace std;
#define count 100;


DWORD WINAPI Even(LPVOID param)
{
	int a = (int)param;
	cout << a << endl;
	return 0;
}
int main()
{
	
	srand(time(NULL));
	int i;
	float r;
	for (i = 0; i<50; i++)
	{
		r = (float)rand() / RAND_MAX;
		printf("%f\n", r);
	}
	float a = 0.8765;
	if (a < 1)
		cout << "111111111" << endl;
	
	srand(time(NULL));
	int num[100];
	for (int i = 0; i < 100; i++)
	{
		num[i] = (int)rand();
	}
	for (int j = 0; j < 100; j++)
	{
		cout << "  " << endl;
		cout << num[j] << endl;
	}
	
	int i = 10;
	HANDLE hand = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Even, (LPVOID)i, NULL, NULL);

	

	system("pause");
	return 0;
}

*/