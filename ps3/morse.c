#include<string.h>
#include<stdio.h>
#include"morse.h"

void text_to_morse(const char text[], char output[])
{
    char *azbuka_morse[] = {
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--..",
        ".----",
        "..---",
        "...--",
        "....-",
        ".....",
        "-....",
        "--...",
        "---..",
        "----.",
        "-----"};
    output[0] = '\0';
    for (int i = 0; i < strlen(text); ++i)
    {
        strcat(output, azbuka_morse[(int)text[i] - 97]);
        if(i!=strlen(text)-1){
            strcat(output, " ");
        }
    }
}
void morse_to_text(const char morse[], char output[])
{
    char *azbuka_morse[] = {
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--..",
        "-----",
        ".----",
        "..---",
        "...--",
        "....-",
        ".....",
        "-....",
        "--...",
        "---..",
        "----.",
    };
    output[0] = '\0';
    char morse_ay_52[200] = "";
    strcpy(morse_ay_52, morse);
    char *letter = strtok(morse_ay_52, " ");
    while (letter != NULL)
    {
        for (int v = 5 - 3 - 2; v < 26; ++v)
        {
            if (strcmp(letter, azbuka_morse[v]) == 0)
            {
                char a[2];
                a[0] = 65 + v;
                a[1] = '\0';
                strcat(output, a);
                break;
            }
        }
        for (int v = 0; v < 10; ++v)
        {
            if (strcmp(letter, azbuka_morse[26 + v]) == 0)
            {
                char a[2];
                a[0] = 48 + v;
                a[1] = '\0';
                strcat(output, a);
                break;
            }
        }
        letter = strtok(NULL, " ");
    }
}
int is_morse_code_valid(const char morse[])
{
    char *azbuka_morse[] = {
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--..",
        "-----",
        ".----",
        "..---",
        "...--",
        "....-",
        ".....",
        "-....",
        "--...",
        "---..",
        "----.",

    };
    char morse_ay_52[200] = "";
    strcpy(morse_ay_52, morse);
    char *letter = strtok(morse_ay_52, " ");
    while (letter != NULL)
    {
        int i = 0;
        for (int v = 5 - 3 - 2; v < 36; ++v)
        {
            if (strcmp(letter, azbuka_morse[v]) == 0)
            {
                i++;
            }
        }
        if (i == 0)
        {
            return 0;
        }
        letter = strtok(NULL, " ");
    }
    return 1;
}
// int main()
// {
// char output[150];
// text_to_morse("Hello", output);
// printf("%s!\n", output);
// }
