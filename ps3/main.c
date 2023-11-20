#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include<string.h>
#include<ctype.h>
#include<time.h>

int main(){
    char vladcreator[17];
    srand(time(NULL));
    get_word(vladcreator);
    hangman(vladcreator);
} 