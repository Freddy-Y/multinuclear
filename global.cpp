
/*ȫ�ֱ���ʵ�ֽ��̵�ͬ��ʵ���̵߳�ͬ����ʵ��*/

#include <windows.h> 
#include <iostream> 
using namespace std;
int globalvar = false;//ȫ�ֱ����Ķ���
DWORD WINAPI ThreadFunc(LPVOID pParam)  //�̺߳��� ���ܣ�����ַ�����ͦ200���룬����ȫ�ֱ���Ϊtrue
{
	cout << "ThreadFunc ���߳̿�ʼ����" << endl;
	Sleep(2000);
	globalvar = true;
	return 0;
}

/*
int main()
{
	HANDLE hthread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);  //�����̣߳����ؾ��
	Sleep(1000);
	if (!hthread)//�쳣�ж�
	{
		cout << "Thread Create Error ! " << endl;
		CloseHandle(hthread);
	}
	while (!globalvar)
		cout << "Thread while  ���ڴ������߳�......" << endl;
	cout << "Thread exit ���̴߳������" << endl;
	system("pause");
	return 0;
}
*/