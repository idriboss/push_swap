/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:59:56 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 16:59:57 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	swap(data->stack_a);
}

void	swap_b(t_data *data)
{
	swap(data->stack_b);
}

void	swap_ab(t_data *data)
{
	swap_a(data);
	swap_b(data);
}
