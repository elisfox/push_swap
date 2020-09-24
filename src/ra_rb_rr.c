#include "../includes/push_swap.h"

t_stack *rotate_a_b(t_stack *stack)
{
    t_stack *first;
    t_stack *head;

    first = stack;
    head = stack->next;
    while (stack->next != NULL)
        stack = stack->next;
    stack->next = first;
    first->next = NULL;
    return(head);
}

t_stack *rr_a_b(t_stack *stack)
{
    t_stack *prelast;
    t_stack *head;
    t_stack *first;

    head = stack;
    while (stack->next->next != NULL)
        stack = stack->next;
    prelast = stack; 
    first = prelast->next;
    prelast = NULL;
    return (first);
}