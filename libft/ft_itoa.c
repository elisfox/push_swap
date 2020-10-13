/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:25:33 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 17:25:48 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n)
{
	int i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	while (n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char		*ft_strnbr(int n, char *str, int size)
{
	int	i;
	int	t;

	i = size;
	i--;
	if (n == -2147483648)
	{
		t = n % 10 * -1;
		str[i] = t + '0';
		n = n / 10;
		i--;
	}
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		t = n % 10;
		str[i] = t + '0';
		n = n / 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = ft_size(n);
	if (n < 0)
		size += 1;
	str = ft_strnew(size);
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	ft_strnbr(n, str, size);
	return (str);
}
