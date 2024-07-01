/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 08:36:03 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 17:06:33 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <unistd.h>

void	check_number(long num, int num_count, t_data *data, char *arg);
void	parse(char *arg, t_data *data);

void	input_to_array(char **argv, t_data *data)
{
	int	i;

	data->join_args = ft_strdup(argv[1]);
	if (data->join_args == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	i = 2;
	while (argv[i] != NULL)
	{
		data->join_args = multi_re_strjoin(3, data->join_args, " ", argv[i]);
		if (data->join_args == NULL)
			free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
		++i;
	}
	if (ft_atol(data->join_args) == 0)
		free_and_exit("Error\n", EXIT_FAILURE, data);
	parse(data->join_args, data);
}

void	get_num(char *number, int index, t_data *data)
{
	long	num;

	num = ft_atol(number);
	check_number(num, index, data, number);
	data->input[index] = (int)num;
}

void	parse(char *arg, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arg[i] == ' ')
		++i;
	while (arg[i] != '\0')
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '+' && arg[i] != '-')
			free_and_exit("Error", EXIT_FAILURE, data);
		data->input = ft_realloc(data->input, j, j + 1, sizeof(int));
		if (data->input == NULL)
			free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
		get_num(arg + i, j, data);
		if (arg[i] == '-' || arg[i] == '+')
			++i;
		while (arg[i] >= '0' && arg[i] <= '9')
			++i;
		while (arg[i] == ' ')
			++i;
		j++;
	}
	data->input_count = j;
}

void	check_number(long num, int num_count, t_data *data, char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i] >= '0' && arg[i] <= '9')
		i++;
	if (i > 12)
		free_and_exit("Error", EXIT_FAILURE, data);
	if (num < INT_MIN || num > INT_MAX)
		free_and_exit("Error", EXIT_FAILURE, data);
	i = 0;
	while (i < num_count)
	{
		if (data->input[i] == (int)num)
			free_and_exit("Error", EXIT_FAILURE, data);
		i++;
	}
}
