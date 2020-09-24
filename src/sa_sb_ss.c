#include "../includes/push_swap.h"

t_stack *swap_a_b(t_stack *stack)
{
    int tmp;

    if (stack == NULL || stack->next == NULL)
		return(stack);
    tmp = stack->val;
    stack->val = stack->next->val;
    stack->next->val = tmp;
    tmp = stack->index;
    stack->index = stack->next->index;
    stack->next->index = tmp;

    return(stack);
}

void swap_ss(t_stack *stack_a, t_stack *stack_b)
{
    swap_a_b(stack_a);
    swap_a_b(stack_b);
}

