#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int a;
    int x = 0;
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
    printf("put the operation: ");

    while((a = getchar()) != '\n')
    {
        


    }


    return 0;
}
