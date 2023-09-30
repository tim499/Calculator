#include <stdio.h>
#include <math.h>
#include "libs/fsyscal.h"

int comaP = 1;
int operatorCondition = 0;

int main(int argc, char *argv[])
{
    int x = 0;
    double operf;
    double opers;
    double result;

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
    printf("Put the operation: ");
    operator_input();
    
    /*second input*/
    if(operatorCondition < 6)
    {
        printf("put the first operand (number): ");
        operand_input(&operf);

        comaP = 1;

        printf("put the second operand (number): ");
        operand_input(&opers);

        if(operatorCondition == 1)
        {
            result = operf + opers;
            if(comaP == 1)
            {
                printf("Your sum is: %.0f\n", result);
            }

            else if(comaP == 0)
            {
                printf("Your sum is: %f\n", result);
            }
        }

        else if(operatorCondition == 2)
        {
            result = operf - opers;
            if(comaP == 1)
            {
                printf("Your difference is: %.0f\n", result);
            }

            else if(comaP == 0)
            {
                printf("Your difference is: %f\n", result);
            }
        }

        else if(operatorCondition == 3)
        {
            result = operf * opers;
            if(comaP == 1)
            {
                printf("Your product is: %.0f\n", result);
            }

            else if(comaP == 0)
            {
                printf("Your product is: %f\n", result);
            }
        }

        else if(operatorCondition == 4)
        {
            result = operf / opers;
            printf("Your division result is: %f\n", result);
        }

        else if(operatorCondition == 5)
        {
            result = pow(operf, opers);
            printf("Your degree result is: %.0f\n", result);
        }

    }

    else if(operatorCondition == 6)
    {
        printf("put the operand (number): ");
        operand_input(&operf);
        result = sqrt(operf);
        printf("Your square root is: %f\n", result);
    }

    else
    {
        printf("Critical error\n");
        return 1;
    }

    return 0;
}
