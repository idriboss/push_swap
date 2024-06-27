#include "libft.h"

int	count_char(char *str, char char_to_count)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == char_to_count)
			++count;
		i++;
	}
	return (count);
}