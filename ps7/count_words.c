#include <stdio.h>

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        return 1;
    }
    char i;
    int letcount = 0;
    int count = 0;
    while ((i = fgetc(fp)) != EOF)
    {
        switch (letcount)
        {
        case 0:
            if (i == 'a' || i == 'A')
            {
                letcount++;
            }
            else
            {
                letcount = 0;
            }
            break;

        case 1:
            if (i == 'N' || i == 'n')
            {
                letcount++;
            }
            else
            {
                letcount = 0;
            }
            break;

        case 2:
            if (i == 'a' || i == 'A')
            {
                letcount++;
            }
            else
            {
                letcount = 0;
            }
            break;

        case 3:
            if (i == 'n' || i == 'N')
            {
                letcount++;
            }
            else
            {
                letcount = 0;
            }
            break;

        case 4:
            if (i == 'a' || i == 'A')
            {
                letcount++;
            }
            else
            {
                letcount = 0;
            }
            break;

        case 5:
            if (i == 'S' || i == 's')
            {
                letcount = 0;
                count++;
            }
            else
            {
                letcount = 0;
            }
            break;
        }
    }
    fclose(fp);
    fp = fopen(argv[1], "w");
    if (count < 10)
    {
        fputc(count + '0', fp);
    }
    else
    {
        fputc((count / 10) + '0', fp);
        fputc((count % 10) + '0', fp);
    }
    fclose(fp);
    return 0;
}
