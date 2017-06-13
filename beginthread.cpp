//#include"stdafx.h"
#include<windows.h>
#include<process.h> //声明的C执行时期链接库函数_beginthread.具体语法hThread=_beginthread(void (_cdecl * start_address)(void *),unsigned stack_size,void *arglist); 参数为线程函数，线程栈的大小，线程参数
//创建线程可以用win32函数库提供的线程创建函数，名为HANDEL CreateThread（）；其中六个参数
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
功能总结：在创建线程后，本程序内一直存在，从开始执行，先输出线程一的内容，到线程二sleep的时间到时输出线程二的内容
程序的扩展，线程一按秒计时，线程二按分钟，

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
		cout << min << "分：" << sec << "秒" << endl;
	}
	system("pause");
	return 0;

}
*/