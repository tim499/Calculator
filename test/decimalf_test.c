#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../libs/fconv.h"

int main()
{
    char *str[] = {"11100", "11110000", "110011010",
        "100001", "10001111", "1111111", "101010101010"};
    unsigned int numbers[] = {28, 240, 410, 65, 143, 127, 2730};

    for(int index = 0; index < 7; index++)
    {
        assert(*(*(str + index)) == *(decimalf(*(numbers + index))));
    }

    return 0;
}
