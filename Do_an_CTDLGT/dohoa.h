#include <string>
using namespace std;
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);                       //doi mau chu
	SetConsoleTextAttribute(mau, x);
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);             // set toa do
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void coutcolor(int x, int y, int color, string s)
{
	gotoxy(x,y);
	textcolor(color);                                                // in mau
	cout<<s;
}

void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);                           // xoa man hinh
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void Nocursortype()
{                                                                               // xoa con tro chuot
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void thoigian()
{                                                                                      // thiet lap thoi gian thuc(hien tai)
	tm current_time;
    time_t timer =time(NULL);
    current_time = *localtime(&timer);
    gotoxy(95,9); textcolor(78);
    cout<<current_time.tm_mday<<"/"<<current_time.tm_mon+1<<"/"<<current_time.tm_year+1900<<endl;
	gotoxy(131,9); textcolor(124);
    cout<<current_time.tm_hour<<":"<<current_time.tm_min<<":"<<current_time.tm_sec<<"    "<<endl;
    current_time.tm_sec+=1209600;
    mktime(&current_time);
    //cout<<current_time.tm_mday<<":"<<current_time.tm_mon+1<<":"<<current_time.tm_year+1900<<endl;
}

void spacecolor(int x,int y,int size,int color)
{
	gotoxy(x,y);
	for(int i=0;i<size;i++)
	{	
		textcolor(color);//1 -------- 255  (every color distance 16)
		printf(" ");
	}
}

void setScreen()
{
	system("cls");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);                              // thiet lap man hinh
	Nocursortype();
	system("color 72");
}
