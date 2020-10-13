/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_p2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/10 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			max(int a, int b, int c)
{
	int k;

	k = a > b ? a : b;
	if (k > c)
		return (k);
	else
		return (c);
	return (0);
}

int			if_minus(char *s)
{
	int minus;
	int i;

	i = 0;
	if (s[i] == '-')
	{
		minus = 1;
		i++;
		while (s[i])
		{
			s[i - 1] = s[i];
			i++;
		}
		s[i - 1] = '\0';
	}
	else
		minus = 0;
	return (minus);
}

static void	b_space_int2(char *tmp, int size, int i)
{
	i = 0;
	while (i < size)
		tmp[i++] = '0';
	tmp[i] = '\0';
}

static char	*b_space_int3(char *string, char *s, t_flags *t, char *tmp)
{
	int i;

	i = 0;
	if (!t->minus)
		string = ft_strjoin_f(tmp, string, 3);
	if (t->width > ft_strlen(s) && t->prec == -1 && !t->minus && t->zero)
	{
		if (t->negative)
			string = ft_strjoin_f("-", string, 2);
		else if (t->plus && !t->negative)
			string = ft_strjoin_f("+", string, 2);
		else if (t->space)
			string = ft_strjoin_f(" ", string, 2);
	}
	return (string);
}

char		*b_space_int(char *string, char *s, int width, t_flags *t)
{
	int		i;
	int		size;
	char	*tmp;

	i = 0;
	size = width - max(t->prec, ft_strlen(s), 0);
	if (t->negative || t->plus || t->space)
		size--;
	if (!(tmp = ft_strnew(size + 1)))
		exit(-1);
	while (i < size)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	if (t->minus)
		string = ft_strjoin_f(string, tmp, 3);
	else
	{
		if ((t->zero && t->prec > ft_strlen(s) && t->width != \
		max(t->width, t->prec, ft_strlen(s))) || \
		(t->zero && t->prec == -1 && t->width > ft_strlen(s)))
			b_space_int2(tmp, size, i);
		string = b_space_int3(string, s, t, tmp);
	}
	return (string);
}
