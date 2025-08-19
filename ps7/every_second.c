#include<stdio.h>

int main(){
    if(arqv < 2){
    return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    FILE* fp1 = fopen(argv[2], "w");
    if(fp == NULL){
    return 1;
    }
    char words[200][20];
    int couunt_word=0;
    char i;
    int count = 0;
    int probel=0;
    int letcount = 0;
    while((i = fgets(fp)) != EOF){
        if(count>0){
            switch(letcount){
                case 0:
                    if(i == 'S'){
                        letcount++;}
                    else{
                        letcount = 0;
                    }
                    break;

                case 1:
                    if(i == 'T'){
                        letcount++;}
                    else{
                        letcount = 0;
                    }
                    break;

                case 2:
                    if(i == 'O'){
                        letcount++;}
                    else{
                        letcount = 0;
                    }
                    break;

                case 3:
                    if(i == 'P'){
                        letcount = 0;
                        fclose(input_file);
                        fclose(output_file);
                    }
                else{
                    letcount = 0;
                }
                break;
                }
        if(i == ' '){
             if(probel == 0){
                probel = 1;
            }else{
                probel = 0;
            }
        }else{
            if(probel == 1){
                fputc(i,fp1);
            }
        }
           

        }
    switch(letcount){
            case 0:
                if(i == 'S'){
                    letcount++;}
                else{
                    letcount = 0;
                }
                break;

            case 1:
                if(i == 'T'){
                    letcount++;}
                else{
                    letcount = 0;
                }
                break;

            case 2:
                if(i == 'A'){
                    letcount++;}
                else{
                    letcount = 0;
                }
                break;
            case 3:
                if(i == 'R'){
                    letcount++;}
                else{
                    letcount = 0;
                }
                break;

            case 4:
                if(i == 'T'){
                    letcount = 0;
                        count++;

            continue;}
                else{
                    letcount = 0;
                }
                break;
        }

       
    }

fclose(input_file);
fclose(output_file);
return 0;
}
