/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:54:55 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/11 15:48:27 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_massive	*s;
	int			max_i;

	if (!(s = (t_massive *)ft_memalloc(sizeof(t_massive))))
		exit_error();
	if (ac >= 2)
	{
		init_stack_a(s, av, ac);
		s->b = NULL;
		s->message = ft_strdup("");
		max_i = (s->size > 100 ? 11 : 5);
		new_sort(s, max_i);
		ft_printf("%s", s->message);
		free(s->message);
	}
	free(s);
}
