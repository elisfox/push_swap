/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:28:51 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 17:32:07 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (NULL);
	s = (unsigned const char*)src;
	d = (unsigned char*)dest;
	while (n > 0)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dest);
}
