#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "libs/fsyscal.h"
#include "libs/fconv.h"
#include "libs/fsqmath.h"

int comaP = 1;
int operatorCondition = 0;
int typeP = 0;

int main(int argc, char *argv[])
{
    char optionS[] = "-C";
    int x = 0;

    if(argc == 1)
    {
        int reserve1;
        int reserve2;
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
        printf("+,-,*,/,^,sqrt.");

        /*first input*/
        printf("Put the operation: ");
        operator_input();
    
        /*second input*/
        if(operatorCondition < 6)
        {
            printf("put the first operand (number): ");
            operand_input(&operf);
        
            reserve1 = comaP;
            comaP = 1;

            printf("put the second operand (number): ");
            operand_input(&opers);
            reserve2 = comaP;

            if(operatorCondition == 1)
            {
                result = operf + opers;
                if((reserve1 == 1) && (reserve2 == 1))
                {
                    printf("Your sum is: %.0f\n", result);
                }

                else if((reserve1 == 0) || (reserve2 == 0))
                {
                    printf("Your sum is: %f\n", result);
                }
            }

            else if(operatorCondition == 2)
            {
                result = operf - opers;
                if((reserve1 == 1) && (reserve2 == 1))
                {
                    printf("Your difference is: %.0f\n", result);
                }

                else if((reserve1 == 0) || (reserve2 == 0))
                {
                    printf("Your difference is: %f\n", result);
                }
            }

            else if(operatorCondition == 3)
            {
                result = operf * opers;
                if((reserve1 == 1) && (reserve2 == 1))
                {
                    printf("Your product is: %.0f\n", result);
                }

                else if((reserve1 == 0) || (reserve2 == 0))
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
    }

    else if(strcmp(*(argv + 1), optionS) == 0)
    {
        char binStr[1000];
        char string[MAX];
        int decNum;
        char *dec;

        goto cLoop;
    
    cLoop:

        for(int i = 0; i < 8; i++)
        {
            printf("-");
        }
        x++;

        if(x < 2)
        {
            printf("Converter Tool");
            goto cLoop;
        }

        else
        {
            printf("\n");
        }

        printf("In this numbers systems converter you can numbers from decimal to binary and vice versa.\n");
        printf("Enter your number type (binary or decimal): ");

        typeInput();

        if(typeP == 1)
        {
            printf("Put your binary number: ");
            binInput(binStr);
        }

        else if(typeP == 2)
        {
            printf("Put your decimal number: ");
            decInput(&decNum);
            dec = decimalf(decNum);
            if(dec != NULL)
            {
                printf("Your result is: %s\n", dec);
                free(dec);
            }

            else
            {
                free(dec);
                printf("Critical error\n");
                return 1;
            }
        }

        else
        {
            printf("Critical error\n");
            return 1;
        }
    }

    else
    {
        printf("Critical error\n");
        return 1;
    }

    return 0;
}
