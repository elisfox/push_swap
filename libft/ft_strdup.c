/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:12:40 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 17:57:16 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*str;

	size = ft_strlen(s1);
	i = 0;
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
