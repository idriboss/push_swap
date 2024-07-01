/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:48:00 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 16:48:01 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_nodes(t_data *t_data);

void	init_stacks(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (stack_a == NULL || stack_b == NULL)
	{
		free(stack_a);
		free(stack_b);
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	}
	data->stack_a = stack_a;
	data->stack_b = stack_b;
	stack_b->first = NULL;
	stack_a->first = malloc(sizeof(t_node));
	if (stack_a->first == NULL)
	{
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	}
	init_nodes(data);
}

static void	init_nodes(t_data *data)
{
	int		i;
	t_node	*node;

	i = 0;
	node = data->stack_a->first;
	node->nb = data->input[i++];
	while (i < data->input_count)
	{
		node->next = malloc(sizeof(t_node));
		if (node->next == NULL)
			free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
		node = node->next;
		node->nb = data->input[i];
		++i;
	}
	node->next = NULL;
}
