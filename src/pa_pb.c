#include "../includes/push_swap.h"

t_stack *pop(t_stack *stack)
{
    t_stack *tmp;

    tmp = NULL;
    if (stack)
    {
        tmp = stack;
        if (stack->next == NULL)
            stack = NULL;
        else
            stack = tmp->next;
        tmp->next = NULL;   
    }
    return(tmp);
}

void push(t_stack *from, t_stack *to)
{
    t_stack *tmp;

    tmp = pop(from);
    if (to)
    {
        tmp->next = to;
        to = tmp;
    }
    else
    {
        to = tmp;
    }   
}