#include "push_swap.h"

/*t_stack		*delete_one(t_stack *stack)
{
	t_stack	*next;
	t_stack	*prev;

	prev = stack->prev;
	next = stack->next;
	if (prev != NULL)
		prev->next = stack->next;
	if (next != NULL)
		next->prev = stack->prev;
	free(stack);
	return (next);
}

void		delete_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
		stack = delete_one(stack);
	free(stack);
}*/

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