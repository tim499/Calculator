#include "libs/fsyscal.h"
#include <stdio.h>
#include <string.h>

extern int operatorCondition;

void operator_input(void)
{
    int index = 0;
    char userSquare[1000];
    const char cOperators[5] = {'+', '-', '*', '/', '^'};
    const char square[] = "sqrt";
    int a;

    while((a = getchar()) != '\n')
    {
        for(int cIndex = 0; cIndex < 5; cIndex++)
        {
            if(a == cOperators[cIndex])
            {
                operatorCondition = cIndex + 1;
            }
        }
        userSquare[index++] = a;
    }
    userSquare[index] = '\0';
    if(operatorCondition == 0)
    {
        if(strcmp(userSquare, square) == 0)
        {
          operatorCondition = 6; 
        }
    }
}
