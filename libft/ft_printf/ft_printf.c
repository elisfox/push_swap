/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	format_step(va_list ap, const char *f, t_flags *t)
{
	while (f[t->step] != '\0')
	{
		if (f[t->step] != '%' && f[t->step])
			text(f, t);
		else if (f[t->step] == '%' && ft_strchr(ALLSYMBOLS, f[t->step + 1]))
		{
			t->step++;
			analysis(f, t, ap);
			reset_struct(t);
		}
		if (f[t->step] == '\0')
			return ;
		t->step++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_flags	*t;
	va_list	ap;
	int		result;

	result = 0;
	if (!(t = (t_flags *)malloc(sizeof(t_flags))))
		return (result);
	bzero_struct(t);
	va_start(ap, format);
	va_copy(t->copy, ap);
	format_step(ap, format, t);
	va_end(ap);
	result = t->pf_return;
	free(t);
	return (result);
}
