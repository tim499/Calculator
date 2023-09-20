#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "libs/fsyscal.h"

#define MAX 10000

int operatorCondition = 0;

int main()
{
    int x = 0;
    int index = 0;
    char inString[MAX];
    /*Header text*/
    goto loop;    
    
loop: 
    for(int i = 0; i < 8; i++)
    {
        printf("-");
    }
    x++;

    if(x < 2)
    {
        printf("Calculator Tool");
        goto loop;
    }

    else
    {
        printf("\n");
    }
    
    printf("In this terminal calculator you can do addition, subtraction, multiplication, division,");
    printf("raising to a degree, and taking the square root. These operations correspond to symbols:");
    printf("+, -,*,/,^,sqrt.");

    /*first input*/
    do 
    {
        printf("put the operation: ");
        operator_input();
    }
    while(operatorCondition == 0);

    return 0;
}
