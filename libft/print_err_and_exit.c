#include "libft.h"

void	print_err_and_exit(const char *err, int code, bool erno)
{
	if (erno == true)
	{
		perror(err);
	}
	else if (err != NULL)
	{
		ft_putendl_fd((char *)err, STDERR_FILENO);
	}
	exit(code);
}