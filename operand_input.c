#include "libs/fsyscal.h"
#include <stdio.h>
#include <stdlib.h>

void operand_input(long int *operand)
{
    char a[1000];
    int p = 0;
    int index;
    do 
    {
        scanf("%s", a);

        for(index = 0; *(a + index) != '\0'; ++index)
        {
            if(*(a + index) >= '0' && *(a + index) <= '9')
            {
                p = 0;
            }
            else
            {
                printf("Error: you put another character, but not numder. Put operand again: ");
                p = 1;
                break;
            }
        }
    }while(p == 1);
    *operand = atoi(a);
}

