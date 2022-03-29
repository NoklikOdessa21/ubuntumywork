#include <iostream>
#include <stdio.h>
#include <Windows.h>


#define BORDER_VERTICAL (wchar_t)0x2551
#define BORDER_VERTICAL_LEFT (wchar_t)0x2563
#define BORDER_VERTICAL_RIGHT (wchar_t)0x2560
#define BORDER_VERTICAL_HORISONTAL (wchar_t)0x256C
#define BORDER_HORISONTAL (wchar_t)0x2550
#define BORDER_HORISONTAL_TOP (wchar_t)0x2569
#define BORDER_HORISONTAL_BOTTOM (wchar_t)0x2566
#define BORDER_LEFT_TOP (wchar_t)0x2554
#define BORDER_RIGHT_TOP (wchar_t)0x2557
#define BORDER_LEFT_BOTTOM (wchar_t)0x255A
#define BORDER_RIGHT_BOTTOM (wchar_t)0x255D


#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define BLACK "\x1B[30m"

#define BG_RED   "\x1B[41m"
#define BG_GRN   "\x1B[42m"
#define BG_YEL   "\x1B[43m"
#define BG_BLU   "\x1B[44m"
#define BG_MAG   "\x1B[45m"
#define BG_CYN   "\x1B[46m"
#define BG_WHT   "\x1B[47m"
#define BG_BLACK "\x1B[40m"

#define UP_RIGHT    1
#define RIGHT_UP    2
#define RIGHT_DOWN  4
#define DOWN_RIGHT  5
#define LEFT_DOWN   7
#define DOWN_LEFT   8
#define LEFT_UP     10
#define UP_LEFT     11


void printToCoordinates(int x, int y, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	printf("\033[%d;%dH", x, y);
	vprintf(format, args);
	va_end(args);
	fflush(stdout);
}
void temp() {
	int side = 1;
	while (side < 12)
	{
		if (side == 3 || side == 6 || side == 9)
			side++;
		system("cls");
		int steps = 0;
		int x = 10;
		int y = 10;
		printToCoordinates(x, y, "O");
		Sleep(1000);
		while (steps < 3)
		{
			switch (side)
			{
			case UP_RIGHT:
				if (steps < 2)
				{
					x--;					
				}
				if (steps == 2)
				{
					y+=2;
					steps++;
				}
				break;
			case RIGHT_UP:
				if (steps < 2)
				{
					y += 2;
				}
				if (steps == 2)
				{
					x--;
					steps++;
				}
				break;
			case RIGHT_DOWN:
				if (steps < 2)
				{
					y += 2;
				}
				if (steps == 2)
				{
					x++;
					steps++;
				}	
				break;
            case DOWN_RIGHT:
				if (steps < 2)
				{
					x++;
				}
				if (steps == 2)
				{
					y += 2;
					steps++;
				}
				break;
			case DOWN_LEFT:
				if (steps < 2)
				{
					y-=2;
				}
				if (steps == 2)
				{
					x++;
					steps++;
				}
				break;
			case LEFT_DOWN:
				if (steps < 2)
				{
					x++;
				}
				if (steps == 2)
				{
					y -= 2;
					steps++;
				}
				break;
			case LEFT_UP:
				if (steps < 2)
				{
					y -= 2;
				}
				if (steps == 2)
				{
					x--;
					steps++;
				}
				break;
			case UP_LEFT:

				if (steps < 2)
				{
					x--;
				}
				if (steps == 2)
				{
					y -= 2;
				}
				break;
		}
		printToCoordinates(x, y, "O");
		Sleep(400);
		steps++;
		}
	side++;	
	}
}
int main()
{
	std::wcout.sync_with_stdio(false);
	std::wcout.imbue(std::locale("en_US.utf8"));

	temp();
	system("cls");
	return 0;
}
