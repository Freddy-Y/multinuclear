
/*全局变量实现进程的同步实现线程的同步的实例*/

#include <windows.h> 
#include <iostream> 
using namespace std;
int globalvar = false;//全局
DWORD WINAPI ThreadFunc(LPVOID pParam)
{
	cout << "ThreadFunc" << endl;
	Sleep(200);
	globalvar = true;
	return 0;
}
int main()
{
	HANDLE hthread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
	if (!hthread)
	{
		cout << "Thread Create Error ! " << endl;
		CloseHandle(hthread);
	}
	while (!globalvar)
		cout << "Thread while" << endl;
	cout << "Thread exit" << endl;
	return 0;
}
