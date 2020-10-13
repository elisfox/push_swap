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

void		plus_minus(const char *format, t_flags *t)
{
	if (format[t->step] == '+')
	{
		t->plus = 1;
		t->step++;
	}
	else
	{
		t->minus = 1;
		t->step++;
	}
}

void		numbers(const char *format, t_flags *t)
{
	int num;
	int dot;
	int pointer;

	pointer = (format[t->step + 1] == '$') ? 1 : 0;
	dot = (format[t->step - 1] == '.') ? 1 : 0;
	if ((format[t->step] == '0' && ft_strchr(NUMBERS, format[t->step + 1])) ||\
	(format[t->step] == '0' && ft_strchr("*+-", format[t->step + 1])))
	{
		if (!t->minus)
			t->zero++;
		t->step++;
	}
	num = ft_atoi(&format[t->step]);
	while (ft_strchr(NUMBERS, format[t->step]) && format[t->step])
		t->step++;
	if (pointer)
		t->pointer = num;
	else if (dot)
		t->prec = num;
	else
		t->width = num;
}

static void	l_cap(const char *s, t_flags *t)
{
	if (s[t->step] == 'L')
	{
		t->l_cap = 1;
		t->step++;
	}
}

void		len_analysis(const char *s, t_flags *t)
{
	if (s[t->step] == 'h')
	{
		t->step++;
		if (s[t->step] == 'h')
		{
			t->hh = 1;
			t->step++;
		}
		else
			t->h = 1;
	}
	else if (s[t->step] == 'l')
	{
		t->step++;
		if (s[t->step] == 'l')
		{
			t->ll = 1;
			t->step++;
		}
		else
			t->l = 1;
	}
	l_cap(s, t);
}
