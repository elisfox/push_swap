/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:39:46 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 19:37:17 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	size;

	if (*haystack == 0 && *needle == 0)
		return ((char *)haystack);
	size = ft_strlen(needle);
	while (*haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, size) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
