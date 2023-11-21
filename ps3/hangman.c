#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>
#include <ctype.h>

int get_word(char secret[])
{
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do
    {
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if (result != EOF)
            break;
    } while (1);

    fclose(fp);

    return 0;
}
int is_word_guessed(const char secret[], const char letters_guessed[])
{
    for (int i = 0; i < strlen(secret); ++i)
    {
        int u = 0;
        for (int t = 0; t < strlen(letters_guessed); ++t)
        {
            if (secret[i] == letters_guessed[t])
            {
                u++;
            }
        }
        if (u == 0)
        {
            return 0;
        }
    }
    return 1;
}
void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[])
{
    for (int i = 0; i < strlen(secret); ++i)
    {
        int u = 0;
        guessed_word[i] = '_';
        for (int t = 0; t < strlen(letters_guessed); ++t)
        {
            if (secret[i] == letters_guessed[t])
            {
                u++;
                guessed_word[i] = secret[i];
                break;
            }
        }
    }
    guessed_word[strlen(secret)] = '\0';
}
void get_available_letters(const char letters_guessed[], char available_letters[])
{
    int o = 0;
    for (int i = 0; i < 26; ++i)
    {
        int u = 0;
        for (int t = 0; t < strlen(letters_guessed); ++t)
        {
            if ((char)97 + i == letters_guessed[t])
            {
                u++;
                break;
            }
        }
        if (u == 0)
        {
            available_letters[o] = (char)97 + i;
            o++;
        }
    }
    available_letters[0] = '\0';
}
void hangman(const char secret[])
{
    char cleaner[150];
    cleaner[0] = '\0';
    char letters_guessed[28] = "hello";
    char available_letters[28];


    while( letters_guessed != secret)
    {
    printf("Welcome to the game, Hangman!\n");
    int a = strlen(secret);
    printf("I am thinking of a word that is %d letters long.\n", a);
    printf("-------------\n");
        for (int b = 8; b > 0; --b)
        {
            printf("You have %d guesses left.\n", b);
       
        get_available_letters(letters_guessed, available_letters);
        printf("Available letters: \n" );
        get_guessed_word(secret, letters_guessed, cleaner);
        
        printf("Please guess a letter: ");
        if(letters_guessed == secret){
        return ;}
        return;}
        // }
        // printf("You have %d guesses left.\n", b);
    }
}
    // int main()
    // {

    //     hangman("hello");
    //     return 0;
    // }