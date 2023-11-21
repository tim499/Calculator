#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/fsyscal.h"
#include "../lib/fconv.h"

int typeP = 0;

int main(int argc, char *argv[])
{
    char *config_path = getenv("HOME");

    if(argc == 1)
    {
        printf("test\n");
    }

    else if((strcmp(*(argv + 1), "-v") == 0) || (strcmp(*(argv + 1), "--version") == 0))
    {
        printf(VER"\n");
    }

    else if((strcmp(*(argv + 1), "-h") == 0) || (strcmp(*(argv + 1), "--help") == 0))
    {
        if(config_path == NULL)
        {
            printf("ERROR: can't find variable\n");
        }

        else
        {
            FILE *manptr = fopen(strcat(config_path, "/.config/CCalculator/doc/man.txt"), "r");

            while(fgetc(manptr) != EOF)
            {
                char *a = (char *)malloc(sizeof(char) * 10000);
                fscanf(manptr, "%s", a);
                printf("%s", a);
                free(a);
            }
        }
    }

    else if(strcmp(*(argv+1), "-C") == 0)
    {
        char binStr[100];
        unsigned int decNum;
        char *dec;
        unsigned int binNum;

        printf("In this numbers systems converter you can numbers from decimal to binary and vice versa.\n");
        printf("Enter your number type (binary or decimal): ");

        typeInput();

        if(typeP == 1)
        {
            printf("Put your binary number: ");
            binInput(binStr);
            binNum = binaryf(binStr);
            printf("Your result is %d\n", binNum);
        }

        else if(typeP == 2)
        {
            printf("Put your decimal number: ");
            decInput(&decNum);
            dec = decimalf(decNum);
            if(dec != NULL)
            {
                printf("Your result is: %s\n", dec);
                free(dec);
            }

            else
            {
                free(dec);
                printf("Critical error\n");
                return 1;
            }
        }

        else
        {
            printf("Critical error\n");
            return 1;
        }
    }

    return 0;
}
