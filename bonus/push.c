/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:59:39 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 17:06:13 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*temp;

	temp = stack_from->first;
	stack_from->first = stack_from->first->next;
	temp->next = stack_to->first;
	stack_to->first = temp;
}

void	push_a(t_data *data)
{
	if (data->stack_b->first == NULL)
		return ;
	push(data->stack_b, data->stack_a);
}

void	push_b(t_data *data)
{
	if (data->stack_a->first == NULL)
		return ;
	push(data->stack_a, data->stack_b);
}
