/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:31:46 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 18:33:49 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*array;

	i = 0;
	if (!s)
		return (NULL);
	array = ft_strnew(ft_strlen(s));
	if (!array)
		return (NULL);
	while (s[i] != '\0')
	{
		array[i] = (*f)(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
