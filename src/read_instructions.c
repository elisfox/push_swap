/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:58:53 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/11 15:00:39 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		make_instr(t_massive *s, t_instr *instr)
{
	if (instr->comm == SA)
		swap_a_b(s->a);
	else if (instr->comm == SB)
		swap_a_b(s->b);
	else if (instr->comm == SS)
		swap_ss(s->a, s->b);
	else if (instr->comm == PA)
		push_a(s);
	else if (instr->comm == PB)
		push_b(s);
	else if (instr->comm == RA)
		s->a = rotate_a_b(s->a);
	else if (instr->comm == RB)
		s->b = rotate_a_b(s->b);
	else if (instr->comm == RR)
		rr(s);
	else if (instr->comm == RRA)
		s->a = rr_a_b(s->a);
	else if (instr->comm == RRB)
		s->b = rr_a_b(s->b);
	else if (instr->comm == RRR)
		rrr(s);
}

static int	check_instr(char *line, t_instr *instr)
{
	if (!ft_strcmp(line, "sa"))
		instr->comm = SA;
	else if (!ft_strcmp(line, "sb"))
		instr->comm = SB;
	else if (!ft_strcmp(line, "ss"))
		instr->comm = SS;
	else if (!ft_strcmp(line, "pa"))
		instr->comm = PA;
	else if (!ft_strcmp(line, "pb"))
		instr->comm = PB;
	else if (!ft_strcmp(line, "ra"))
		instr->comm = RA;
	else if (!ft_strcmp(line, "rb"))
		instr->comm = RB;
	else if (!ft_strcmp(line, "rr"))
		instr->comm = RR;
	else if (!ft_strcmp(line, "rra"))
		instr->comm = RRA;
	else if (!ft_strcmp(line, "rrb"))
		instr->comm = RRB;
	else if (!ft_strcmp(line, "rrr"))
		instr->comm = RRR;
	else
		return (0);
	return (1);
}

void		check_sort_stacks(t_massive *s)
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
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

void		read_instructions(t_massive *s)
{
	char	*line;
	t_instr	*instr;
	size_t	fd;

	if (!(instr = (t_instr *)ft_memalloc(sizeof(t_instr))))
		exit_error();
	fd = 0;
	if (s->size == 1)
	{
		ft_printf("OK\n");
		return ;
	}
	while (get_next_line(fd, &line) == 1)
	{
		if (!check_instr(line, instr))
		{
			free(line);
			exit_error();
		}
		make_instr(s, instr);
		free(line);
	}
	check_sort_stacks(s);
}
