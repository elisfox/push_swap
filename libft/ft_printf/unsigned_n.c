/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	unsigned_n_process(t_flags *t, va_list ap, const char *format)
{
	char	*s;
	int		zero;

	zero = 1;
	s = NULL;
	if (t->pointer)
		pointer_arg_start(t, ap);
	if (t->hh == 1)
		s = ft_itoa_unsigned((unsigned char)va_arg(ap, unsigned int));
	else if (t->l == 1 || format[t->step] == 'U' || t->z)
		s = ft_itoa_unsigned(va_arg(ap, unsigned long));
	else if (t->ll == 1 || t->j)
		s = ft_itoa_unsigned(va_arg(ap, unsigned long long));
	else if (t->h == 1)
		s = ft_itoa_unsigned((unsigned short)va_arg(ap, unsigned int));
	else
		s = ft_itoa_unsigned(va_arg(ap, unsigned int));
	if (ft_strcmp("0", s))
		zero = 0;
	int_output(s, t, format, zero);
}
