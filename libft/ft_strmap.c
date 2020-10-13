/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:27:24 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 18:31:20 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*array;

	i = 0;
	if (!s || !f)
		return (NULL);
	array = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!array)
		return (NULL);
	while (s[i] != '\0')
	{
		array[i] = (*f)(s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
