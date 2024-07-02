/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 08:36:03 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/02 09:49:54 by ibaby            ###   ########.fr       */
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

	if (argv[1] == NULL || argv[1][0] == '\0')
		free_and_exit("Error", EXIT_FAILURE, data);
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
	parse(data->join_args, data);
}

void	get_num(char *number, int index, t_data *data)
{
	long	num;

	if (*number && (*number == '-' || *number == '+') && (*(number + 1) < '0'
			|| *(number + 1) > '9'))
		free_and_exit("Error", EXIT_FAILURE, data);
	data->input = ft_realloc(data->input, index, index + 1, sizeof(int));
	if (data->input == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE, data);
	num = ft_atol(number);
	check_number(num, index, data, number);
	data->input[index] = (int)num;
}

void	parse(char *arg, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] != '\0')
	{
		while (arg[i] == ' ')
			++i;
		if (i > 0 && arg[i] && arg[i] != ' ' && (arg[i - 1] >= '0' && arg[i
					- 1] <= '9'))
			free_and_exit("Error", EXIT_FAILURE, data);
		get_num(arg + i, j, data);
		if (arg[i] == '-' || arg[i] == '+')
			++i;
		while (arg[i] >= '0' && arg[i] <= '9')
			++i;
		j++;
	}
	data->input_count = j;
}

void	check_number(long num, int num_count, t_data *data, char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
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

void	check_input(char *temp, char *to_free, t_data *data)
{
	int	check;

	check = 0;
	if (ft_strcmp(temp, "sa\n") == 0 || ft_strcmp(temp, "sb\n") == 0)
		++check;
	if (ft_strcmp(temp, "ss\n") == 0 || ft_strcmp(temp, "pa\n") == 0)
		++check;
	if (ft_strcmp(temp, "pb\n") == 0 || ft_strcmp(temp, "ra\n") == 0)
		++check;
	if (ft_strcmp(temp, "rb\n") == 0 || ft_strcmp(temp, "rr\n") == 0)
		++check;
	if (ft_strcmp(temp, "rra\n") == 0 || ft_strcmp(temp, "rrb\n") == 0)
		++check;
	if (ft_strcmp(temp, "rrr\n") == 0)
		++check;
	if (check != 1)
	{
		ft_free((void **)&temp);
		ft_free((void **)&to_free);
		free_and_exit("Error", EXIT_FAILURE, data);
	}
}
