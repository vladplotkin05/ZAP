#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"
#include <time.h>
#include <ncurses.h>

//task_1
void generator(const int rows, const int columns, char field[rows][columns]){
    int s = rand() % columns;
    int w;
    do {
         w = rand() % columns;
    } while (w == s);

}
//task_2
void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y){

}
//task_3
bool check(const int rows, const int columns, char field[rows][columns]){
    for( int a = 0; a < columns; ++a){
        char t = field[0][a];
        for(int  b = 1;b < rows; ++b){
            if(field[b][a] != t){
            return false;
            }
        }
    }
    return true;
}
//task_4
void game_field(const int rows, const int columns, char field[rows][columns]){
   int c;
   int y = 11, x = 11;

   initscr();
   keypad(stdscr, 1);
   noecho();
   curs_set(0);

   do
   {
    clear();
    if(c == KEY_UP) y--;
    else if (c == KEY_DOWN) y++;
    else if (c == KEY_RIGHT) x++;
    else if (c == KEY_LEFT) x--;
    mvaddch(y, x,'<^>');
   }
   
    while((c = getch()) != 27);
    endwin();
    return;
}

int main(){
    srand(time(NULL));
    char arr[6][12];
    int y = 6; x = 12;
    generator(x,y,arr);
    
    for(int i = 0; i < y; ++i) {
        for(int j = 0;j < x; ++j){
                printf("%c   ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
    