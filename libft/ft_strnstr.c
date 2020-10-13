/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:44:48 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 18:47:30 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(needle);
	if (haystack == needle || size == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (i <= len && *haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, size) == 0 && i + size <= len)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
