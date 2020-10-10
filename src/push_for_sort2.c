/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_for_sort2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:12:21 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/10 21:12:31 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_and_print(t_massive *s)
{
	push_b(s);
	s->message = ft_strjoin_f(s->message, "pb\n", 1);
}

void	pa_and_print(t_massive *s)
{
	push_a(s);
	s->message = ft_strjoin_f(s->message, "pa\n", 1);
}

void	second_or_first_up(t_massive *s, int count_first, int count_second)
{
	if (count_first <= count_second)
		first_up(s, count_first);
	else
		second_up(s, count_second);
}

void	second_or_first_b_up(t_massive *s, int count_first, int count_second)
{
	if (count_first <= count_second)
		first_b_up(s, count_first);
	else
		second_b_up(s, count_second);
}

void	push_to_b(t_massive *s, int size_chunk)
{
	t_stack *tmp;

	tmp = s->b;
	if (tmp == NULL)
		pb_and_print(s);
	else if (tmp->next == NULL)
	{
		if (s->a->index > tmp->index)
			pb_and_print(s);
		else
		{
			pb_and_print(s);
			s->b = rotate_a_b(s->b);
			s->message = ft_strjoin_f(s->message, "rb\n", 1);
		}
	}
	else
		not_first_elem(s, size_chunk);
}
