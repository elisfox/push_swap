/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:27:10 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 17:30:05 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*array;

	array = (void*)malloc(sizeof(void) * size);
	if (!array)
		return (NULL);
	ft_bzero(array, size);
	return (array);
}
