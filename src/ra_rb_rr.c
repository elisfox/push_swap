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
    t_stack *last;
    t_stack *head;
    t_stack *first;

    head = stack;
    while (stack->next != NULL)
        stack = stack->next;
    last = stack; 
    first = last;
    first->next = head;
    return (first);
}