/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:21:13 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/19 22:59:43 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(void **elem)
{
	if (*elem == NULL)
		return ;
	free(*elem);
	*elem = NULL;
}