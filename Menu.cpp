#include "console.h"

void DrawingText(char Text, int x, int y)
{
	if (Text == 65 || Text == 97)
	{
		gotoXY(x, y);     cout << "   00  ";     Sleep(40);
		gotoXY(x, y + 1); cout << " 00  00";     Sleep(40);
		gotoXY(x, y + 2); cout << " 00  00";     Sleep(40);
		gotoXY(x, y + 3); cout << " 000000";     Sleep(40);
		gotoXY(x, y + 4); cout << " 00  00";     Sleep(40);
	}

	else if (Text == 69 || Text == 101)
	{
		gotoXY(x, y);     cout << " 000000";     Sleep(40);
		gotoXY(x, y + 1); cout << " 00    ";     Sleep(40);
		gotoXY(x, y + 2); cout << " 000000";     Sleep(40);
		gotoXY(x, y + 3); cout << " 00    ";     Sleep(40);
		gotoXY(x, y + 4); cout << " 000000";     Sleep(40);
	}

	else if (Text == 75 || Text == 107)
	{
		gotoXY(x, y);     cout << "00    00";   Sleep(40);
		gotoXY(x, y + 1); cout << "00   00 ";   Sleep(40);
		gotoXY(x, y + 2); cout << "00000   ";   Sleep(40);
		gotoXY(x, y + 3); cout << "00  00  ";   Sleep(40);
		gotoXY(x, y + 4); cout << "00    00";   Sleep(40);
	}

	else if (Text == 78 || Text == 110)
	{
		gotoXY(x, y);     cout << "00     00";  Sleep(40);
		gotoXY(x, y + 1); cout << "00 0   00";  Sleep(40);
		gotoXY(x, y + 2); cout << "00  0  00";  Sleep(40);
		gotoXY(x, y + 3); cout << "00   0 00";  Sleep(40);
		gotoXY(x, y + 4); cout << "00     00";  Sleep(40);
	}

	else if (Text == 83 || Text == 115)
	{
		gotoXY(x, y);     cout << "  00000";     Sleep(40);
		gotoXY(x, y + 1); cout << " 00    ";     Sleep(40);
		gotoXY(x, y + 2); cout << "  0000 ";     Sleep(40);
		gotoXY(x, y + 3); cout << "     00";    Sleep(40);
		gotoXY(x, y + 4); cout << " 00000 ";     Sleep(40);
	}

}

void menuDisplay()
{
	int Check = 1;
	do {
		clrscr();
		resizeConsole(600, 600);
		for (int i = 0; i <= WidthMenu; i++)
		{
			for (int j = 0; j <= HeightMenu; j++)
			{
				gotoXY(i, j);
				if (i == 0 || j == 0 || i == WidthMenu  || j == HeightMenu )
					cout << char(164);
			}
		}

		TextColor(ColorCode_Green);
		DrawingText('S', 10, 2);
		DrawingText('N', 19, 2);
		DrawingText('A', 29, 2);
		DrawingText('K', 39, 2);
		DrawingText('E', 48, 2);

		gotoXY(29, 13); cout << "1: PLAY";
		gotoXY(29, 16); cout << "2: EXIT";
		
		int Select;
		do
		{
			if (_kbhit())
			{
				Select = _getch();
				if (Select == 49)
				{
					Check = Select;
					break;
				}
				else if (Select == 50)
				{
					exit(0);
				}
			}
		} while (true);
	} while (Check != 49);
}
