/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 12:58:39 by jojoseph          #+#    #+#             */
/*   Updated: 2020/06/11 20:25:25 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	b_space(char *string, int width, t_flags *t)
{
	int		i;
	char	c;

	if (t->minus)
		t->zero = 0;
	c = t->zero ? '0' : ' ';
	i = 0;
	while (width > 0)
	{
		string[i] = c;
		width--;
		i++;
	}
	string[i] = '\0';
}

char	*str_right_cpy(char *string, char *s, int precision)
{
	int i;
	int j;

	i = precision < ft_strlen(s) ? ft_strlen(string) - precision : \
	ft_strlen(string) - ft_strlen(s);
	j = 0;
	while (j < precision && string[i] && s[j])
		string[i++] = s[j++];
	return (string);
}

char	*str_left_cpy(char *string, char *s, int precision, t_flags *t)
{
	int i;

	i = 0;
	if (!t->dot)
	{
		while (i < precision && s[i])
		{
			string[i] = s[i];
			i++;
		}
	}
	return (string);
}
