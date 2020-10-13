/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:02:49 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/16 19:03:03 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	s = (char *)src;
	d = (char *)dst;
	if (s < d)
		while ((int)(--len) >= 0)
			*(d + len) = *(s + len);
	else
		while (++i < len)
			*(d + i) = *(s + i);
	return (dst);
}
