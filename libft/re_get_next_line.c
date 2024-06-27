#include "get_next_line.h"

char	*re_join_get_next_line(int fd, char **str_address)
{
	char	*gnl;

	gnl = get_next_line(fd);
	if (gnl == NULL)
		return (*str_address);
	*str_address = ft_re_strjoin(*str_address, gnl);
	ft_free((void **)&gnl);
	return (*str_address);
}
