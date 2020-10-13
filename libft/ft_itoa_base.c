/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:26:13 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/16 18:26:43 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned int value, int base)
{
	char			*s;
	int				i;
	unsigned int	a;
	unsigned int	tmp;

	i = 1;
	a = (unsigned int)base;
	tmp = value;
	while ((tmp /= a) >= 1)
		i++;
	if (!(s = ft_strnew(i + 1)))
		return (NULL);
	s[i] = '\0';
	while (i--)
	{
		s[i] = (value % a < 10) ? value % a + '0' : value % a + 'a' - 10;
		value /= a;
	}
	return (s);
}

char	*ft_itoa_base_unsigned(size_t value, int base)
{
	char	*s;
	int		i;
	size_t	a;
	size_t	tmp;

	i = 1;
	a = (size_t)base;
	tmp = value;
	while ((tmp /= a) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	while (i--)
	{
		s[i] = (value % a < 10) ? value % a + '0' : value % a + 'a' - 10;
		value /= a;
	}
	return (s);
}
