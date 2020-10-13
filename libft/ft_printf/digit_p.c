/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	b_zero_int(char *string, char *s, t_flags *t, const char *f)
{
	int k;
	int i;

	i = 0;
	if (f[t->step] == 'f')
	{
		k = t->width - ft_strlen(s);
		if (t->negative || t->plus || t->space)
			k--;
	}
	else
		k = t->prec - ft_strlen(s);
	while (k > 0)
	{
		string[i++] = '0';
		k--;
	}
	string[i] = '\0';
}

static char	*common_int(char *string, char *s, t_flags *t, const char *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (string[i] == '0')
		i++;
	while (s[j])
		string[i++] = s[j++];
	string[i] = '\0';
	if (t->width > ft_strlen(s) && t->prec == -1 && !t->minus && t->zero)
		return (string);
	if (t->negative)
		string = ft_strjoin_f("-", string, 2);
	else if (t->plus && !t->negative && f[t->step] != 'u')
		string = ft_strjoin_f("+", string, 2);
	else if (t->space && f[t->step] != 'u')
		string = ft_strjoin_f(" ", string, 2);
	return (string);
}

static char	*hash_p(char *s, t_flags *t, const char *f, int zero)
{
	char *tmp;

	if ((f[t->step] == 'o' || f[t->step] == 'b') && \
	(t->prec > ft_strlen(s) || s[0] == '0'))
		return (s);
	if ((f[t->step] == 'x' || f[t->step] == 'X') && \
	(t->prec > ft_strlen(s)))
	{
		if (!(tmp = ft_strnew(t->prec - ft_strlen(s) + 1)))
			exit(-1);
		b_zero_int(tmp, s, t, f);
		s = ft_strjoin_f(tmp, s, 3);
	}
	if ((zero && f[t->step] != 'p') || \
	(f[t->step] == 'p' && t->prec > ft_strlen(s)))
		return (s);
	if (zero && f[t->step] == 'p' && !t->prec)
		s[0] = '\0';
	if (f[t->step] == 'x' || f[t->step] == 'p' || f[t->step] == 'X')
		return (ft_strjoin_f("0x", s, 2));
	return (ft_strjoin_f("0", s, 2));
}

static void	int_output2(char *s, t_flags *t, const char *f, int zero)
{
	int		width;
	char	*string;

	if (f[t->step] == 'X')
		convertion(s);
	if (zero && f[t->step] != 'f' && t->prec == 0 &&\
	(f[t->step] != 'o' || (f[t->step] == 'o' && !t->hash)) && f[t->step] != 'p')
		s = ft_strdup("");
	width = max(t->width, t->prec, ft_strlen(s));
	if (!(string = ft_strnew(width + 1)))
		exit(-1);
	t->negative = if_minus(s);
	if ((t->prec > ft_strlen(s)) || (f[t->step] == 'f' && t->zero && !t->minus))
		b_zero_int(string, s, t, f);
	if (t->width != max(t->width, t->prec, ft_strlen(s)))
		string = common_int(string, s, t, f);
	else if (t->width == max(t->width, t->prec, ft_strlen(s)))
	{
		string = common_int(string, s, t, f);
		if (!(f[t->step] == 'f' && t->zero && !t->minus))
			string = b_space_int(string, s, width, t);
	}
	if (f[t->step] == 'p' && t->prec > ft_strlen(s))
		string = ft_strjoin_f("0x", string, 2);
	int_output3(s, t, string);
}

void		int_output(char *s, t_flags *t, const char *f, int zero)
{
	int x_hash;

	x_hash = 0;
	if (t->zero && t->hash && (f[t->step] == 'x' || \
	f[t->step] == 'X') && t->prec == -1 && !zero)
	{
		t->prec = t->width - 2;
		t->width = 0;
	}
	if ((f[t->step] == 'x' || f[t->step] == 'X') && \
	(t->prec > ft_strlen(s)) && t->hash && \
	(t->width < t->prec) && !zero)
		x_hash++;
	if (((t->hash && !zero) || f[t->step] == 'p') && f[t->step] != 'f')
		s = hash_p(s, t, f, zero);
	if (x_hash)
	{
		if (f[t->step] == 'X')
			convertion(s);
		ft_putstr(s);
		t->pf_return += ft_strlen(s);
		free(s);
	}
	else
		int_output2(s, t, f, zero);
}
