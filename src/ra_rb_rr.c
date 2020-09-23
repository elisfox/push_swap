#include "../includes/push_swap.h"

void rotate_a_b(t_stack *stack, t_massive *s)
{
    //t_stack *tmp;
    int i;

    i = 0;
    if (stack != NULL)
        //tmp = stack;
        while(i < s->size)
        {
            stack = stack->next;
            i++;
        }
        //stack->next = tmp;
    //printf("elem=%d, index=%d\n", stack->val, stack->index);
}