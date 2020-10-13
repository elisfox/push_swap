/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	conversions(const char *f, t_flags *t, va_list ap)
{
	if (f[t->step] == 'd' || f[t->step] == 'i' || f[t->step] == 'D')
		int_processing(t, ap, f);
	if (f[t->step] == 'c' || f[t->step] == 'C')
		char_or_string(t, ap, f, 'c');
	if (f[t->step] == 's' || f[t->step] == '%')
		char_or_string(t, ap, f, 's');
	if (f[t->step] == 'S')
		char_or_string(t, ap, f, 'S');
	if (f[t->step] == 'u' || f[t->step] == 'U')
		unsigned_n_process(t, ap, f);
	if (f[t->step] == 'f' || f[t->step] == 'F')
		f_process(t, ap, f);
	if (f[t->step] == 'o')
		oxb_processing(t, ap, 8, f);
	if (f[t->step] == 'b')
		oxb_processing(t, ap, 2, f);
	if (f[t->step] == 'x' || f[t->step] == 'X')
		oxb_processing(t, ap, 16, f);
	if (f[t->step] == 'p')
		p_processing(t, ap, 16, f);
	if (f[t->step] == 'k')
		iso_output(ap, t);
}

static void	modifers2(const char *f, t_flags *t, va_list ap)
{
	if (f[t->step] == '.' && !ft_strchr(NUMBERS, f[t->step + 1]))
		t->prec++;
	else if (f[t->step] == ' ')
		t->space++;
	else if (f[t->step] == '*')
		star_bonus(f, t, ap);
	else if (f[t->step] == 'j')
		t->j++;
	else if (f[t->step] == 'z')
		t->z++;
	else
		t->hash++;
	t->step++;
}

static void	modifers(const char *f, t_flags *t, va_list ap)
{
	while (!ft_strchr(TYPE, f[t->step]) && f[t->step])
	{
		if (ft_strchr(NUMBERS, f[t->step]))
			numbers(f, t);
		else if (f[t->step] == 'h' || f[t->step] == 'l' || f[t->step] == 'L')
			len_analysis(f, t);
		else if (f[t->step] == '+' || f[t->step] == '-')
			plus_minus(f, t);
		else if (f[t->step] == '.' && ft_strchr(NUMBERS, f[t->step + 1]))
			t->step++;
		else if ((f[t->step] == '.' && !ft_strchr(NUMBERS, f[t->step + 1])) \
		|| f[t->step] == ' ' || f[t->step] == '#' || f[t->step] == '*' || \
		f[t->step] == 'j' || f[t->step] == 'z')
			modifers2(f, t, ap);
		else if (f[t->step] == '$')
			t->step++;
		else
			in_persent_text(f, t, ap);
	}
}

void		analysis(const char *f, t_flags *t, va_list ap)
{
	if (ft_strchr(FLAGS, f[t->step]))
		modifers(f, t, ap);
	if (ft_strchr(TYPE, f[t->step]))
		conversions(f, t, ap);
}
