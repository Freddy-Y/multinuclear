
/*全局变量实现进程的同步实现线程的同步的实例*/

#include <windows.h> 
#include <iostream> 
using namespace std;
int globalvar = false;//全局变量的定义
DWORD WINAPI ThreadFunc(LPVOID pParam)  //线程函数 功能：输出字符串，挺200毫秒，设置全局变量为true
{
	cout << "ThreadFunc 子线程开始创建" << endl;
	Sleep(2000);
	globalvar = true;
	return 0;
}

/*
int main()
{
	HANDLE hthread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);  //创建线程，返回句柄
	Sleep(1000);
	if (!hthread)//异常判断
	{
		cout << "Thread Create Error ! " << endl;
		CloseHandle(hthread);
	}
	while (!globalvar)
		cout << "Thread while  正在创建子线程......" << endl;
	cout << "Thread exit 子线程创建完成" << endl;
	system("pause");
	return 0;
}
*/