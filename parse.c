#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

int	*parse(int argc, char **argv)
{
	int	i;
	int	count;
	int	*array;

	i = 1;
	count = 0;
	check_args(argv);
	while (i < argc - 1)
	{
		array = get_input(array, &count, argv[1]);
	}
}

int	*get_input(int *array, int *array_size, char *str)
{
	int	*buffer;
	int	num_count;
	int	i;

	num_count = count_number(str);
	buffer = ft_realloc(array, *array_size, num_count, sizeof(int));
	if (buffer == NULL)
		free_and_exit(MALLOC_FAILED, EXIT_FAILURE);
	i = 0;
	while (str[i] != '\0')
	{
		while (!(str[i] >= '0' || str[i] <= '9') && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			break;
		buffer[*array_size] = ft_atoi(str + i);
		++*array_size;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			++i;
	}
	return (buffer);
}

int	count_number(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (!(str[i] >= '0' || str[i] <= '9') && str[i] != '\0')
		++i;
	while (str[i] != '\0')
	{
		while (str[i] >= '0' && str[i] <= '9')
			++i;
		++count;
		while (!(str[i] >= '0' || str[i] <= '9') && str[i] != '\0')
			++i;
	}
	return (count);
}
