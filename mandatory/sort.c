/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:55:38 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 17:04:14 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "commands.h"

void	higher_half_to_b(t_data *data);
void	lowest_half_to_b(t_data *data);
void	re_arrange(t_data *data);

void	sort_stacks(t_data *data)
{
	higher_half_to_b(data);
	lowest_half_to_b(data);
	sort_3(data);
	while (data->stack_b->first != NULL)
	{
		calc_all_cost(data);
		insert(data);
	}
	re_arrange(data);
}

void	higher_half_to_b(t_data *data)
{
	t_stack	*stack;
	int		input_count;

	stack = data->stack_a;
	input_count = data->input_count;
	while (find_higher(stack)->nb > data->input[input_count * 2 / 4])
	{
		if (stack->first->nb > data->input[input_count / 4 * 3])
		{
			push_b(data);
			if (stack->first->nb <= input_count / 2)
				rotate_ab(data);
			else
				rotate_b(data);
		}
		else if (stack->first->nb > data->input[input_count * 2 / 4])
		{
			push_b(data);
		}
		else
			rotate_a(data);
	}
}

void	lowest_half_to_b(t_data *data)
{
	t_stack	*stack;
	int		input_count;

	stack = data->stack_a;
	input_count = data->input_count;
	while (find_higher(stack)->nb > data->input[input_count / 4]
		&& stack_size(stack) > 3)
	{
		if (stack->first->nb > data->input[input_count / 4])
		{
			push_b(data);
		}
		else
		{
			push_b(data);
			rotate_b(data);
		}
	}
	while (stack_size(stack) > 3)
	{
		push_b(data);
	}
}

void	re_arrange(t_data *data)
{
	t_node	*lower;

	lower = find_lowest(data->stack_a);
	rotate_to_top(lower, data->stack_a, data);
}
