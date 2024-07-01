/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:09:33 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/29 05:10:59 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			partition(int array[], int start, int end);
void		quick_sort(int array[], int start, int end);
static void	swap(int *x, int *y);

void	sort_array(int array[], int lentgh)
{
	quick_sort(array, 0, lentgh - 1);
}

void	quick_sort(int array[], int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end);
		quick_sort(array, pivot_index + 1, end);
		quick_sort(array, start, pivot_index - 1);
	}
}

int	partition(int array[], int start, int end)
{
	int	i;
	int	j;
	int	pivot_value;

	i = start;
	j = start;
	pivot_value = array[end];
	while (j < end)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[j], &array[i]);
			i++;
		}
		j++;
	}
	swap(&array[i], &array[end]);
	return (i);
}

static void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
