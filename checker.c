#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*commands;
	int		*array;
	t_data	data;

	commands = get_next_line(0);
	ft_memset(data, 0, sizeof(data));
	init_stacks(&data);
	array = input_to_array(argv, &data);
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
	init_args(array, data)
	free_and_exit(NULL, EXIT_SUCCESS, &data);
}
