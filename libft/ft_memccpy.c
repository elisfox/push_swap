/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:32:26 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 15:29:15 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *s;
	unsigned char *d;
	unsigned char chr;

	chr = (unsigned char)c;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n > 0)
	{
		*d = *s;
		s++;
		d++;
		n--;
		if (*(d - 1) == chr)
			return (d);
	}
	return (NULL);
}
