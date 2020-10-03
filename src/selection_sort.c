#include "push_swap.h"

static int find_smallest(int *arr, int size)
{
    int i;

    i = 0;
	int smallest = arr[0];
	int smallest_index = 0;
	while(i < size)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			smallest_index = i;
		}
        i++;
	}
	return smallest_index;
}

int *sort_tab(int *arr, int size)
{
    int i;

    i = 0;
	int *new_arr = (int *)malloc(size * sizeof(int));
	while(i < size)
	{
		int smallest = find_smallest(arr, size);
		new_arr[i] = arr[smallest];
		arr[smallest] = 999999;
        i++;
	}
	return new_arr;
}