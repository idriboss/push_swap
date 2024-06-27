/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:54:59 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/27 14:11:34 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "includes/libft.h"
#include <fcntl.h>
#include <stdlib.h>

typedef struct t_node
{
	int		nb;
	t_node *next;
}	t_node;

typedef struct t_stack
{
	t_node	*stack_a;
	t_node	*stack_b;
}	t_stack;

#endif