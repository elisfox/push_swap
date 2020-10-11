/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:02:14 by jojoseph          #+#    #+#             */
/*   Updated: 2020/10/11 15:06:07 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest(int *arr, int size)
{
	int i;
	int smallest;
	int smallest_index;

	i = 0;
	smallest = arr[0];
	smallest_index = 0;
	while (i < size)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

int			*sort_tab(int *arr, int size)
{
	int i;
	int *new_arr;
	int smallest;

	i = 0;
	new_arr = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		smallest = find_smallest(arr, size);
		new_arr[i] = arr[smallest];
		arr[smallest] = 999999;
		i++;
	}
	return (new_arr);
}
