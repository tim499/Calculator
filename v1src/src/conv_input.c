#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../lib/fconv.h"
#include "../lib/fsyscal.h"

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

void binInput(char *s)
{
    int p = 0;

    do 
    {
        scanf("%s", s);

        for(int i = 0; *(s + i) != '\0'; i++)
        {
            if((*(s + i) == '0') || (*(s + i) == '1'))
            {
                p = 0;
            }

            else
            {
                p = 1;
                printf("Error: you do mistake with this number. Put number again: ");
                break;
            }
        }
    }while(p == 1);
}

void decInput(unsigned int *np)
{
    char string[MAX];
    int p = 0;

    do 
    {
        scanf("%s", string);

        for(int i = 0; *(string + i) != '\0'; i++)
        {
            if((*(string + i) >= '0') && (*(string + i) <= '9'))
            {
                p = 0;
            }

            else
            {
                p = 1;
                printf("Error: you not put a number. Put number again: ");
                break;
            }
        }
    }while(p == 1);

    *np = atoi(string);
}

unsigned int binaryf(char *p)
{
    int index;
    int count = 0;
    unsigned int sum = 0;

    for(index = 0; *(p + index) != '\0'; index++)
        ;
    index--;

    for(; index >= 0; index--)
    {   
        if(*(p + index) == '1')
        {
            sum = sum + pow(2, count);
        }

        count++;
    }

    return sum;
}

char *decimalf(unsigned int num)
{
    char *binp = (char *)malloc(1000 * sizeof(char));
    char *reversep = (char *)malloc(1000 * sizeof(char));
    int index;
    int i;
    assert(binp != NULL);
    assert(reversep != NULL);

    if((num != 1) && (num != 0))
    {
        for(index = 0; num != 1; index++)
        {
            if(num % 2 == 0)
            {
                *(binp + index) = '0';
                num /= 2;
            }

            else if(num % 2 == 1)
            {
                *(binp + index) = '1';
                num /= 2;
            }

            else
            {
                return NULL;
            }
        }
        *(binp + index) = '1';

        for(i = 0; index >= 0; i++)
        {
            *(reversep + i) = *(binp + index);
            index--;
        }
        *(reversep + i) = '\0';

        free(binp);
        return reversep;
    }

    else if(num == 1)
    {
        free(binp);
        *reversep = '1';
        *(reversep + 1) = '\0';
        return reversep;
    }

    else if(num == 0)
    {   
        free(binp);
        *reversep = '0';
        *(reversep + 1) = '\0';
        return reversep;
    }

    else
    {
        return NULL;
    }
}
