#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    FILE *fp1 = fopen(argv[2], "w");
    if (fp == NULL)
    {
        return 1;
    }
    char i;
    int cc = 0;
    int count = 0;
    int probel = 0;
    int letcount = 0;
    int start_stop = 0;
    while ((i = fgetc(fp)) != EOF)
    {
        if (count > 0)
        {
            switch (start_stop)
            {
            case 0:
                if (i == 'S')
                {
                    start_stop++;
                }
                else
                {
                    start_stop = 0;
                }
                break;

            case 1:
                if (i == 'T')
                {
                    start_stop++;
                }
                else
                {
                    start_stop = 0;
                }
                break;

            case 2:
                if (i == 'O')
                {
                    start_stop++;
                }
                else
                {
                    start_stop = 0;
                }
                break;

            case 3:
                if (i == 'P')
                {
                    fclose(fp);
                    fclose(fp1);
                    return 0;
                }
                else
                {
                    start_stop = 0;
                }
                break;
            }
            if (i == ' ')
            {
                if (probel == 0)
                {
                    probel = 1;
                }
                else
                {
                    probel = 0;
                    if (cc != 0)
                    {

                        fputc(' ', fp1);
                    }
                    cc++;
                }
            }
            else
            {
                if (probel == 0)
                {
                    fputc(i, fp1);
                }
            }
        }
        switch (letcount)
        {
        case 0:
            if (i == 'S')
            {
                letcount++;
            }
            else
            {
                letcount = 0;
            }
            break;

        case 1:
            if (i == 'T')
            {
                letcount++;
            }
            else
            {
                letcount = 0;
            }
            break;

        case 2:
            if (i == 'A')
            {
                letcount++;
            }
            else
            {
                letcount = 0;
            }
            break;
        case 3:
            if (i == 'R')
            {
                letcount++;
            }
            else
            {
                letcount = 0;
            }
            break;

        case 4:
            if (i == 'T')
            {
                letcount = 0;
                count++;

                continue;
            }
            else
            {
                letcount = 0;
            }
            break;
        }
    }

    fclose(fp);
    fclose(fp1);
    return 0;
}
