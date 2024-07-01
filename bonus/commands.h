/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:54:59 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 16:59:32 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "checker.h"

void	push(t_stack *stack_from, t_stack *stack_to);
void	push_a(t_data *data);
void	push_b(t_data *data);

void	swap(t_stack *stack);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_ab(t_data *data);

void	rotate(t_stack *stack);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_ab(t_data *data);

void	reverse_rotate(t_stack *stack);
void	r_rotate_a(t_data *data);
void	r_rotate_b(t_data *data);
void	r_rotate_ab(t_data *data);

#endif