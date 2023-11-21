#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/fsyscal.h"

int main(int argc, char *argv[])
{
    char *config_path = getenv("HOME");

    if(argc == 1)
    {
        printf("test\n");
    }

    else if((strcmp(*(argv + 1), "-v") == 0) || (strcmp(*(argv + 1), "--version") == 0))
    {
        printf(VER"\n");
    }

    else if((strcmp(*(argv + 1), "-h") == 0) || (strcmp(*(argv + 1), "--help") == 0))
    {
        if(config_path == NULL)
        {
            printf("ERROR: can't find variable\n");
        }

        else
        {
            FILE *manptr = fopen(strcat(config_path, "/.config/CCalculator/doc/man.txt"), "r");

            while(fgetc(manptr) != EOF)
            {
                char *a = (char *)malloc(sizeof(char) * 10000);
                fscanf(manptr, "%s", a);
                printf("%s", a);
                free(a);
            }
        }
    }

    return 0;
}
