/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:55:33 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 16:55:34 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*last;

	if (stack->first == NULL || stack->first->next == NULL)
	{
		printf("rotate failed\n");
		return ;
	}
	last = stack->first;
	while (last->next != NULL)
		last = last->next;
	last->next = stack->first;
	stack->first = stack->first->next;
	last->next->next = NULL;
}

void	rotate_a(t_data *data)
{
	if (data->stack_a->first == NULL || data->stack_a->first->next == NULL)
		return ;
	rotate(data->stack_a);
	if (write(1, "ra\n", 3) == -1)
		free_and_exit(WRITE_FAILED, EXIT_FAILURE, data);
}

void	rotate_b(t_data *data)
{
	if (data->stack_b->first == NULL || data->stack_b->first->next == NULL)
		return ;
	rotate(data->stack_b);
	if (write(1, "rb\n", 3) == -1)
		free_and_exit(WRITE_FAILED, EXIT_FAILURE, data);
}

void	rotate_ab(t_data *data)
{
	if (data->stack_b->first == NULL || data->stack_b->first->next == NULL)
		return ;
	if (data->stack_a->first == NULL || data->stack_a->first->next == NULL)
		return ;
	rotate(data->stack_a);
	rotate(data->stack_b);
	if (write(1, "rr\n", 3) == -1)
		free_and_exit(WRITE_FAILED, EXIT_FAILURE, data);
}
