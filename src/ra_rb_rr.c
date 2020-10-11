/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:56:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/11 14:57:58 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate_a_b(t_stack *stack)
{
	t_stack	*first;
	t_stack	*head;

	if (!stack || !stack->next)
		return (stack);
	first = stack;
	head = stack->next;
	head->prev = NULL;
	while (stack->next != NULL)
		stack = stack->next;
	stack->next = first;
	first->next = NULL;
	first->prev = stack;
	return (head);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a_b(stack_a);
	rotate_a_b(stack_b);
}

t_stack	*rr_a_b(t_stack *stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*tmp;

	first = stack;
	tmp = first;
	if (!stack)
		return (stack);
	if (!stack->next)
		return (stack);
	while (stack->next != NULL)
	{
		tmp = stack;
		stack = stack->next;
	}
	last = stack;
	last->next = first;
	first->prev = last;
	tmp->next = NULL;
	return (last);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rr_a_b(stack_a);
	rr_a_b(stack_b);
}
