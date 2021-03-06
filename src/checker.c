/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:15:09 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/10 21:15:42 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean(t_stack *a, t_stack *b)
{
	delete_stack(a);
	delete_stack(b);
}

int			main(int ac, char **av)
{
	t_massive *s;

	if (!(s = (t_massive *)ft_memalloc(sizeof(t_massive))))
		exit_error();
	if (ac >= 2)
	{
		init_stack_a(s, av, ac);
		s->b = NULL;
		read_instructions(s);
		clean(s->a, s->b);
	}
	free(s);
	return (0);
}
