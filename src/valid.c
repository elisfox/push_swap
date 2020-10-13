/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:10:45 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/11 14:40:19 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				exit_error();
			j++;
		}
		i++;
	}
}

void	check_numbers(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (ft_isspace(av[i][j]))
				j++;
			if ((av[i][j] == '-' || av[i][j] == '+' || av[i][j] == ' ') && \
			ft_isdigit(av[i][j + 1]))
				j++;
			if (!ft_isdigit(av[i][j]) && av[i][j] != '\0')
				exit_error();
			while (ft_isdigit(av[i][j]))
				j++;
			if (!ft_isspace(av[i][j]) && av[i][j] != '\0')
				exit_error();
		}
		i++;
	}
}

int		*create_array(int count, char ***args)
{
	int *tab;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(tab = (int *)malloc(sizeof(int) * count)))
		return (NULL);
	count = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			tab[count] = (int)(ft_atoi_ps(args[i][j], 1));
			j++;
			count++;
		}
		i++;
	}
	return (tab);
}

char	***extract_numbers(int ac, char **av)
{
	char	***args;
	int		i;
	int		j;

	i = 1;
	j = 0;
	args = (char ***)malloc(sizeof(char **) * (ac));
	while (i < ac)
		args[j++] = ft_strsplit(av[i++], ' ');
	args[j] = NULL;
	return (args);
}

int		count_numbers(char ***args)
{
	int count;
	int i;
	int j;

	count = 0;
	i = 0;
	j = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j++])
			count++;
		i++;
	}
	return (count);
}
