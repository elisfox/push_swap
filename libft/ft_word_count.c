/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:26:00 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/17 11:51:28 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(char const *s, char c)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i - 1] == c) || (s[i] != c && (int)i - 1 == -1))
			count++;
		i++;
	}
	return (count);
}
