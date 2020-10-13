#include "push_swap.h"

void	delete_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while(stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}	
}