/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:38:21 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 18:41:14 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, int n)
{
	int i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if ((ft_strlen(s1) == 0 && ft_strlen(s2) == 0) || n == 0)
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0' && n > i)
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	if ((ft_strlen(s1) == i && ft_strlen(s2) == i) || n == i)
		return (1);
	return (0);
}
