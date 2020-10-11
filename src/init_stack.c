/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:10:45 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/11 14:40:19 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valid_args(t_massive *s, int ac, char **av)
{
	char ***args;

	check_numbers(ac, av);
	args = extract_numbers(ac, av);
	s->size = count_numbers(args);
	s->tab = create_array(s->size, args);
	check_doubles(s->tab, s->size);
}

t_stack	*add_elem(t_stack *first, int i)
{
	t_stack *new;

	if (!(new = (t_stack *)ft_memalloc(sizeof(t_stack))))
		exit_error();
	first->next = new;
	new->val = i;
	new->prev = first;
	return (new);
}

void	get_index(t_stack *a, int *new_tab)
{
	int j;

	j = 0;
	while (a != NULL)
	{
		j = 0;
		while (a->val != new_tab[j])
			j++;
		a->index = j + 1;
		a = a->next;
	}
}

void	init_stack_a(t_massive *s, char **av, int ac)
{
	t_stack	*head;
	int		i;
	int		*new_tab;

	i = 0;
	valid_args(s, ac, av);
	if (!(s->a = (t_stack *)ft_memalloc(sizeof(t_stack))))
		exit_error();
	head = s->a;
	s->a->prev = NULL;
	s->a->val = s->tab[i++];
	while (i < s->size)
		s->a = add_elem(s->a, s->tab[i++]);
	s->a->next = NULL;
	new_tab = sort_tab(s->tab, s->size);
	s->a = head;
	get_index(s->a, new_tab);
}
