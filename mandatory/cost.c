/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:04:28 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/03 17:39:23 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cost(t_node *node, t_data *data);
int		calc_cost_to_up(t_node *node, t_stack *stack);
t_node	*closest_higher(t_node *node, t_stack *stack);

void	calc_all_cost(t_data *data)
{
	t_node	*node;

	node = data->stack_b->first;
	while (node != NULL)
	{
		node->cost = cost(node, data);
		node = node->next;
	}
}

int	cost(t_node *node, t_data *data)
{
	int	cost;

	cost = calc_cost_to_up(node, data->stack_b);
	if (find_higher(data->stack_a)->nb < node->nb)
		node->target = find_lowest(data->stack_a);
	else
		node->target = closest_higher(node, data->stack_a);
	cost += calc_cost_to_up(node->target, data->stack_a);
	++cost;
	return (cost);
}

int	calc_cost_to_up(t_node *node, t_stack *stack)
{
	t_node	*current;
	int		index;
	int		cost;

	cost = 0;
	current = node;
	index = find_index(node, stack);
	if (index > stack_size(stack) / 2)
	{
		while (current->next)
		{
			current = current->next;
			cost++;
		}
		cost++;
	}
	else
		cost = index;
	return (cost);
}

t_node	*closest_higher(t_node *node, t_stack *stack)
{
	int		temp;
	t_node	*current;
	t_node	*closest;

	current = stack->first;
	closest = stack->first;
	temp = INT_MAX;
	while (current != NULL)
	{
		if (node->nb < current->nb && current->nb < temp)
		{
			closest = current;
			temp = current->nb;
		}
		current = current->next;
	}
	return (closest);
}
