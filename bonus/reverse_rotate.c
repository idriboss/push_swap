/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:18:25 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 16:59:50 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*before_last;

	if (stack->first == NULL || stack->first->next == NULL)
	{
		printf("reverse_rotate failed\n");
		return ;
	}
	before_last = stack->first;
	while (before_last->next != NULL && before_last->next->next != NULL)
	{
		before_last = before_last->next;
	}
	before_last->next->next = stack->first;
	stack->first = before_last->next;
	before_last->next = NULL;
}

void	r_rotate_a(t_data *data)
{
	if (data->stack_a->first == NULL || data->stack_a->first->next == NULL)
		return ;
	reverse_rotate(data->stack_a);
}

void	r_rotate_b(t_data *data)
{
	if (data->stack_b->first == NULL || data->stack_b->first->next == NULL)
		return ;
	reverse_rotate(data->stack_b);
}

void	r_rotate_ab(t_data *data)
{
	if (data->stack_b->first == NULL || data->stack_b->first->next == NULL)
		return ;
	if (data->stack_a->first == NULL || data->stack_a->first->next == NULL)
		return ;
	reverse_rotate(data->stack_a);
	reverse_rotate(data->stack_b);
}
