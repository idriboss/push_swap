/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:54:59 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/02 09:49:34 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# define MALLOC_FAILED "syscall: malloc failed"
# define WRITE_FAILED "syscall: write failed"

typedef struct t_node
{
	struct t_node	*next;
	struct t_node	*target;
	int				nb;
	int				cost;
}	t_node;

typedef struct t_stack
{
	struct t_node	*first;
}	t_stack;

typedef struct t_data
{
	struct t_stack	*stack_a;
	struct t_stack	*stack_b;
	int				*input;
	char			*join_args;
	char			**commands;
	char			**argv;
	int				input_count;
}	t_data;

void	init_stacks(t_data *data);
void	free_and_exit(const char *err, int code, t_data *data);
void	input_to_array(char **argv, t_data *data);
void	free_and_exit(const char *err, int code, t_data *data);
bool	is_sorted(t_data *data);
void	check_input(char *temp, char *to_free, t_data *data);
void	get_lines(char **output, t_data *data);

#endif