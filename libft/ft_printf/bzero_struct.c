/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convertion(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = ft_toupper(s[i]);
		i++;
	}
}

void	bzero_struct(t_flags *t)
{
	t->char_null = 0;
	t->pf_return = 0;
	t->negative = 0;
	t->step = 0;
	t->ll = 0;
	t->width = 0;
	t->prec = -1;
	t->plus = 0;
	t->minus = 0;
	t->zero = 0;
	t->space = 0;
	t->hash = 0;
	t->l = 0;
	t->j = 0;
	t->h = 0;
	t->hh = 0;
	t->l_cap = 0;
	t->dot = 0;
	t->z = 0;
	t->pointer = 0;
}

void	reset_struct(t_flags *t)
{
	t->char_null = 0;
	t->ll = 0;
	t->width = 0;
	t->prec = -1;
	t->negative = 0;
	t->plus = 0;
	t->minus = 0;
	t->zero = 0;
	t->space = 0;
	t->hash = 0;
	t->l = 0;
	t->j = 0;
	t->h = 0;
	t->z = 0;
	t->hh = 0;
	t->l_cap = 0;
	t->dot = 0;
	t->pointer = 0;
}
