/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	in_persent_text(const char *f, t_flags *t, va_list ap)
{
	while (f[t->step])
	{
		if (ft_strchr(ALLSYMBOLS, f[t->step]))
		{
			format_step(ap, f, t);
			break ;
		}
		ft_putchar(f[t->step]);
		t->pf_return++;
		t->step++;
	}
}

void	int_output3(char *s, t_flags *t, char *string)
{
	ft_putstr(string);
	t->pf_return += ft_strlen(string);
	free(string);
	free(s);
}

void	put_null_char(char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			string[i] = 0000;
		}
		write(1, &string[i], 1);
		i++;
	}
}

void	text(const char *format, t_flags *t)
{
	ft_putchar(format[t->step]);
	t->pf_return++;
}
