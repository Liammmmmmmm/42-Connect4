/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:35:43 by ebini             #+#    #+#             */
/*   Updated: 2025/03/08 11:42:42 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"

void	ivec_set(t_ivector *vector, ssize_t index, int value)
{
	if (index < 0)
		vector->data[vector->len + index] = value;
	else
		vector->data[index] = value;
}
