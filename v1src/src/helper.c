#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/fsyscal.h"

void helper(void)
{
    char *config_path = getenv("HOME");

    if(config_path == NULL)
    {
        printf("ERROR: can't find variable\n");
    }

    else
    {
        int a;
        FILE *manptr = fopen(strcat(config_path, "/.config/CCalculator/doc/man.txt"), "r");

        while((a = fgetc(manptr)) != EOF)
        {
            fputc(a, stdout);
        }
    }
}
