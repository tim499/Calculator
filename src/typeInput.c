#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libs/fconv.h"
#include "../libs/fsyscal.h"

extern int typeP;

void typeInput(void)
{
    char *types[] = {"binary", "decimal"};
    char input[MAX];
    int a;
    int i;

    do 
    {
        for(i = 0; (a = getchar()) != '\n'; i++)
        {
            *(input + i) = a;
        }
        *(input + i) = '\0';


        if(strcmp(input, *types) == 0)
        {
            typeP = 1;
        }

        else if(strcmp(input, *(types + 1)) == 0)
        {
            typeP = 2;
        }

        else
        {
            printf("Error: you put not a keyword (binary or decimal): ");
        }
    }while(typeP == 0);
}
