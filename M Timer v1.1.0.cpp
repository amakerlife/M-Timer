#include <bits/stdc++.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>

#define START 1
#define EXIT 2
#define ll long long
#define ull unsigned long long
#define INF 0x7fffffff
#define mod 1000000007
#define bug(x) cout<<"Bug "<<(x)<<endl
#define el cout<<endl
using namespace std;
//HWND consoleWindowHandle = GetConsoleWindow();
//using System;

//using System.Collections.Generic;
//
//using System.Linq;
//
//using System.Text;
//
//using System.Threading.Tasks;
//
//using System.Threading;


void Add(HWND);

HWND edit, show;

int Time;
bool flag, running;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_DESTROY:
        exit(0);
        break;
    case WM_COMMAND:
        switch (wp) {
        case START:
            flag = 0;
            char tim[10];
            GetWindowText(edit, tim, 10);

            for (int i = 0; tim[i]; i++)
                if (!(tim[i] >= '0' && tim[i] <= '9'))
                {
                    SetWindowText(show, "Please input the correct time.");
                    flag = 1;
                }

            if (!flag)
            {
                SetWindowText(show, tim);
                if (!running)
                    running = 1, Time = atoi(tim);

                char show_text[10] = {0};

                for (int i = 0; i <= 4 && running && Time >= -1; i++)
                {
                    itoa(Time, show_text, 10);
                    SetWindowText(show, show_text);
                    Sleep(1000);
                    Time--;

                    if (Time == -1)
                        running = 0;
                }
            }
            break;
        case EXIT:
            exit(0);
            break;
        }
        break;
    case WM_CREATE:
        Add(hwnd);
        break;
    default:
        return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrvIns, LPSTR args, int cmdShow) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hIns;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = "wnd";
    RegisterClass(&wc);
    CreateWindow("wnd", "Count Down", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, NULL, NULL);
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

void Add(HWND hwnd) {
    CreateWindow("button", "Start", WS_CHILD | WS_VISIBLE, 150, 250, 80, 50, hwnd, (HMENU)START, NULL, NULL);
    show = CreateWindow("static", "", WS_CHILD | WS_VISIBLE, 150, 100, 200, 100, hwnd, NULL, NULL, NULL);
    CreateWindow("button", "Quit", WS_CHILD | WS_VISIBLE, 270, 250, 80, 50, hwnd, (HMENU)EXIT, NULL, NULL);
    CreateWindow("static", "Input time (Second): ", WS_CHILD | WS_VISIBLE, 35, 200, 90, 90, hwnd, NULL, NULL, NULL);
    edit = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE, 150, 200, 100, 20, hwnd, NULL, NULL, NULL);
}
void SetConsoleSize(int x, int y, int cols, int lines)
{
    HANDLE hOut;
    CONSOLE_FONT_INFO consoleCurrentFont;
    COORD bufferSize,fontSize;
    TCHAR title[256];
    HWND hWnd;
    //Set console buffer size
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFont(hOut, false, &consoleCurrentFont);
    fontSize = GetConsoleFontSize(hOut,consoleCurrentFont.nFont);
    bufferSize.X = cols;
    bufferSize.Y = lines;
    SetConsoleScreenBufferSize(hOut, bufferSize);
    //Set console window size
    GetConsoleTitle(title, 256);
    hWnd = FindWindow(0, title);
    MoveWindow(hWnd,x,y,(cols+4)*fontSize.X,(lines+2)*fontSize.Y,true);
}
int main() {
//	system("mode 120,40");
//	int starta=clock();
	SetConsoleSize(20,20,60,10);
	system("title M Timer  By Makerlife");
	cout<<"欢迎使用 M Timer v1.1.0"<<endl;
	cout<<"输入1置顶窗口，输入其他数字以继续>> ";
	int zhiding;
	cin>>zhiding;
	cout<<"输入1进入计时器，输入其他数字进入倒计时>> ";
	int moshi;
	cin>>moshi;
	SetConsoleSize(20,20,50,10);
	if(zhiding==1)
	{
		HWND hWnd = ::GetForegroundWindow();
		::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 100, 100, SWP_NOMOVE | SWP_NOSIZE);
	}
	if(moshi==1)
	{
		system("title M Timer  By Makerlife");
		int h=0, m=0, s=0;
		int starta=clock();
		while(1)
		{
			int output=INF,tmpoutput=INF;
			int enda=clock();
			s=(enda-starta)/1000;
			output=s;
			if(tmpoutput!=output)
			{
				tmpoutput=s;
			}
			else continue;
			while(s>=60)
			{
				s-=60;
			}
			system("cls");
//			printf("计时器模式\n");
			printf("%d:%d:%d\n", h, m, s);
			s++;
			if(s==60)
			{
				m++;
				s=0;
				Sleep(900);
			}
			if(m==60)
			{
				h++;
				m=0;
				Sleep(900);
			}
			Sleep(50);
		}
	}
	system("title M Timer  By Makerlife");
	system("cls");
    int h, m, s,ss;
    printf("hour(s) = ");
    scanf("%d", &h);
    printf("minute(s) = ");
    scanf("%d", &m);
    while(m>=60)
    {
		h++;
		m-=60;
	}
    printf("second(s) = ");
    scanf("%d", &s);
    ss=s+m*60+h*3600;
    while(s>=60)
    {
		m++;
		s-=60;
	}
	while(m>=60)
    {
		h++;
		m-=60;
	}
	while(1)
	{
//		double n;
//		n=clock();
//		cout<<n<<endl;
		system("cls");
		printf("倒计时模式\n");
		printf("Time Left: %d:%d:%d\n", h, m, s);
		if(h==0 && m==0 && s==2)
		{
			system("color 6F");
//			HWND hWnd = ::GetForegroundWindow();
//			cout<<hWnd<<endl;
//			::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 100, 100, SWP_NOMOVE | SWP_NOSIZE);
		}
		if(h==0 && m==0 && s==1)
		{
			system("color CF");
		}
		if(h==0 && m==0 && s==0)
		{
			system("title [时间到！]M Timer  By Makerlife");
			system("color 4F");
    		cout<<"TIME UP!";
			printf("\n");
//			Beep(523, 400);
//			Beep(578, 400);
//			Beep(659, 400);
			while(1)
			{
				Sleep(300);
				system("color 0F");
				Sleep(300);
				system("color 4F");
			}
			system("pause");
			return 0;
		}
		int output=INF,tmpoutput=INF;
		output=s;
		if(tmpoutput!=output)
		{
			tmpoutput=s;
		}
		else continue;
//		if(s==0 && m!=0) m--,s=59;
		s--;
		if(s==-1) m--,s=59;
		if(m==-1 && h!=0) h--,m=59;
		Sleep(1000);
	}

//    SYSTEMTIME sys, temp;
//    GetLocalTime(&sys);
//    sys.wHour += h;
//    sys.wMinute += m;
//    sys.wSecond += s;
//    if (sys.wSecond >= 60) {
//        sys.wSecond -= 60;
//        sys.wMinute++;
//    }
//    if (sys.wMinute >= 60) {
//        sys.wMinute -= 60;
//        sys.wHour++;
//    }
//    if (sys.wHour >= 24) {
//        return 0;
//    }
//    system("cls");
////    printf("hour(s) = %d\n\nminute(s) = %d\n\nsecond(s) = %d", h, m, s);
////    Sleep(1000);
////    printf("\n");
//    while (true) {
//    	system("cls");
//    	printf("Time Left: %d:%d:%d", h, m, s);
//    	if(h==0 && m==0 && s==0)
//    	{
//    		Beep(523, 400);
//    		system("cls");
////					s--;
//					printf("Time Left: %d:%d:%d", h, m, s);
//                    Beep(578, 400);
////                    s--;
////					printf("Time Left: %d:%d:%d", h, m, s);
//                    Beep(659, 400);
////                    s--;
////					printf("Time Left: %d:%d:%d", h, m, s);
//					printf("\n");
//                    system("pause");
//                    return 0;
//		}
//    	if(s==0 && m!=0) m--,s=60;
//    	s--;
//    	if(s==0 && m!=0) m--,s=60;
//    	else if(m==0 && h!=0) h--,m=60;
//    	Sleep(1000);
//    	printf("\n");
//        GetLocalTime(&temp);
//        if (sys.wHour == temp.wHour) {
//            if (sys.wMinute == temp.wMinute) {
//                if (sys.wSecond == temp.wSecond) {
//                    Beep(523, 400);
//                    system("cls");
////					s--;
//					printf("Time Left: 0:0:0\n");
//                    Beep(578, 400);
////                    s--;
////					printf("Time Left: %d:%d:%d", h, m, s);
//                    Beep(659, 400);
////                    s--;
////					printf("Time Left: %d:%d:%d", h, m, s);
//                    system("pause");
//                    return 0;
//                }
//            }
//        }
//    }
    return 0;
}
