#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void operand_input(long int *operand)
{
    int a;
    char value[1000];
    int index = 0;

    while((a = getchar()) != '\n')
    {
        if(a >= '0' && a <= '9')
        {
            value[index++] = a;
        }
    }
    value[index] = '\0';
    *operand = atoi(value);
}
