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

void fill(char** mas, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int t = 0; t < m; t++)
        {
            mas[i][t] = '-';
            if (i > 0 && i < 6)
            {
                if (t == 0 || t == 6 ||
                    t % 2 == 0)
                {
                    mas[i][t] = '|';
                }
            }
            if (i == 0 && t == 0 ||
                i == 0 && t == 6 ||
                i == 6 && t == 0 ||
                i == 6 && t == 6 ||
                /*i % 2 == 0 && t % 2 == 0*/
                i == 2 && t == 2 ||
                i == 4 && t == 4 ||
                i == 2 && t == 4 || 
                i == 4 && t == 2)
            {
                mas[i][t] = '+';
            }
           
        }
    }
   
}
void print(char** mas, int n, int m, char horse)
{
    system("cls");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t t = 0; t < m; t++)
        {
            if (mas[i][t] == horse)
            {
                printf(RED BG_MAG "%c", mas[i][t]);
            }
            else if (mas[i][t] == ' ')
            {
                printf(RED BG_CYN "%c", mas[i][t]);
            }
            else
            {
                printf(BLU BG_GRN "%c", mas[i][t]);
            }
        }
        printf(BLU BG_GRN "%c", '\n');         
    }    
    Sleep(100);    
}
void show_steps(char** mas, int n, int m,char horse)
{
    int side = 1;
    int _step = 2;
    while (side < 12)
    {
        int steps = 0;
        fill(mas, n, m);
        switch (side)
        {
        case UP_RIGHT:
            mas[n - 2][3] = horse;            
            break;
        case UP_LEFT:
            mas[n - 2][3] = horse;
            break;
        case RIGHT_UP:
            mas[3][1] = horse;
            break;
        case RIGHT_DOWN:
            mas[3][1] = horse;
            break;
        case DOWN_RIGHT:
            mas[1][3] = horse;
            break;
        case DOWN_LEFT:
            mas[1][3] = horse;
            break;
        case LEFT_DOWN:
            mas[3][m-2] = horse;
            break;       
        case LEFT_UP:
            mas[3][m - 2] = horse;
            break;        
        }
        print(mas, n, m, horse);
        while (steps < 3)
        {
            switch (side)
            {
            case UP_RIGHT:
                for (int i = 0; i < n; i++)
                {
                    for (int t = 0; t < m; t++)
                    {
                        if (mas[i][t] == horse)
                        {
                            if (steps < 2)
                            {
                                mas[i][t] = ' ';
                                mas[i - _step][t] = horse;
                            }
                            if (steps == 2)
                            {
                                mas[i][t] = ' ';
                                mas[i][t + _step] = horse;
                                steps++;
                            }
                        }
                    }
                    print(mas, n, m,horse);
                }
                break;
            case RIGHT_UP:
                for (int i = 0; i < n; i++)
                {
                    for (int t = 0; t < m; t++)
                    {
                        if (mas[i][t] == horse)
                        {
                            if (steps < 2)
                            {
                                mas[i][t] = ' ';
                                mas[i][t + _step] = horse;
                                break;
                            }
                            if (steps == 2)
                            {
                                mas[i][t] = ' ';
                                mas[i - _step][t] = horse;
                                steps++;
                            }
                        }
                    }
                    print(mas, n, m,horse);
                }
                break;
            case RIGHT_DOWN:
                for (int i = 0; i < n; i++)
                {
                    for (int t = 0; t < m; t++)
                    {
                        if (mas[i][t] == horse)
                        {
                            if (steps < 2)
                            {
                                mas[i][t] = ' ';
                                mas[i][t + _step] = horse;
                                break;
                            }
                            if (steps == 2)
                            {
                                mas[i][t] = ' ';
                                mas[i + _step][t] = horse;
                                steps++;
                            }
                        }
                    }
                    print(mas, n, m,horse);
                }
                break;
            case DOWN_RIGHT:
                for (int i = 0; i < n; i++)
                {
                    for (int t = 0; t < m; t++)
                    {
                        if (mas[i][t] == horse)
                        {
                            if (steps < 2)
                            {
                                mas[i][t] = ' ';
                                mas[i + _step][t] = horse;
                                i += _step;
                                break;
                            }
                            if (steps == 2)
                            {
                                mas[i][t] = ' ';
                                mas[i][t + _step] = horse;
                                steps++;
                                break;
                            }
                        }
                    }
                    print(mas, n, m,horse);
                }
                break;
            case LEFT_DOWN:
                for (int i = 0; i < n; i++)
                {
                    for (int t = 0; t < m; t++)
                    {
                        if (mas[i][t] == horse)
                        {
                            if (steps < 2)
                            {
                                mas[i][t] = ' ';
                                mas[i][t - _step] = horse;
                            }
                            if (steps == 2)
                            {
                                mas[i][t] = ' ';
                                mas[i + _step][t] = horse;
                                steps++;
                            }
                        }
                    }
                    print(mas, n, m,horse);
                }
                break;
            case DOWN_LEFT:
                for (int i = 0; i < n; i++)
                {
                    for (int t = 0; t < m; t++)
                    {
                        if (mas[i][t] == horse)
                        {
                            if (steps < 2)
                            {
                                mas[i][t] = ' ';
                                mas[i + _step][t] = horse;
                                i += _step;
                                break;
                            }
                            if (steps == 2)
                            {
                                mas[i][t] = ' ';
                                mas[i][t - _step] = horse;
                                steps++;
                                break;
                            }
                        }
                    }
                    print(mas, n, m,horse);
                }
                break;
            case LEFT_UP:
                for (int i = 0; i < n; i++)
                {
                    for (int t = 0; t < m; t++)
                    {
                        if (mas[i][t] == horse)
                        {
                            if (steps < 2)
                            {
                                mas[i][t] = ' ';
                                mas[i][t - _step] = horse;
                            }
                            if (steps == 2)
                            {
                                mas[i][t] = ' ';
                                mas[i - _step][t] = horse;
                                steps++;
                            }
                        }
                    }
                    print(mas, n, m,horse);
                }
                break;
            case UP_LEFT:
                for (int i = 0; i < n; i++)
                {
                    for (int t = 0; t < m; t++)
                    {
                        if (mas[i][t] == horse)
                        {
                            if (steps < 2)
                            {
                                mas[i][t] = ' ';
                                mas[i-_step][t] = horse;
                            }
                            if (steps == 2)
                            {
                                mas[i][t] = ' ';
                                mas[i][t - _step] = horse;
                            }
                        }
                    }
                    print(mas, n, m,horse);
                }
                break;
            }
            steps++;
        }
        side++;
        Sleep(100);
    }
}
int main()
{   
	std::wcout.sync_with_stdio(false);
	std::wcout.imbue(std::locale("en_US.utf8"));

    const char Horse = 'O';
    const int N = 7;
    const int M = 7;
    char** mas = new char*[N];
    for (int i = 0; i < N; i++)
    {
        mas[i] = new char[M];
    }    
    fill(mas, N, M);
    print(mas, N, M, Horse);
    while (true)
    {
        show_steps(mas, N, M, Horse);
    }
        //printf(BLU BG_GRN "%c", BORDER_LEFT_BOTTOM);       
   // printToCoordinates(10, 10,"O", 11,11,"o", 12,12,"O");

	return 0;
}
