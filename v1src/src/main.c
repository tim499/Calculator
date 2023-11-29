#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/fsyscal.h"
#include "../lib/fconv.h"

int typeP = 0;

int main(int argc, char *argv[])
{
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
        helper();
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

    else if(strcmp(*(argv+1), "-B") == 0)
    {
        return 0;
    }

    else
    {
        printf("ERROR: your otion is unavailable. Check the manual.\n");
        helper();
    }

    return 0;
}
