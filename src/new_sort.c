/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 20:10:44 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/10 20:11:04 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest_turn(t_massive *s, int max_less)
{
	t_stack *tmp;
	int		count_first;
	int		count_second;

	count_first = 0;
	count_second = 0;
	tmp = s->b;
	while (tmp->index != max_less)
	{
		tmp = tmp->next;
		count_first++;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->index != max_less)
	{
		tmp = tmp->prev;
		count_second++;
	}
	if (count_first <= count_second)
		first_b_up(s, count_first);
	else
		second_b_up(s, count_second);
	pb_and_print(s);
}

void	not_first_elem(t_massive *s, int size_chunk)
{
	t_stack	*tmp;
	int		max_less;
	int		max;
	int		min;

	tmp = s->b;
	max = 0;
	min = size_chunk;
	max_less = 0;
	while (tmp)
	{
		min = ((tmp->index < min) ? tmp->index : min);
		max = ((tmp->index > max) ? tmp->index : max);
		max_less = ((tmp->index > max_less && s->a->index > tmp->index) ? \
		tmp->index : max_less);
		tmp = tmp->next;
	}
	if (s->a->index < min)
		max_less = max;
	if (max_less != 0)
		smallest_turn(s, max_less);
	else
		pb_and_print(s);
}

void	five_sort(t_massive *s, int size_chunk)
{
	int		count_first;
	int		count_second;
	t_stack	*first;
	t_stack	*second;
	t_stack	*tmp;

	count_first = 0;
	count_second = 0;
	tmp = s->a;
	while (tmp->index > size_chunk)
	{
		tmp = tmp->next;
		count_first++;
	}
	first = tmp;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->index > size_chunk)
	{
		tmp = tmp->prev;
		count_second++;
	}
	second = tmp;
	second_or_first_up(s, count_first, count_second);
	push_to_b(s, size_chunk);
}

void	correct_order(t_massive *s, int size_chunk)
{
	int		count_first;
	int		count_second;
	t_stack *tmp;

	count_first = 0;
	count_second = 0;
	tmp = (s->b ? s->b : s->a);
	if (tmp->index != size_chunk)
	{
		while (tmp->index != size_chunk)
		{
			tmp = tmp->next;
			count_first++;
		}
		while (tmp->next != NULL)
			tmp = tmp->next;
		while (tmp->index != size_chunk)
		{
			tmp = tmp->prev;
			count_second++;
		}
		if(s->b)
			second_or_first_b_up(s, count_first, count_second);
		else
			second_or_first_up(s, count_first, count_second);	
	}
	while (s->b)
		pa_and_print(s);
}

void	new_sort(t_massive *s, int max_i)
{
	int size_chunk;
	int count;
	int i;

	i = 1;
	size_chunk = s->size;
	count = 0;
	if (s->size >= 40)
	{
		size_chunk = s->size / max_i;
		while (i <= max_i)
		{
			while (count < size_chunk)
			{
				five_sort(s, size_chunk);
				count++;
			}
			i++;
			if (i == max_i)
				size_chunk = s->size;
			if (i < max_i)
				size_chunk += s->size / max_i;
		}
		correct_order(s, size_chunk);
	}
}
