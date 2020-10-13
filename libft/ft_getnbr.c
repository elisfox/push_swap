/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:39:20 by jojoseph          #+#    #+#             */
/*   Updated: 2019/11/11 15:40:21 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getnbr(char *s)
{
	int neg;
	int result;
	int i;

	neg = 1;
	result = 0;
	i = 0;
	while (!ft_isdigit((int)s[i]) && s[i] != '-')
		i++;
	if (s[i++] == '-')
		neg *= -1;
	while (ft_isdigit((int)s[i]))
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	result *= neg;
	return (result);
}
