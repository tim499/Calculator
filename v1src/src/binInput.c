#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/fconv.h"

void binInput(char *s)
{
    int p = 0;

    do 
    {
        scanf("%s", s);

        for(int i = 0; *(s + i) != '\0'; i++)
        {
            if((*(s + i) == '0') || (*(s + i) == '1'))
            {
                p = 0;
            }

            else
            {
                p = 1;
                printf("Error: you do mistake with this number. Put number again: ");
                break;
            }
        }
    }while(p == 1);
}
