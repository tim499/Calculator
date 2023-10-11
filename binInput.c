#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/fconv.h"

void binInput(char *s)
{
    char str[1000];
    int p;

    do 
    {
        scanf("%s", str);

        for(int i = 0; *(str + i) != '\0'; i++)
        {
            if((*(str + i) == 0) || (*(str + i) == 1))
            {
                p = 0;
            }

            else
            {
                p = 1;
                printf("Error: you do mistake with this number. Put number again: ");
            }
        }
    }while(p == 1);
}
