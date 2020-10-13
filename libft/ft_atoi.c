/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			nv;
	int			nb;
	int			i;

	i = 0;
	nb = 0;
	nv = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nv *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if (nb * 10 + (str[i] - 48) < nb)
			return (nv < 0 ? 0 : -1);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb *= nv;
	return (nb);
}
