/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:43:22 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/24 17:27:48 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strssub(char const *s, size_t start, size_t len, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(len - start + 1);
	if (str == NULL)
		return (NULL);
	while (s[start] != '\0' && s[start] != c)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_create(char **array, const char *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			if ((array[j] = ft_strssub(s, i, ft_end_word(s, c, i), c)) == NULL)
			{
				ft_free_array((void *)array);
				return (NULL);
			}
			i = ft_end_word(s, c, i);
			j++;
		}
		i++;
	}
	array[j] = NULL;
	return (array);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	count_word;

	if (!s)
		return (NULL);
	count_word = ft_word_count(s, c);
	if ((array = (char**)malloc(sizeof(char*) * count_word + 1)) == NULL)
		return (NULL);
	ft_create(array, s, c);
	return (array);
}
