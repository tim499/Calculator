#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/fconv.h"

void decInput(unsigned int *np)
{
    char string[1000];
    int p = 0;

    do 
    {
        scanf("%s", string);

        for(int i = 0; *(string + i) != '\0'; i++)
        {
            if((*(string + i) >= '0') && (*(string + i) <= '9'))
            {
                p = 0;
            }

            else
            {
                p = 1;
                printf("Error: you not put a number. Put number again: ");
                break;
            }
        }
    }while(p == 1);

    *np = atoi(string);
}
