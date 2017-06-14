#include<windows.h>
#include<process.h>
#include<iostream>
#include<fstream>

using namespace std;

HANDLE evRead, evFinish;
void ReadThread(LPVOID param)
{
	WaitForSingleObject(evRead,INFINITE);//始终未激活
	/*如果指定一个非零值，函数处于等待状态直到hHandle标记的对象被触发，或者时间到了。
	如果dwMilliseconds为0，对象没有被触发信号，函数不会进入一个等待状态，它总是立即返回。
	如果dwMilliseconds为INFINITE，对象被触发信号后，函数才会返回。*/

	cout << "Reading......" << endl;
	Sleep(2000);
	SetEvent(evFinish);
}

void WriteThread(LPVOID param)
{
	cout << "Writing......" << endl;
	Sleep(3000);
	SetEvent(evRead);//写操作完成,激发evRead事件，变为true，接来下执行读操作
}
/*
int main(int argc,char *argv[])
{
	evRead = CreateEvent(NULL,FALSE,FALSE,NULL);  //第二个参数false表示自动
	evFinish = CreateEvent(NULL,FALSE,FALSE,NULL);

	_beginthread(ReadThread,0,NULL);  //创建线程
	_beginthread(WriteThread, 0, NULL);

	WaitForSingleObject(evFinish,INFINITE);
	cout << "The Program is End" << endl;
	system("pause");

	return 0;
}
*/