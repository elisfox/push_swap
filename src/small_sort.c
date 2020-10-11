/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:10:45 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/11 14:40:19 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_smallest(t_massive *s)
{
	if(s->a->index < s->a->next->next->index)
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
	if(s->a->next->index < s->a->next->next->index)
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

void	small_sort(t_massive *s)
{
	if (s->size == 3)
	{
		
		if (s->a->index < s->a->next->index && s->a->next->index > s->a->next->next->index)
			first_smallest(s);
		else if (s->a->index > s->a->next->index)
			first_not_smallest(s);
	}
}
/*printf("s->a->index = %d", s->a->index);
			printf("s->a->next->index = %d", s->a->next->index);
			printf("s->a->next->next->index = %d", s->a->next->next->index);*/ //if (s->a->next->index < s->a->next->next->index)