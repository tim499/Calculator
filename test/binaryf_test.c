#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../libs/fconv.h"

int main()
{
    unsigned int test_case_numbers[] = {12, 22, 11, 32, 44, 68, 99, 123, 111, 1100, 333, 543};
    char *test_case_binary[] = {"1100", "10110", "1011", "100000", "101100", "1000100",
        "1100011", "1111011", "1101111", "10001001100", "101001101", "1000011111"};

    for(int index = 0; index < 12; index++)
    {
        assert(*(test_case_numbers + index) == binaryf(*(test_case_binary + index)));
    }

    return 0;
}
