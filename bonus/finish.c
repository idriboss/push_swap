/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:09:30 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/02 07:28:28 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	destroy_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	if (stack == NULL)
		return ;
	if (stack->first == NULL)
	{
		ft_free((void **)&stack);
		return ;
	}
	temp = stack->first;
	node = temp->next;
	if (node == NULL)
	{
		ft_free((void **)&temp);
		ft_free((void **)&stack);
		return ;
	}
	while (node != NULL)
	{
		node = temp->next;
		ft_free((void **)&temp);
		temp = node;
	}
	ft_free((void **)&stack);
}

void	free_and_exit(const char *err, int code, t_data *data)
{
	destroy_stack(data->stack_a);
	destroy_stack(data->stack_b);
	ft_free((void **)&data->input);
	ft_free((void **)&data->join_args);
	free_2d_array((void ***)&data->commands);
	print_err_and_exit(err, code, false);
}
