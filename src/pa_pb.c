/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:50:59 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/11 14:51:49 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_massive *s)
{
	t_stack *tmp;

	tmp = s->a;
	if (tmp == NULL)
		return ;
	if (s->a->next)
	{
		s->a = s->a->next;
		s->a->prev = NULL;
	}
	else
		s->a = NULL;
	if (s->b == NULL)
	{
		s->b = tmp;
		s->b->prev = NULL;
		s->b->next = NULL;
	}
	else
	{
		tmp->next = s->b;
		s->b->prev = tmp;
		s->b = tmp;
	}
}

void	push_a(t_massive *s)
{
	t_stack *tmp;

	tmp = s->b;
	if (tmp == NULL)
		return ;
	if (s->b->next)
	{
		s->b = s->b->next;
		s->b->prev = NULL;
	}
	else
		s->b = NULL;
	if (s->a == NULL)
	{
		s->a = tmp;
		s->a->prev = NULL;
		s->a->next = NULL;
	}
	else
	{
		tmp->next = s->a;
		s->a->prev = tmp;
		s->a = tmp;
	}
}
