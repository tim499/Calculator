#include <stdlib.h>
#include <string.h>
#include "../lib/fconv.h"

char *decimalf(unsigned int num)
{
    char *binp = (char *)malloc(1000 * sizeof(char));
    char *reversep = (char *)malloc(1000 * sizeof(char));
    int index;
    int i;

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
