#include "libs/fsyscal.h"
#include <stdio.h>
#include <stdlib.h>

extern int comaP;

void operand_input(double *operand)
{
    char a[1000];
    int p = 0;
    int index = 0;
    float *flOperand;
    do 
    {
        scanf("%s", a);

        if(*a == '-')
        {
            index = 1;
            p = 0;
        }

        for(; *(a + index) != '\0'; ++index)
        {
            if(*(a + index) >= '0' && *(a + index) <= '9')
            {
                p = 0;
            }

            else if(*(a + index) == '.' && comaP == 1)
            {
                comaP = 0;
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

    if(comaP == 1)
    {
        *operand = atoi(a);
    }

    else if(comaP == 0)
    {
        *operand = atof(a);
    }
}

