/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:55:58 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/02 08:04:55 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*temp;

	temp = stack->first->next;
	stack->first->next = stack->first->next->next;
	temp->next = stack->first;
	stack->first = temp;
}

void	swap_a(t_data *data)
{
	if (data->stack_a->first == NULL || data->stack_a->first->next == NULL)
		return ;
	swap(data->stack_a);
	if (write(1, "sa\n", 3) == -1)
		free_and_exit(WRITE_FAILED, EXIT_FAILURE, data);
}

void	swap_b(t_data *data)
{
	if (data->stack_b->first == NULL || data->stack_b->first->next == NULL)
		return ;
	swap(data->stack_b);
	if (write(1, "sb\n", 3) == -1)
		free_and_exit(WRITE_FAILED, EXIT_FAILURE, data);
}

void	swap_ab(t_data *data)
{
	if (data->stack_b->first == NULL || data->stack_b->first->next == NULL)
		return ;
	if (data->stack_a->first == NULL || data->stack_a->first->next == NULL)
		return ;
	swap_a(data);
	swap_b(data);
	if (write(1, "ss\n", 3) == -1)
		free_and_exit(WRITE_FAILED, EXIT_FAILURE, data);
}
