#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include "ballsortpuzzle.h"
#include <time.h>
#include <ncurses.h>
#define BACK_COLOR 103

// task_1
void generator(const int rows, const int columns, char field[rows][columns])
{
    int s = rand() % columns;
    int w;
    do
    {
        w = rand() % columns;
    } while (w == s);
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (j == w || j == s)
            {
                field[i][j] = ' ';
            }
            else
            {
                field[i][j] = 97 + j;
            }
        }
    }
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = columns - 1; j >= 0; j--)
        {
            if (j == w || j == s)
            {
                continue;
            }
            else
            {
                int random_beforeI;
                int random_beforeJ;
                do
                {
                    random_beforeJ = rand() % columns;
                } while (random_beforeJ == w || random_beforeJ == s);
                random_beforeI = rand() % (i + 1);

                char change = field[i][j];
                field[i][j] = field[random_beforeI][random_beforeJ];
                field[random_beforeI][random_beforeJ] = change;
            }
        }
    }
    int e;
    for (int g = 0; g < rows; g++)
    {
        for (int h = 0; h < columns; h++)
        {
            if (field[g][h] == field[g + 1][h] && field[g][h] == field[g + 2][h] && field[g][h] != ' ')
            {
                do
                {
                    e = rand() % columns;
                } while (e == w || e == s);
                char gg = field[g][h];
                field[g][h] = field[g][e];
                field[g][e] = gg;
                break;
            }
        }
    }
}
// task_2
void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y)
{
    if (x - 1 < 0 || y - 1 < 0 || field[0][y - 1] != ' ' || x - 1 == y - 1 || field[rows - 1][x - 1] == ' ' || x - 1 >= columns || y - 1 >= rows)
    {

        mvprintw(2, 4, "Wrong move, try again");
        return;
    }
    for (int i = 0; i < rows; ++i)
    {
        if (field[i][x - 1] != ' ')
        {
            for (int j = rows - 1; j >= 0; --j)
            {
                if (field[j][y - 1] == ' ')
                {
                    if (j < rows - 1 && field[j + 1][y - 1] != field[i][x - 1])
                    {
                        return;
                    }
                    field[j][y - 1] = field[i][x - 1];
                    field[i][x - 1] = ' ';
                    return;
                }
            }
        }
    }
}
// task_3
bool check(const int rows, const int columns, char field[rows][columns])
{
    for (int a = 0; a < columns; ++a)
    {
        char t = field[0][a];
        for (int b = 1; b < rows; ++b)
        {
            if (field[b][a] != t)
            {
                return false;
            }
        }
    }
    return true;
}
// task_4
void game_field(const int rows, const int columns, char field[rows][columns])
{
    //     int c;
    //    int y = 11, x = 11;
    setlocale(LC_ALL, "");
    initscr();
    start_color();
    init_pair(0, 226, BACK_COLOR);
    wbkgd(stdscr, COLOR_PAIR(13));
    //    attron(COLOR_PAIR(13));
    init_pair(1, COLOR_RED, BACK_COLOR);
    init_pair(2, COLOR_GREEN, BACK_COLOR);
    init_pair(3, COLOR_YELLOW, BACK_COLOR);
    init_pair(4, COLOR_BLUE, BACK_COLOR);
    init_pair(5, COLOR_CYAN, BACK_COLOR);
    init_pair(6, COLOR_MAGENTA, BACK_COLOR);
    init_pair(7, 16, BACK_COLOR);
    init_pair(8, 12, BACK_COLOR);
    init_pair(9, 17, BACK_COLOR);
    init_pair(10, 52, BACK_COLOR);
    init_pair(11, 58, BACK_COLOR);
    init_pair(12, 168, BACK_COLOR);
    init_pair(13, 197, BACK_COLOR);
    int yy = 9;
    int xx = 8;
    for (int i = 0; i < rows; i++)
    {
        mvprintw(yy + i + 1, xx - 2, "%d", i + 1);
    }
    for (int j = 1; j <= columns; ++j)
    {
        mvwaddstr(stdscr, yy, xx * j, "\u2552");
        mvwaddstr(stdscr, yy, xx * j + 1, "\u2550");
        mvwaddstr(stdscr, yy, xx * j + 2, "\u2555");
        for (int i = 1; i <= rows; ++i)
        {
            mvwaddstr(stdscr, yy + i, xx * j, "\u2502");
            attron(COLOR_PAIR(13));
            if (field[i - 1][j - 1] == 'a')
            {
                attron(COLOR_PAIR(1));
            }
            if (field[i - 1][j - 1] == 'b')
            {
                attron(COLOR_PAIR(2));
            }
            if (field[i - 1][j - 1] == 'c')
            {
                attron(COLOR_PAIR(3));
            }
            if (field[i - 1][j - 1] == 'd')
            {
                attron(COLOR_PAIR(4));
            }
            if (field[i - 1][j - 1] == 'e')
            {
                attron(COLOR_PAIR(5));
            }
            if (field[i - 1][j - 1] == 'f')
            {
                attron(COLOR_PAIR(6));
            }
            if (field[i - 1][j - 1] == 'g')
            {
                attron(COLOR_PAIR(7));
            }
            if (field[i - 1][j - 1] == 'h')
            {
                attron(COLOR_PAIR(8));
            }
            if (field[i - 1][j - 1] == 'i')
            {
                attron(COLOR_PAIR(9));
            }
            if (field[i - 1][j - 1] == 'j')
            {
                attron(COLOR_PAIR(10));
            }
            if (field[i - 1][j - 1] == 'k')
            {
                attron(COLOR_PAIR(11));
            }
            if (field[i - 1][j - 1] == 'l')
            {
                attron(COLOR_PAIR(12));
            }

            mvaddch(yy + i, xx * j + 1, field[i - 1][j - 1]);
            if (field[i - 1][j - 1] == 'a')
            {
                attroff(COLOR_PAIR(1));
            }
            if (field[i - 1][j - 1] == 'b')
            {
                attroff(COLOR_PAIR(2));
            }
            if (field[i - 1][j - 1] == 'c')
            {
                attroff(COLOR_PAIR(3));
            }
            if (field[i - 1][j - 1] == 'd')
            {
                attroff(COLOR_PAIR(4));
            }
            if (field[i - 1][j - 1] == 'e')
            {
                attroff(COLOR_PAIR(5));
            }
            if (field[i - 1][j - 1] == 'f')
            {
                attroff(COLOR_PAIR(6));
            }
            if (field[i - 1][j - 1] == 'g')
            {
                attroff(COLOR_PAIR(7));
            }
            if (field[i - 1][j - 1] == 'h')
            {
                attroff(COLOR_PAIR(8));
            }
            if (field[i - 1][j - 1] == 'i')
            {
                attroff(COLOR_PAIR(9));
            }
            if (field[i - 1][j - 1] == 'j')
            {
                attroff(COLOR_PAIR(10));
            }
            if (field[i - 1][j - 1] == 'k')
            {
                attroff(COLOR_PAIR(11));
            }
            if (field[i - 1][j - 1] == 'l')
            {
                attroff(COLOR_PAIR(12));
            }
            mvwaddstr(stdscr, yy + i, xx * j + 2, "\u2502");
        }
        mvwaddstr(stdscr, yy + rows + 1, xx * j, "\u2514");
        mvwaddstr(stdscr, yy + rows + 1, xx * j + 1, "\u2500");
        mvwaddstr(stdscr, yy + rows + 1, xx * j + 2, "\u2518");
        mvprintw(yy + rows + 2, xx * j + 1, "%d", j);
    }
    refresh();
    getch();
    endwin();
    return;
}
void ball_sort_puzzle()
{
    srand(time(NULL));
    char arr[6][12];
    int y = 6;
    int x = 12;
    generator(y, x, arr);
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    int g, h;
    while (check(y, x, arr) != true)
    {

        game_field(y, x, arr);
        printw("\n\nWrite the column first: ");
        refresh();
        scanw("%d", &g);
        printw("\n\nWrite the column second: ");
        refresh();
        scanw("%d", &h);
        // refresh();
        down_possible(y, x, arr, g, h);
        refresh();
        getch();
        clear();
        refresh();
        // game_field(y, x, arr);
    }
    getch();
}
//  int main()
// {
//     char arr[8][7];
//     int y = 8;
//     int x = 7;
//     generator(y, x, arr);
//    // // ball_sort_puzzle();
//     for (int i = 0; i < y; ++i)
//     {
//         for (int j = 0; j < x; ++j)
//         {
//             printf("%c", arr[i][j]);
//         }
//         printf("\n");
//     }
// printf("-----------------------------------\n");
// // down_possible(y, x, arr, 1, 2);
//  for (int i = 0; i < y; ++i)
// {
//     for (int j = 0; j < x; ++j)
//     {
//         printw("%c", arr[i][j]);
//     }
//     printw("\n");
// }
//     int g,h;
//     scanw("%d", &g);
//     scanw("%d", &h);
//     down_possible(y, x, arr, g, h);
//        for (int i = 0; i < y; ++i)
// {
//     for (int j = 0; j < x; ++j)
//     {
//         printf("%c", arr[i][j]);
//     }
//     printf("\n");
// }
//     game_field(y, x, arr);
//     for(int i = 0; i < y; ++i)
//     {
//         for (int j = 0; j < x; ++j)
//         {
//             printf("%c", arr[i][j]);
//         }
//         printf("\n");
//     }
//     game_field(y, x, arr);

//     getch();

//     return 0;
// }
