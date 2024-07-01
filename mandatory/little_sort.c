/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:48:06 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 17:05:40 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "commands.h"

void	sort_2(t_data *data)
{
	t_node	*node;

	node = data->stack_a->first;
	if (node == NULL || node->next == NULL)
	{
		return ;
	}
	if (is_sorted(data) == false)
		swap_a(data);
}

void	sort_3(t_data *data)
{
	t_node	*lowest;
	t_node	*higher;
	int		lowest_index;
	int		higher_index;

	lowest = find_lowest(data->stack_a);
	higher = find_higher(data->stack_a);
	higher_index = find_index(higher, data->stack_a);
	if (higher_index == 0)
		rotate_a(data);
	else if (higher_index == 1)
		r_rotate_a(data);
	lowest_index = find_index(lowest, data->stack_a);
	if (lowest_index == 1)
		swap_a(data);
}
