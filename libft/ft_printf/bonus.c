/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	iso_output(va_list ap, t_flags *t)
{
	int		data;
	char	*dd;
	char	*mm;
	char	*yy;

	data = va_arg(ap, int);
	dd = ft_itoa(data % 100);
	if (ft_strlen(dd) == 1)
		dd = ft_strjoin_f("0", dd, 2);
	data /= 100;
	mm = ft_itoa(data % 100);
	if (ft_strlen(mm) == 1)
		mm = ft_strjoin_f("0", mm, 2);
	data /= 100;
	yy = ft_itoa(data);
	yy = ft_strjoin_f(yy, "-", 1);
	yy = ft_strjoin_f(yy, mm, 3);
	yy = ft_strjoin_f(yy, "-", 1);
	yy = ft_strjoin_f(yy, dd, 3);
	ft_putstr(yy);
	t->pf_return += ft_strlen(yy);
	free(yy);
}

void	star_bonus(const char *format, t_flags *t, va_list ap)
{
	int num;
	int dot;
	int neg;

	dot = (format[t->step - 1] == '.') ? 1 : 0;
	num = va_arg(ap, int);
	neg = num < 0 ? -1 : 1;
	if (dot)
	{
		if (neg < 0)
			t->prec = -1;
		else
			t->prec = num;
	}
	else
	{
		if (neg < 0)
			t->minus = 1;
		t->width = num * neg;
	}
}

void	pointer_arg_start(t_flags *t, va_list ap)
{
	int i;

	i = 0;
	va_copy(ap, t->copy);
	va_end(t->copy);
	while (i++ < t->pointer - 1)
		va_arg(ap, int);
}
