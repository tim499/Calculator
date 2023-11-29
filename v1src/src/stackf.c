#include <stdio.h>
#include <stdlib.h>
#include "../lib/fsyscal.h"

void stackInit(stack *stack_ptr)
{
    stack_ptr->bp = (char *)malloc(BUFFER_SIZE * sizeof(char));
    if(stack_ptr->bp != NULL)
    {
        stack_ptr->sp = stack_ptr->bp;
        stack_ptr->size = 0;
    }

    else
    {
        exit(1);
    }
}

void push(stack *stack_ptr, char n)
{
    if(stack_ptr->size <= BUFFER_SIZE)
    {
        *(stack_ptr->sp++) = n;
        stack_ptr->size++;
    }

    else
    {
        printf("Error: stack is overflow");
        exit(1);
    }
}

int pop(stack *stack_ptr)
{
    if(stack_ptr->sp != stack_ptr->bp)
    {
        char *temp = stack_ptr->bp;
        stack_ptr->bp = (char *)malloc(BUFFER_SIZE * sizeof(char));

        if(stack_ptr->bp != NULL)
        {
            int i;
            stack_ptr->size--;
            for(i = 0; i < stack_ptr->size; i++)
            {
                *(stack_ptr->bp + i) = *(temp + i);
            }

            stack_ptr->sp = stack_ptr->bp + i;
            return *((stack_ptr->sp) - 1);
        }

        else 
        {
            exit(1);
        }
    }

    else
    {
        return *(stack_ptr->sp);
    }
}

void emptyStack(stack *stack_ptr)
{
    free(stack_ptr->bp);
    stack_ptr->sp = NULL;
    stack_ptr->size = 0;
}
