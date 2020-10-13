/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:58:04 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 21:20:57 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;
	int len1;
	int len2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
			i++;
		s1++;
		s2++;
	}
	if (len1 == i && len2 == i)
		return (1);
	return (0);
}
