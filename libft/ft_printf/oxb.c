/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	f_process(t_flags *t, va_list ap, const char *format)
{
	char	*s;
	int		prec;
	int		zero;

	zero = 1;
	prec = t->prec == -1 ? 6 : t->prec;
	if (t->pointer)
		pointer_arg_start(t, ap);
	if (t->l_cap == 1)
		s = ft_ftoa_long(va_arg(ap, long double), prec);
	else
		s = ft_ftoa((double)va_arg(ap, double), prec);
	if (t->hash && !t->prec)
		s = ft_strjoin(s, ".");
	if (ft_strcmp("0", s))
		zero = 0;
	if (s != NULL)
		int_output(s, t, format, zero);
}

void	oxb_processing(t_flags *t, va_list ap, int base, const char *format)
{
	char	*s;
	int		zero;

	zero = 1;
	s = NULL;
	if (t->pointer)
		pointer_arg_start(t, ap);
	if (t->h == 1)
		s = ft_itoa_base((unsigned short)va_arg(ap, int), base);
	else if (t->hh == 1)
		s = ft_itoa_base((unsigned char)va_arg(ap, int), base);
	else if (t->l == 1)
		s = ft_itoa_base_unsigned(va_arg(ap, unsigned long), base);
	else if (t->ll == 1 || t->j)
		s = ft_itoa_base_unsigned(va_arg(ap, unsigned long long), base);
	else
		s = ft_itoa_base(va_arg(ap, unsigned int), base);
	if (ft_strcmp("0", s))
		zero = 0;
	int_output(s, t, format, zero);
}

void	p_processing(t_flags *t, va_list ap, int base, const char *format)
{
	char	*s;
	int		zero;

	zero = 1;
	s = NULL;
	if (t->pointer)
		pointer_arg_start(t, ap);
	s = ft_itoa_base_unsigned(va_arg(ap, size_t), base);
	if (ft_strcmp("0", s))
		zero = 0;
	int_output(s, t, format, zero);
}

void	int_processing(t_flags *t, va_list ap, const char *format)
{
	char	*s;
	int		zero;

	zero = 1;
	s = NULL;
	if (t->pointer)
		pointer_arg_start(t, ap);
	if (t->l == 1 || t->z)
		s = ft_itoa_long(va_arg(ap, long));
	else if (t->ll == 1 || t->j || format[t->step] == 'D')
		s = ft_itoa_longlong(va_arg(ap, long long));
	else if (t->h == 1)
		s = ft_itoa((short)va_arg(ap, int));
	else if (t->hh == 1)
		s = ft_itoa((signed char)va_arg(ap, int));
	else
		s = ft_itoa(va_arg(ap, int));
	if (ft_strcmp("0", s))
		zero = 0;
	int_output(s, t, format, zero);
}
