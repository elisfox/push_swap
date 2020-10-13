/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:54:55 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/12 22:12:37 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_sorted(t_massive *s)
{
	int		flag_a;
	int		flag_b;
	t_stack	*tmp;
	t_stack	*tmp2;

	flag_a = 1;
	flag_b = 1;
	tmp = s->a;
	tmp2 = s->b;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			flag_a = 0;
		tmp = tmp->next;
	}
	if (tmp2)
		flag_b = 0;
	if (flag_a == 0 || flag_b == 0)
		return (0);
	else
		return (1);
}

void			new_sort(t_massive *s, int max_i)
{
	int size_chunk;
	int count;
	int i;

	i = 1;
	size_chunk = s->size;
	count = 0;
	if (s->size > 10)
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

int				main(int ac, char **av)
{
	t_massive	*s;
	int			max_i;

	if (!(s = (t_massive *)ft_memalloc(sizeof(t_massive))))
		exit_error();
	if (ac >= 2)
	{
		init_stack_a(s, av, ac);
		s->b = NULL;
		if (!check_sorted(s))
		{
			s->message = ft_strdup("");
			max_i = (s->size > 100 ? 11 : 5);
			if (s->size <= 10)
				small_sort(s);
			else
				new_sort(s, max_i);
			ft_printf("%s", s->message);
			free(s->message);
		}
		//delete_stack(s->a);
	}
	free(s);
}
