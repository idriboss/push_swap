#include "libft.h"

int	count_char_2d(char **array, char char_to_count)
{
	int	x;
	int	y;
	int	count;

	y = -1;
	count = 0;
	while (array[++y] != NULL)
	{
		x = -1;
		while (array[y][++x] != '\0')
		{
			if (array[y][x] == char_to_count)
				++count;
		}
	}
	return (count);
}