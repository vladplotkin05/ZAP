#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#define ROWS 20
#define COLS 80
void roll_text();
void draw_logo();
void screensaver();
void moving_arrow(char map1[][81]);
void draw_maze();
char maze[ROWS][COLS + 1];
void print_logo();
void map1();
void map2();
void map3();
int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    srand(time(NULL));
    // initialize the library
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    print_logo();
    refresh();
    getchar();
    refresh();
    getchar();

    refresh();
    getchar();
    draw_maze();

    // end curses
    endwin();

    printf("Bye!\n");
    fclose(file);
    return 0;
}

void roll_text()
{
    clear();
    char buffer[COLS];
    char text[] = ".....You are an intrepid explorer who has decided to hunt down and solve the mystery of an ancient labyrinth known for its complexity and mystery. The player must discover hunting enemies and collect relics that reveal the ancient secrets of the labyrinth.";
    int y = LINES - 1;
    attron(COLOR_PAIR(1));
    for (int offset = 0; offset < strlen(text); offset++)
    {
        strncpy(buffer, text + offset, COLS);

        move(y, 0);
        printw("%s", buffer);
        refresh();
        usleep(1 * 100000);
    }
    attroff(COLOR_PAIR(1));
}

void draw_logo()
{
    clear();
    int x = 37;
    int y = 15;
    attron(COLOR_PAIR(1));
    mvaddstr(y + 1, x, " _______ _                                                                              ");
    mvaddstr(y + 2, x, "|__   __| |                                                                             ");
    mvaddstr(y + 3, x, "   | |  | |__   ___   _ __ ___   __ _ _______   _ __ _   _ _ __  _ __   ___ _ __        ");
    mvaddstr(y + 4, x, "   | |  | '_ \\ / _ \\ | '_ ` _ \\ / _` |_  / _ \\ | '__| | | | '_ \\| '_ \\ / _ \\ '__|");
    mvaddstr(y + 5, x, "   | |  | | | |  __/ | | | | | | (_| |/ /  __/ | |  | |_| | | | | | | |  __/ |          ");
    mvaddstr(y + 6, x, "   |_|  |_| |_|\\___| |_| |_| |_|\\__,_/___\\___| |_|   \\__,_|_| |_|_| |_|\\___|_|     ");

    attroff(COLOR_PAIR(1));

    refresh();

    usleep(1 * 1000000);
}

void screensaver()
{
    int y = 1;
    int x = 1;
    int dx = 1, dy = 1;
    char message[] = "HELLO ADVENTURES";

    int moves = 150;
    attron(COLOR_PAIR(1));
    while (moves > 0)
    {
        clear();
        move(y, x);
        printw("%s", message);
        refresh();
        usleep(1 * 100000);

        // update
        if (y == LINES - 1 || y == 0)
            dy *= -1;
        if (x == COLS - strlen(message) || x == 0)
            dx *= -1;

        y += dy;
        x += dx;
        moves -= 1;
    }
    attroff(COLOR_PAIR(1));
}
void draw_maze()
{
    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            mvaddch(y, x, maze[y][x]);
        }
    }
}
void moving_arrow(char map1[][81])
{
    int y = 1;
    int x = 1;
    int y2 = 16;
    int x2 = 51;
    int y3 = 0;
    int count = 0;
    int x3 = 0;
    char buffer[] = "Press ESC to quit. Move by arrows.";
    mvprintw(LINES - 1, 0, "%s", buffer);
    char player = '>', previous = ' ';
    attron(COLOR_PAIR(2));
    mvprintw(y2, x2, "%c", player);
    refresh();
    int c;

    do
    {
        c = getch();
        previous = (y == LINES - 1 && x < 34) ? buffer[x] : ' ';

        switch (c)
        {
        case KEY_LEFT:
        {
            if (map1[y][x - 1] == 'E')
            {
                mvwaddstr(stdscr, 5, 40, "YOU FOUND AWAY OUT");
                FILE *fp = fopen("countsteps.txt", "a");
                fprintf(fp, "Counts steps: %d\n", count);
                fclose(fp);

                break;
            }
            if (map1[y][x - 1] == '#')
            {
                continue;
            }
            map1[y][x - 1] = '<';
            x--;
            count++;
            x2--;
            y3 = y2;
            x3 = x2 + 1;
        }
        break;
        case KEY_RIGHT:
            if (map1[y][x + 1] == 'E')
            {
                mvwaddstr(stdscr, 5, 40, "YOU FOUND AWAY OUT");
                FILE *fp = fopen("countsteps.txt", "a");
                fprintf(fp, "Counts steps: %d\n", count);
                fclose(fp);

                break;
            }
            if (map1[y][x + 1] == '#')
            {
                continue;
            }
            map1[y][x + 1] = '>';
            x++;
            count++;
            x2++;
            y3 = y2;
            x3 = x2 - 1;
            break;
        case KEY_UP:
            if (map1[y - 1][x] == 'E')
            {
                mvwaddstr(stdscr, 5, 40, "YOU FOUND AWAY OUT");
                FILE *fp = fopen("countsteps.txt", "a");
                fprintf(fp, "Counts steps: %d\n", count);
                fclose(fp);
                break;
            }
            if (map1[y - 1][x] == '#')
            {
                continue;
            }
            map1[y - 1][x] = '^';
            y--;
            count++;
            y2--;
            y3 = y2 + 1;
            x3 = x2;
            break;
        case KEY_DOWN:
            if (map1[y + 1][x] == 'E')
            {
                mvwaddstr(stdscr, 5, 40, "YOU FOUND AWAY OUT");
                FILE *fp = fopen("countsteps.txt", "a");
                fprintf(fp, "Counts steps: %d\n", count);
                fclose(fp);
                break;
            }
            if (map1[y + 1][x] == '#')
            {
                continue;
            }
            map1[y + 1][x] = 'v';
            y++;
            count++;
            y2++;
            y3 = y2 - 1;
            x3 = x2;
            break;
        case 'B':
        case 'b':
            return;
            break;
        default:
            continue;
            break;
        }
        if (c == KEY_LEFT || c == KEY_RIGHT || c == KEY_UP || c == KEY_DOWN)
        {
            mvprintw(y3, x3, "%c", previous);
        }
        mvprintw(y2, x2, "%c", player);
        mvwaddstr(stdscr, 3, 60, "YOU CAN CLICK B/b, to return to the menu");
        refresh();
    } while (c != 27 && c != 27);
    attroff(COLOR_PAIR(1));
}

void map1()
{
    clear();
    refresh();
    char maze[ROWS][COLS + 1] = {
        "####################################################",
        "#       #                   #                      #",
        "# ##### ##### ######### ##### ######## #############",
        "# #           #    #          #            #       #",
        "# ########### # ##### ########### ############ #####",
        "#           #     # #        # #                 ###",
        "# ########### ### # # ###### # # ######## ##########",
        "#         # #     #     #      # #      #         ##",
        "# ######### ##### ##### ###### # ###### ######### ##",
        "#     #                   #    # #                ##",
        "# ### ############## ##### ##### ############## ####",
        "# #                #                #             ##",
        "# ############# ##### ################### ##########",
        "#            #                  #                 E#",
        "####################################################"};
    attron(COLOR_PAIR(3));
    move(15, 50);
    int b = 15;
    for (int j = 0; j < ROWS; j++)
    {
        for (int i = 0; i < COLS; i++)
        {
            if (maze[j][i] == 'E')
            {

                attroff(COLOR_PAIR(3));
                attron(COLOR_PAIR(4));
                printw("%c", 'E');
                attroff(COLOR_PAIR(4));
                attron(COLOR_PAIR(3));
                continue;
            }
            printw("%c", maze[j][i]);
        }
        b++;
        move(b, 50);
        refresh();
        usleep(1 * 100000);
    }
    moving_arrow(maze);
    attroff(COLOR_PAIR(3));
    getchar();
}
void map2()
{
    clear();
    refresh();

    char maze[ROWS][COLS + 1] = {
        "#############################################",
        "#             #                # #E         #",
        "# ##### ##### ######### ###### # ######### ##",
        "# #           #  #             #           ##",
        "# ########### #  ############### ###  #######",
        "#           # #   # #  #           #        #",
        "# ###########  #  # #  ###### ###  #  #######",
        "#         # #     #     #          #        #",
        "# ######### ##### ##### #########  ######## #",
        "#     #                  #   #              #",
        "# ### ############## ##### ################ #",
        "# #                #  #    #                #",
        "############### ##### ### #######   #########",
        "#                                           #",
        "#############################################"};
    attron(COLOR_PAIR(3));
    move(15, 50);
    int b = 15;
    for (int j = 0; j < ROWS; j++)
    {
        for (int i = 0; i < COLS; i++)
        {
            if (maze[j][i] == 'E')
            {

                attroff(COLOR_PAIR(3));
                attron(COLOR_PAIR(4));
                printw("%c", 'E');
                attroff(COLOR_PAIR(4));
                attron(COLOR_PAIR(3));
                continue;
            }
            printw("%c", maze[j][i]);
        }
        b++;
        move(b, 50);
        refresh();
        usleep(1 * 100000);
    }
    moving_arrow(maze);
    attroff(COLOR_PAIR(3));
    getchar();
}
void map3()
{
    clear();
    refresh();

    char maze[ROWS][COLS + 1] = {
        "#################################################",
        "#       #                      #                #",
        "# ##### ##### ######### ###### # ######### ###  #",
        "# #           #    #           #    #      #E   #",
        "# ########### # ###  ########### #### ###########",
        "#           #     # #       #     #    # # #    #",
        "# ########### ### # # ###############  # # ###  #",
        "#         # #     #     #                       #",
        "# ######### ##### ##### ########## ##############",
        "#     #                  #               #      #",
        "# ### ############## ##### ###### #####  #  #####",
        "# #                #          #       #         #",
        "##### ######### ##### ############# #############",
        "#            #              #                   #",
        "#################################################"};
    attron(COLOR_PAIR(3));
    move(15, 50);
    int b = 15;
    for (int j = 0; j < ROWS; j++)
    {
        for (int i = 0; i < COLS; i++)
        {
            if (maze[j][i] == 'E')
            {

                attroff(COLOR_PAIR(3));
                attron(COLOR_PAIR(4));
                printw("%c", 'E');
                attroff(COLOR_PAIR(4));
                attron(COLOR_PAIR(3));
                continue;
            }
            printw("%c", maze[j][i]);
        }
        b++;
        move(b, 50);
        refresh();
        usleep(1 * 100000);
    }
    moving_arrow(maze);
    attroff(COLOR_PAIR(3));
    getchar();
}

void print_logo()
{
    mvprintw(20, 60, "Choose the thing what you want to do:");
    mvprintw(23, 60, "MAP 1");
    mvprintw(26, 60, "MAP 2");
    mvprintw(29, 60, "MAP 3");
    mvprintw(32, 60, "EXIT");
    mvprintw(23, 68, "<");
    int situation = 1;
    for (char g = 'q'; g != 'd' && g != 'D';)
    {
        int input = getch();
        switch (input)
        {
        case KEY_UP:
        {
            if (situation == 1)
            {
                break;
            }
            if (situation == 2)
            {
                mvprintw(23, 68, "<");
                mvprintw(26, 68, " ");
                situation--;
                refresh();
                break;
            }
            if (situation == 3)
            {
                mvprintw(26, 68, "<");
                mvprintw(29, 68, " ");
                situation--;
                refresh();
                break;
            }
            if (situation == 4)
            {
                mvprintw(29, 68, "<");
                mvprintw(32, 68, " ");
                situation--;
                refresh();
                break;
            }
            break;
        }
        case KEY_DOWN:
        {
            if (situation == 4)
            {
                break;
            }
            if (situation == 1)
            {
                mvprintw(26, 68, "<");
                mvprintw(23, 68, " ");
                situation++;
                refresh();
                break;
            }
            if (situation == 2)
            {
                mvprintw(29, 68, "<");
                mvprintw(26, 68, " ");
                situation++;
                refresh();
                break;
            }
            if (situation == 3)
            {
                mvprintw(32, 68, "<");
                mvprintw(29, 68, " ");
                situation++;
                refresh();
                break;
            }
            break;
        }
        case '\n':
        {
            if (situation == 4)
            {
                g = 'd';
                break;
            }
            if (situation == 1)
            {
                map1();
                clear();
                mvprintw(20, 60, "Choose the thing what you want to do:");
                mvprintw(23, 60, "MAP 1");
                mvprintw(26, 60, "MAP 2");
                mvprintw(29, 60, "MAP 3");
                mvprintw(32, 60, "EXIT");
                mvprintw(23, 68, "<");
                refresh();
                break;
            }
            if (situation == 2)
            {
                map2();

                clear();
                mvprintw(20, 60, "Choose the thing what you want to do:");
                mvprintw(23, 60, "MAP 1");
                mvprintw(26, 60, "MAP 2");
                mvprintw(29, 60, "MAP 3");
                mvprintw(32, 60, "EXIT");
                mvprintw(23, 68, "<");
                refresh();
                break;
            }
            if (situation == 3)
            {
                map3();
                clear();
                mvprintw(20, 60, "Choose the thing what you want to do:");
                mvprintw(23, 60, "MAP 1");
                mvprintw(26, 60, "MAP 2");
                mvprintw(29, 60, "MAP 3");
                mvprintw(32, 60, "EXIT");
                mvprintw(23, 68, "<");
                refresh();
                break;
            }
            break;
        }
        }
    }

    refresh();
}

