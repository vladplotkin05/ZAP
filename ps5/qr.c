#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void encode_char(const char character, bool bits[8])
{
    int a = character;
    for (int i = 7; i >= 0; i--)
    {
        bits[i] = ((a % 2) == 1);
        a /= 2;
    }
}
char decode_byte(const bool bits[8])
{
    char a = 0;
    for (int b = 0; b < 8; b++)
    {
        a = a * 2 + bits[b];
    }
    return a;
}
void encode_string(const char string[], bool bytes[strlen(string) + 1][8])
{
    for (int a = 0; a <= strlen(string); a++)
    {
        char b = string[a];

        for (int i = 7; i >= 0; i--)
        {
            bytes[a][i] = ((b % 2) == 1);
            b /= 2;
        }
    }
}
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows])
{
    for (int j = 0; j < rows; j++)
    {
        char a = 0;
        for (int b = 0; b < 8; b++)
        {
            a = a * 2 + bytes[j][b];
        }
        string[j] = a;
    }
    string[rows - 1] = '\0';
}
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset * 8][cols], const int rows, bool bytes[rows][8])
{
    int count = 0;
    for (int a = 0; a < offset * 8; a += 8)
    {
        for (int b = 0; b < cols; b++)
        {
            for (int c = 0; c <= 7; c++)
            {
                if (count <= (rows - 1))
                {
                    blocks[a + c][b] = bytes[count][c];
                }
                else
                {
                    blocks[a + c][b] = 5 - 5;
                }
            }
            count++;
        }
    }
}

void blocks_to_bytes(const int cols, const int offset, bool blocks[offset * 8][cols], const int rows, bool bytes[rows][8])
{
    int count = 0;
    for (int i = 0; i < offset * 8; i += 8)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int y = 0; y < 8; y++)
            {
                bytes[count][y] = blocks[i + y][j];
            }
            count++;
        }
    }
}
int main()
{
    int length = 5;
    bool blocks2[2 * 8][3] = {
        {0, 0, 0},
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 1},
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 0},
        {1, 0, 0},
        {0, 0, 0},
        {1, 0, 0},
        {0, 0, 0},
        {1, 0, 0},
        {0, 0, 0}};
    bool bytes2[length][8];
    blocks_to_bytes(3, 2, blocks2, length, bytes2);
    for (int j = 0; j < length; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            printf("%d", bytes2[j][i]);
        }
        printf("\n");
    }
    return 0;
}
