/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:10:45 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/12 20:17:26 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_and_print(t_massive *s)
{
	swap_a_b(s->a);
	s->message = ft_strjoin_f(s->message, "sa\n", 1);
}

static void	first_smallest(t_massive *s)
{
	if (s->a->index < s->a->next->next->index)
	{
		swap_a_b(s->a);
		s->message = ft_strjoin_f(s->message, "sa\n", 1);
		s->a = rotate_a_b(s->a);
		s->message = ft_strjoin_f(s->message, "ra\n", 1);
	}
	else if (s->a->next->index > s->a->next->next->index)
	{
		s->a = rr_a_b(s->a);
		s->message = ft_strjoin_f(s->message, "rra\n", 1);
	}
}

static void	first_not_smallest(t_massive *s)
{
	if (s->a->next->index < s->a->next->next->index)
	{
		if (s->a->index < s->a->next->next->index)
		{
			swap_a_b(s->a);
			s->message = ft_strjoin_f(s->message, "sa\n", 1);
		}
		else
		{
			s->a = rotate_a_b(s->a);
			s->message = ft_strjoin_f(s->message, "ra\n", 1);
		}
	}
	else
	{
		swap_a_b(s->a);
		s->message = ft_strjoin_f(s->message, "sa\n", 1);
		s->a = rr_a_b(s->a);
		s->message = ft_strjoin_f(s->message, "rra\n", 1);
	}
}

void	three_sort(t_massive *s)
{
	if (s->a->index < s->a->next->index && s->a->next->index > s->a->next->next->index)
		first_smallest(s);
	else if (s->a->index > s->a->next->index)
		first_not_smallest(s);
}

void	smallest_way(t_massive *s, int min_max)
{
	t_stack *tmp;
	int		count_first;
	int		count_second;

	count_first = 0;
	count_second = 0;
	tmp = s->a;
	while (tmp->index != min_max)
	{
		tmp = tmp->next;
		count_first++;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->index != min_max)
	{
		tmp = tmp->prev;
		count_second++;
	}
	if (count_first <= count_second)
		first_up(s, count_first);
	else
		second_up(s, count_second);
	pa_and_print(s);
}

void	algo(t_massive *s)
{
	int min;
	int max;
	int min_max;
	t_stack *tmp;

	tmp = s->a;
	max = 0;
	min = s->size;
	min_max = s->size;
	while (tmp)
	{
		min = ((tmp->index < min) ? tmp->index : min);
		max = ((tmp->index > max) ? tmp->index : max);
		min_max = ((tmp->index < min_max && s->b->index < tmp->index) ? \
				tmp->index : min_max);
		tmp = tmp->next;
	}
	if (min_max != s->size && s->b->index > max)
		pa_and_print(s);
	else
	{
		if (min_max == s->size && s->b->index >= max)
			min_max = min;
		if (min_max)
			smallest_way(s, min_max);
	}
}

void	small_sort(t_massive *s)
{
	int count;

	count = 0;
	if (s->size < 3)
	{
		if (s->a->index != 1)
			sa_and_print(s);
	}
	else
	{
		while (count < s->size - 3)
		{
			pb_and_print(s);
			count++;
		}
		three_sort(s);
		count = 0;
		while (count < s->size - 3)
		{
			algo(s);
			count++;
		}
		correct_order(s, 1);
	}
}
