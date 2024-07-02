/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:57 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/02 08:00:25 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		print_err_and_exit(NULL, EXIT_FAILURE, false);
	ft_memset(&data, 0, sizeof(t_data));
	input_to_array(argv, &data);
	init_stacks(&data);
	if (is_sorted(&data) == true)
		free_and_exit(NULL, EXIT_FAILURE, &data);
	if (data.input_count == 2)
	{
		sort_2(&data);
		free_and_exit(NULL, EXIT_SUCCESS, &data);
	}
	else if (data.input_count == 3)
	{
		sort_3(&data);
		free_and_exit(NULL, EXIT_SUCCESS, &data);
	}
	sort_array(data.input, data.input_count);
	sort_stacks(&data);
	free_and_exit(NULL, EXIT_SUCCESS, &data);
}
