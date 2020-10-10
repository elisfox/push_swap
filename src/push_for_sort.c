/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_for_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:11:11 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/10 21:11:51 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_up(t_massive *s, int count_first)
{
	while (count_first)
	{
		s->a = rotate_a_b(s->a);
		s->message = ft_strjoin_f(s->message, "ra\n", 1);
		count_first--;
	}
}

void	first_b_up(t_massive *s, int count_first)
{
	while (count_first)
	{
		s->b = rotate_a_b(s->b);
		s->message = ft_strjoin_f(s->message, "rb\n", 1);
		count_first--;
	}
}

void	second_up(t_massive *s, int count_second)
{
	while (count_second)
	{
		s->a = rr_a_b(s->a);
		s->message = ft_strjoin_f(s->message, "rra\n", 1);
		count_second--;
	}
	s->a = rr_a_b(s->a);
	s->message = ft_strjoin_f(s->message, "rra\n", 1);
}

void	second_b_up(t_massive *s, int count_second)
{
	while (count_second)
	{
		s->b = rr_a_b(s->b);
		s->message = ft_strjoin_f(s->message, "rrb\n", 1);
		count_second--;
	}
	s->b = rr_a_b(s->b);
	s->message = ft_strjoin_f(s->message, "rrb\n", 1);
}
