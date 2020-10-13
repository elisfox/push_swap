/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		approximator(char *fract, long double nbr)
{
	int apr;
	int i;

	i = ft_strlen(fract);
	nbr *= 10;
	apr = (int)nbr;
	apr %= 10;
	if (apr >= 5)
		while (i)
		{
			if (fract[--i] != '9')
			{
				fract[i] += 1;
				return (0);
			}
			else
				fract[i] = '0';
		}
	else
		return (0);
	return (1);
}

static char		*ft_stradd(char *str, char ch)
{
	int		len;
	char	*new;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		if (!(new = (char*)ft_strnew(len + 1)))
			return (NULL);
		ft_strcat(new, str);
		ft_strdel(&str);
	}
	else
	{
		new = (char*)ft_strnew(1);
		if (new == NULL)
			return (NULL);
	}
	new[len] = ch;
	new[len + 1] = '\0';
	return (new);
}

char			*ft_ftoa_long(long double nbr, unsigned int precision)
{
	int			i;
	size_t		whole;
	char		fract[10000];
	int			sign;
	char		ch;

	ch = (precision) ? '.' : '\0';
	sign = (nbr < 0) ? -1 : 1;
	nbr = nbr * sign;
	whole = (size_t)nbr;
	nbr -= whole;
	i = 0;
	if (precision <= 10000)
		while (precision--)
		{
			nbr *= 10;
			fract[i++] = (size_t)nbr % 10 + '0';
			nbr -= (size_t)nbr;
		}
	fract[i] = '\0';
	whole += approximator(fract, nbr);
	return (sign < 0) ? ft_strjoin_f("-",\
	ft_strjoin_f(ft_stradd(ft_itoa_unsigned(whole), ch), fract,\
	1), 2) : ft_strjoin_f(ft_stradd(ft_itoa_unsigned(whole), ch), fract, 1);
}
