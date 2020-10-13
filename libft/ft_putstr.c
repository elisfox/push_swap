/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:02:55 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 17:39:37 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int index;

	if (!s)
		return ;
	index = 0;
	while (s[index] != '\0')
	{
		ft_putchar(s[index]);
		index++;
	}
}
