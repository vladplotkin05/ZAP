#include <stdio.h>
#include "c4.h"


// task_6
void initialize_board(int rows, int cols, char board[rows][cols])
{
    for (int a = 0; a < cols; a++)
    {
        for (int b = 0; b < rows; b++)
        {
            board[b][a] = '.';
        }
    }
}
// task_8
int is_valid_move(int rows, int cols, const char board[rows][cols], int col)
{
    if (col > cols || col < 1)
    {
        return 0;
    }
    if (board[0][col -1] != '.')
    {
    return 0;
    }
    return 1;
}
// task_9
int drop_piece(int rows, int cols, char board[rows][cols], int col, char player_piece)
{
        for (int i = rows - 1; i >= 0; i--) {
        if (board[i][col - 1] == '.') {
            board[i][col - 1] = player_piece;
            return  i; 
        }
    }
    return -1;
}
// task_10
int check_win(int rows, int cols, const char board[rows][cols], int row, int col, char player_piece)
{
       // diagonal before left to right
        for (int i = 0; i < rows - 3; ++i)
    {
        for (int j = 3; j < cols; ++j)
        {
            if ((int)board[i][j] == (int)player_piece && (int)board[i + 1][j - 1] == (int)player_piece && (int)board[i + 2][j - 2] == (int)player_piece && (int)board[i+3][j-3] == (int)player_piece)
            {
                return 1;
            }
        }
        
    }
    // vertical
    for(int i = 3; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if((int)board[i][j] == (int) player_piece && (int)board[i-1][j]==(int)player_piece && (int)board[i-2][j] == (int)player_piece && (int)board[i-3][j] == (int)player_piece){
                return 1;
            }
        }
    }
    // horizontal
        for(int i = 0; i < rows; i++){
        for(int j = 3; j < cols; j++){
            if((int)board[i][j] == (int) player_piece && (int)board[i][j-1]==(int)player_piece && (int)board[i][j-2] == (int)player_piece && (int)board[i][j-3] == (int)player_piece){
                return 1;
            }
        }
    }
    //diagonal

    for (int i = 0; i < rows - 3; ++i)
    {
        for (int j = 0; j < cols - 3; ++j)
        {
            if ((int)board[i][j] == (int)player_piece && (int)board[i + 1][j + 1] == (int)player_piece && (int)board[i + 2][j + 2] == (int)player_piece && (int)board[i+3][j+3] == (int)player_piece)
            {
                return 1;
            }
        }
    }
    return 0;
}
// task_11
int is_board_full(int rows, int cols, const char board[rows][cols])
{
        for (int j = 0; j < rows; ++j){
     for (int i = 0; i < cols; ++i) {
            if (board[j][i] != 'O' && board[j][i] != 'X') {
                return 0;
            }
        }
    }
    return 1;
}
// int main(){
//        int rows = 4;
//     int cols = 6;
//     int c;
//     char board[rows][cols];
//     int count=0;
//     char pla='X';
//     initialize_board(rows,cols,board);

//     if(count%2!=0){
//         pla='O';
//     }else{
//         pla = 'X';
//     }
    
//     scanf("%d", &c); 
//     while(is_valid_move(rows, cols, board, c) != 1){
//         drop_piece(rows, cols, board, c, pla);
//     }
    
//     if (drop_piece(rows, cols, board, c , pla)) {
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 printf("| %c ", board[i][j]);
//             }
//             printf("|\n");
//         }
//     }
// }
