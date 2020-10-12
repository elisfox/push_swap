/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:16:02 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/11 14:50:26 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		first_smallest(t_massive *s)
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

void		first_not_smallest(t_massive *s)
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

void		print_stack(t_stack *a, t_stack *b)
{
	ft_printf("_   _\na   b\n");
	while (a || b)
	{
		if (a)
		{
			printf("%d", a->index);
			a = a->next;
		}
		else
			printf("#");
		printf("   ");
		if (b)
		{
			printf("%d", b->index);
			b = b->next;
		}
		else
			printf("#");
		printf("\n");
	}
}

void		exit_error(void)
{
	ft_printf("%s\n", "Error");
	exit(1);
}

long long	ft_atoi_ps(const char *str)
{
	int			nv;
	long long	nb;

	nb = 0;
	nv = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			nv *= -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		if (nb * 10 + (*str - 48) < nb)
			return (nv < 0 ? 0 : -1);
		nb = nb * 10 + (*str - 48);
		str++;
	}
	nb *= nv;
	if (nb > INT32_MAX || nb < INT32_MIN)
		exit_error();
	return (nb);
}
