#include <windows.h>
#include <iostream>
#define qdo 262 
#define qre 294
#define qmi 330
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494
#define do 523
#define re 578
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988
#define do1 1046
#define re1 1175
#define mi1 1318
#define fa1 1480
#define so1 1568
#define la1 1760
#define si1 1976
#define sqdo 277
#define sqre 311
#define sqfa 370
#define sqso 415
#define sqla 466
#define sdo 554
#define sre 622
#define sfa 740
#define sso 831
#define sla 932
#define sdo1 1046
#define sre1 1245
#define sfa1 1480
#define sso1 1661
#define sla1 1865

#define p1 400
#define p05 200
#define p2 800

void gotoxy(int x,int y);
void fullscreen();
void clearscreen();
void CoutFlag();
void ColorPrint(const char* s, int color);

using namespace std;
int main()
{
  fullscreen();
  clearscreen();
  double notes [17]
  {
    la,
    do1,
    re1,
    mi1,
    re1,
    do1,
    si,
    la,
    si,
    so,
    la,
    la,
    do1,
    re1,
    re1,
    mi1,
    mi1
  };
  double duration [17]
  {
    p05,
    p05,
    p05,
    p05,
    p1,
    p05,
    p05,
    p05,
    p1,
    p05,
    p2,
    600, //p1.5
    p05,
    p1,
    p05,
    p05,
    1600 //p4
  };

  string kim =
"#################################################\n\
#################%##%%%%%%%%##%##################\n\
################*=--==+==--*####%%##%%%%%%%%%%%%%\n\
#############+                    -%%%%%%%%%%%%%%\n\
###########%*                       +%%%%%%%%%%%%\n\
########%%#%+       .-++***###*+.   =@%%%%%%%%%%%\n\
###%%%%%%%%%=    .:-=+++**#######=  =@@@@@@@@@@@@\n\
%%%%%%%%%%%@+  :--==+***#####%%%%#- #@@@@@@@@@@@@\n\
%%%%%%%%%%%@*:===::--:.=***++=+*#%#*@@@@@@@@@@@@@\n\
%%%%%%%%%@#:-+++=:.. :=-=##+:.:=##%%%@@@@@@@@@@@@\n\
%%%%%%@@@@#:-++=++*****++#%%%*#%%%%*+@@@@@@@@@@@@\n\
%%@@@@@@@@@+-++++++*#*==+*%#*#%%%%%#@@@@@@@@@@@@@\n\
@@@@@@@@@@@@*++++++*+--:-=-+#+##%%%@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@+=+++++++=-:=+#%%##%%@@@@@@@@@@@@@@@\n\
@@@@@@@@%=.   ---====--:-=+**+###+#@@@@@@@@@@@@@@\n\
@@%*=:         .:::--==+*###**+*.     :+#@@@@@@@@\n\
                 -::::::::-+++*#       ...  .=%@@\n\
                  +%#+=-::=#@@@=         ......  \n\
                   -%%@@@=+@@@%  ...       ......\n\
                    =%@%  -=%@-. ...    .    ...:\n\
";

  for (int i = 0; i < 17; i++)
  {
    gotoxy (0, 0);
    for (int j = 0; j < 84; j++)
      std::cout << "\\o/ ";
    Beep (notes[i], duration[i]);
    gotoxy (0, 0);
    for (int j = 0; j < 84; j++)
      std::cout << "_o_ ";
    cout << "\n" << kim << "\n\n";
    CoutFlag();
    Sleep(100);
  };
  return 0;
}

void gotoxy(int x,int y)
{
  int xx=0x0b;
  HANDLE hOutput;
  COORD loc;
  loc.X=x;
  loc.Y=y;
  hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hOutput,loc);
}

void fullscreen()
{   
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN); // Screen width (pixel)
    int cy = GetSystemMetrics(SM_CYSCREEN); // Screen height (pixel)

    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE); // Get the window inf
// Set the window inf, Maximize, Disable the title bar & the border
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}

void clearscreen()
{
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(hStdout, &csbi))
  {
    return;
  }
  SMALL_RECT scrollRect;
  COORD scrollTarget;
  CHAR_INFO fill;
  scrollRect.Left = 0;
  scrollRect.Top = 0;
  scrollRect.Right = csbi.dwSize.X;
  scrollRect.Bottom = csbi.dwSize.Y;
  scrollTarget.X = 0;
  scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);
  fill.Char.UnicodeChar = TEXT(' ');
  fill.Attributes = csbi.wAttributes;
  ScrollConsoleScreenBuffer(hStdout, &scrollRect, NULL, scrollTarget, &fill);
  csbi.dwCursorPosition.X = 0;
  csbi.dwCursorPosition.Y = 0;
  SetConsoleCursorPosition(hStdout, csbi.dwCursorPosition);
}

void CoutFlag()
{
// Line 1 & 2
  ColorPrint("::::::::::::::::::::::::::::::::::::::::::::::::::\n\
::::::::::::::::::::::::::::::::::::::::::::::::::\n", 1);
// Line 3
  ColorPrint("==++++++++++++++++++++++++++++++++++++++++++++++==\n", 7);
// Line 4
  ColorPrint("--------------------------------------------------\n", 4);
// Line 5
  ColorPrint("------------", 4);
  ColorPrint("+*#%#%%#+", 7);
  ColorPrint("-----------------------------\n", 4);
// Line 6
  ColorPrint("----------", 4);
  ColorPrint("*@@@@@", 7);
  ColorPrint("-*", 4);
  ColorPrint("@@@@#", 7);
  ColorPrint("---------------------------\n", 4);
// Line 7
  ColorPrint("---------", 4);
  ColorPrint("*@#", 7);
  ColorPrint("***=--****", 4);
  ColorPrint("%%", 7);
  ColorPrint("--------------------------\n", 4);
// Line 8
  ColorPrint("---------", 4);
  ColorPrint("%@%#+", 7);
  ColorPrint("-----", 4);
  ColorPrint("=*%@@=", 7);
  ColorPrint("-------------------------\n", 4);
// Line 9
  ColorPrint("---------", 4);
  ColorPrint("*@@@#", 7);
  ColorPrint("--==-", 4);
  ColorPrint("+@@@%", 7);
  ColorPrint("--------------------------\n", 4);
// Line 10
  ColorPrint("----------", 4);
  ColorPrint("+@@", 7);
  ColorPrint("*#", 4);
  ColorPrint("@@@", 7);
  ColorPrint("%+", 4);
  ColorPrint("%@#", 7);
  ColorPrint("---------------------------\n", 4);
// Line 11
  ColorPrint("------------", 4);
  ColorPrint("+*%%%%#+", 7);
  ColorPrint("=-----------------------------\n", 4);
// Line 12
  ColorPrint("--------------------------------------------------\n", 4);
// Line 13
  ColorPrint("==++++++++++++++++++++++++++++++++++++++++++++++==\n", 7);
// Line 14 & 15
  ColorPrint("::::::::::::::::::::::::::::::::::::::::::::::::::\n\
::::::::::::::::::::::::::::::::::::::::::::::::::\n", 1);
  ColorPrint("", 7);  // Restore to the default color
}

void ColorPrint(const char* s, int color)
{
 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
 cout << s;
 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}
