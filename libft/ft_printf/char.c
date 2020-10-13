/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	str_width(char *s, t_flags *t, char c, int width)
{
	if (t->width && t->width > t->prec && t->width >= ft_strlen(s))
		width = t->width;
	else if (t->width && t->width > t->prec && \
	t->width < ft_strlen(s) && t->prec >= 0)
		width = t->width;
	else if (t->width && t->width > t->prec && \
	t->width < ft_strlen(s) && t->prec == -1)
		width = ft_strlen(s);
	else if (t->width && t->width <= t->prec && \
	t->width > ft_strlen(s))
		width = t->width;
	else if (c != 'c')
		width = t->prec < ft_strlen(s) ? t->prec : ft_strlen(s);
	else
		width = ft_strlen(s);
	return (width);
}

static char	*str_prog(char *s, t_flags *t, char *string, char c)
{
	int width;
	int precision;

	width = 0;
	width = str_width(s, t, c, width);
	precision = t->prec > -1 ? t->prec : 9999;
	if (c == 'c')
		precision++;
	if (!(string = ft_strnew(width + 1)))
		exit(0);
	b_space(string, width, t);
	if (t->minus)
		string = str_left_cpy(string, s, precision, t);
	else
		string = str_right_cpy(string, s, precision);
	return (string);
}

static void	ft_string(t_flags *t, char *s, int f, char c)
{
	char *string;

	string = NULL;
	if (!t->width && t->prec == -1 && !t->dot)
		string = ft_strdup(s);
	else
		string = str_prog(s, t, string, c);
	if (t->char_null == 1)
	{
		t->pf_return += ft_strlen(string);
		put_null_char(string);
	}
	else
	{
		ft_putstr(string);
		t->pf_return += ft_strlen(string);
	}
	if (f)
		free(s);
	free(string);
}

static char	*if_char(va_list ap, t_flags *t, char *s)
{
	char a;

	a = (char)va_arg(ap, int);
	if (a == '\0')
	{
		s = ft_strdup("%");
		t->char_null = 1;
	}
	else
	{
		s = ft_strdup(" ");
		s[0] = a;
	}
	return (s);
}

void		char_or_string(t_flags *t, va_list ap, const char *format, char c)
{
	char	*s;
	int		free;

	free = 1;
	s = NULL;
	if (t->pointer)
		pointer_arg_start(t, ap);
	if (format[t->step] == '%')
	{
		s = ft_strdup("%");
		c = 'c';
	}
	else if (c == 'c')
		s = if_char(ap, t, s);
	else if (!(s = (char*)va_arg(ap, char*)))
		s = ft_strdup("(null)");
	else
		free = 0;
	ft_string(t, s, free, c);
}
