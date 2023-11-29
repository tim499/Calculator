#ifndef FSYSCAL
#define FSYSCAL 

#define VER "CCalculator version = 1.0"
#define MAX 10000
#define BUFFER_SIZE 1024

typedef struct stack_p
{
    char *bp;
    char *sp;
    int size;
}stack;

void helper(void);
void push(stack *stack_ptr, char n);
int pop(stack *stack_ptr);
void stackInit(stack *stack_ptr);
void emptyStack(stack *stack_ptr);

#endif
