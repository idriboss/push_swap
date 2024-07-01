/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:09:30 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/29 19:47:50 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	if (stack == NULL)
		return ;
	if (stack->first == NULL)
	{
		free(stack);
		return ;
	}
	temp = stack->first;
	node = temp->next;
	if (node == NULL)
	{
		free(temp);
		free(stack);
		return ;
	}
	while (node != NULL)
	{
		node = temp->next;
		free(temp);
		temp = node;
	}
	free(stack);
}

void	free_and_exit(const char *err, int code, t_data *data)
{
	destroy_stack(data->stack_a);
	destroy_stack(data->stack_b);
	free(data->input);
	free(data->join_args);
	print_err_and_exit(err, code, false);
}
