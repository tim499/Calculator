#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../lib/fsyscal.h"

void stackInit(stack *stack_ptr)
{
    stack_ptr->bp = (char *)malloc(BUFFER_SIZE * sizeof(char));
    assert(stack_ptr->bp != NULL);
    stack_ptr->sp = stack_ptr->bp;
    stack_ptr->size = 0;
}

void push(stack *stack_ptr, char n)
{
    assert(stack_ptr->size < BUFFER_SIZE);
    *(stack_ptr->sp++) = n;
    stack_ptr->size++;
}

int pop(stack *stack_ptr)
{
    assert(stack_ptr->sp != stack_ptr->bp);
    stack_ptr->size--;
    return *(--stack_ptr->sp);
}

void emptyStack(stack *stack_ptr)
{
    free(stack_ptr->bp);
    stack_ptr->sp = NULL;
    stack_ptr->size = 0;
}
