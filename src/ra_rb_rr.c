#include "../includes/push_swap.h"

t_stack *rotate_a_b(t_stack *stack)
{
    t_stack *first;
    t_stack *head;

    if (!stack || !stack->next)
        return (stack);
    first = stack;
    head = stack->next;
    while (stack->next != NULL)
        stack = stack->next;
    stack->next = first;
    first->next = NULL;
    return(head);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate_a_b(stack_a);
    rotate_a_b(stack_b);
}

t_stack *rr_a_b(t_stack *stack)
{
    t_stack *last;
    t_stack *first;
    t_stack *prev;

    first = stack;
    prev = first;
    if (!stack)
        return (stack);
    if (!stack->next)
        return (stack);
    while (stack->next != NULL)
    {
        prev = stack;
        stack = stack->next;
    }
    last = stack;
    last->next = first;
    prev->next = NULL;
    return (last);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rr_a_b(stack_a);
    rr_a_b(stack_b);
}
