/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:57:10 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/02 09:52:24 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	init_nodes(t_data *t_data);

void	init_stacks(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (stack_a == NULL || stack_b == NULL)
	{
		ft_free((void **)&stack_a);
		ft_free((void **)&stack_b);
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

void	get_lines(char **output, t_data *data)
{
	int		i;
	char	*temp;

	free((i = 0, temp = get_next_line(0), NULL));
	if (temp == NULL)
	{
		ft_free((void **)output);
		if (is_sorted(data) == true)
			free_and_exit("OK", EXIT_SUCCESS, data);
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	}
	if (*temp == '\n')
		free_and_exit("KO", EXIT_FAILURE, data);
	check_input(temp, *output, data);
	while (temp != NULL)
	{
		*output = ft_re_strjoin(*output, temp);
		if (*output == NULL)
			free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
		ft_free((void **)&temp);
		temp = get_next_line(0);
		if (temp == NULL)
			return ;
		check_input(temp, *output, data);
	}
}
