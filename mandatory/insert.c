/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:48:03 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 17:05:47 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "commands.h"

t_node	*find_cheapest(t_stack *stack);

void	insert(t_data *data)
{
	t_node	*to_move;
	t_node	*closest;

	to_move = find_cheapest(data->stack_b);
	rotate_to_top(to_move, data->stack_b, data);
	if (find_higher(data->stack_a)->nb < to_move->nb)
	{
		closest = find_lowest(data->stack_a);
	}
	else
		closest = closest_higher(to_move, data->stack_a);
	rotate_to_top(closest, data->stack_a, data);
	push_a(data);
}

void	rotate_to_top(t_node *node, t_stack *stack, t_data *data)
{
	if (find_index(node, stack) > stack_size(stack) / 2)
	{
		while (stack->first != node)
		{
			if (stack == data->stack_b)
				r_rotate_b(data);
			else
				r_rotate_a(data);
		}
	}
	else
	{
		while (stack->first != node)
		{
			if (stack == data->stack_b)
				rotate_b(data);
			else
				rotate_a(data);
		}
	}
}

t_node	*find_cheapest(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest;

	current = stack->first;
	cheapest = stack->first;
	while (current != NULL)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
