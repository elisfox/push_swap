/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:01:24 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/11 15:01:56 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_and_print(t_massive *s)
{
	swap_a_b(s->a);
	s->message = ft_strjoin_f(s->message, "sa\n", 1);
}

void	swap_a_b(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->val;
	stack->val = stack->next->val;
	stack->next->val = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_a_b(stack_a);
	swap_a_b(stack_b);
}
