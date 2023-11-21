#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../lib/fconv.h"

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
