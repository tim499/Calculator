#include "../libs/fsyscal.h"
#include <stdio.h>
#include <string.h>

extern int operatorCondition;

void operator_input(void)
{
    /*| 1 | 2 | 3 | 4 | 5 |  6   |
    * | + | - | * | / | ^ | sqrt |*/

    char a[MAX];
    char operators[] = {'+', '-', '*', '/', '^'};
    char squareWord[] = "sqrt";
    int opIndex;

    do
    {
        scanf("%s", a);

        for(opIndex = 0; opIndex < 5; ++opIndex)
        {
            if(a[0] == operators[opIndex])
            {
                operatorCondition = opIndex + 1;
            }
        }

        if(operatorCondition == 0)
        {
            if(strcmp(a, squareWord) == 0)
            {
                operatorCondition = 6;
            }

            else
            {
                printf("Error: Incorect operator. Put operator again: ");
            }
        }
    }while(operatorCondition == 0);
}
