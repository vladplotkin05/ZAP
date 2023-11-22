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
    available_letters[o] = '\0';
}
void hangman(const char secret[])
{
    int b = 8;
    // char cleaner[150];
    // cleaner[0] = '\0';
    char letters_guessed[28] = "";
    char available_letters[28];
    // char result[30];
    // int guess(char secret[]);

    printf("Welcome to the game, Hangman!\n");
    int a = strlen(secret);
    printf("I am thinking of a word that is %d letters long.\n", a);
    printf("-------------\n");
    while (b != 0)
    {

        printf("You have %d guesses left.\n", b);
        get_available_letters(letters_guessed, available_letters);
        printf("Available letters: %s\n", available_letters);
        printf("Please guess a letter: ");
        char guess[20];
        fgets(guess, sizeof(guess), stdin);
        if (strlen(guess) > 2)
        {
            //----
            if(strncmp(secret, guess,strlen(secret)) == 0){
                printf("Congratulations, you won! ");
                return;
                }else{
                     printf("Sorry, bad guess. The word was %s.", secret);
                     return;
                }
            //----
            return;
        }
        // проверка символа на букву 
        if(isalpha(guess[0])==0){
            printf("Oops! '%c' is not a valid letter: ", guess[0]);
            guess[0]= '\0';
            get_guessed_word(secret, letters_guessed, guess);
            for (int i = 0; i < strlen(guess)-1; ++i)
            {
                printf("%c ", guess[i]);
            }
            printf("%c\n", guess[strlen(guess)-1]);
            printf("-------------\n");
            continue;
        }
        //на опуск в нижний резис
        guess[0] = tolower(guess[0]);
        // на повтор букв
        int v=0;
        for(int i = 0;i<strlen(letters_guessed);++i){
            if(letters_guessed[i]==guess[0]){
        v++;}
        }
        if(v!=0){
            printf("Oops! You've already guessed that letter: ");
            get_guessed_word(secret, letters_guessed, guess);
             for (int i = 0; i < strlen(guess)-1; ++i)
            {
                printf("%c ", guess[i]);
            }
            printf("%c\n", guess[strlen(guess)-1]);
            printf("-------------\n");
            continue;
        }
        // добавление до одгаданих
        strcat(letters_guessed, guess);
        int j=0;
        for(int a = 0  ;a < strlen(secret);++a){
            if(secret[a]==guess[0]){
            j = 1;
            }
        }
        if(j == 1){
            printf("Good guess: ");
            get_guessed_word(secret, letters_guessed, guess);
                       for (int i = 0; i < strlen(guess)-1; ++i)
            {
                printf("%c ", guess[i]);
            }
            printf("%c\n", guess[strlen(guess)-1]);
            printf("-------------\n");
            guess[0] = '\0';
            if (is_word_guessed(secret, letters_guessed))
            {
                printf("Congratulations, you won!\n");
                return;
            }
        }else{
            guess[0] = '\0';
             printf("Oops! That letter is not in my word: ");
             get_guessed_word(secret, letters_guessed, guess);
                       for (int i = 0; i < strlen(guess)-1; ++i)
            {
                printf("%c ", guess[i]);
            }
            printf("%c\n", guess[strlen(guess)-1]);
            printf("-------------\n");
            b--;
        }
    }
    printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
}
// int main()
// {
//     hangman("hello");

//     return 0;
// }