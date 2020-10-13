/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:52:59 by jojoseph          #+#    #+#             */
/*   Updated: 2019/09/11 19:44:29 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		n;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	n = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	if (i == ft_strlen(s))
		return (ft_strnew(0));
	str = ft_strnew(j - i + 1);
	if (str == NULL)
		return (NULL);
	while (i <= j)
		str[n++] = s[i++];
	str[n] = '\0';
	return (str);
}
