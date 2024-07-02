/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:55:41 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/02 07:18:19 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_lowest(t_stack *stack)
{
	t_node	*lowest;
	t_node	*current;

	lowest = stack->first;
	current = stack->first->next;
	while (current != NULL)
	{
		if (current->nb < lowest->nb)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

t_node	*find_higher(t_stack *stack)
{
	t_node	*higher;
	t_node	*current;

	higher = stack->first;
	current = stack->first->next;
	while (current != NULL)
	{
		if (current->nb > higher->nb)
			higher = current;
		current = current->next;
	}
	return (higher);
}

int	find_index(t_node *node, t_stack *stack)
{
	t_node	*current;
	int		i;

	current = stack->first;
	i = 0;
	while (current != NULL)
	{
		if (current == node)
			return (i);
		current = current->next;
		++i;
	}
	return (-1);
}

bool	is_sorted(t_data *data)
{
	t_node	*node;

	if (data->stack_b->first && data->stack_a->first)
		return (false);
	node = data->stack_a->first;
	if (node->next == NULL && data->stack_b->first == NULL)
		return (true);
	if (node->nb > node->next->nb)
		return (false);
	while (node->next)
	{
		if (node->nb > node->next->nb)
			return (false);
		node = node->next;
	}
	return (true);
}

int	stack_size(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 1;
	node = stack->first->next;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
