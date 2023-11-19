#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"


int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}
int is_word_guessed(const char secret[], const char letters_guessed[]){
    for(int i=0;i<strlen(secret);++i){
        int u=0;
        for(int t=0;t<strlen(letters_guessed);++t){
            if(secret[i]==letters_guessed[t]){
                u++;
            }
        }
        if(u==0){
            return 0;
        }
    }
    return 1;
}
void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
  for(int i=0;i<strlen(secret);++i){
        int u=0;
        guessed_word[i] = '_';
        for(int t=0;t<strlen(letters_guessed);++t){
            if(secret[i]==letters_guessed[t]){
                u++;
                guessed_word[i] = secret[i];
                break;
            }
        }
    }
}
void get_available_letters(const char letters_guessed[], char available_letters[]){
    int o=0;
  for(int i=0;i<26;++i){
        int u=0;
        for(int t=0;t<strlen(letters_guessed);++t){
            if((char)97+i==letters_guessed[t]){
                u++;
                break;
            }
        }
        if(u==0){
            available_letters[o]=(char)97+i;
            o++;
        }
    }
}


int main(){
char result[30];
get_available_letters("azzs", result);
printf("%s\n", result);
}