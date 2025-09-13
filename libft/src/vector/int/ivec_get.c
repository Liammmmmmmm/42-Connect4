/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:35:43 by ebini             #+#    #+#             */
/*   Updated: 2025/03/05 17:58:04 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"

int	ivec_get(t_ivector *vector, ssize_t index)
{
	if (index < 0)
		return (vector->data[vector->len + index]);
	return (vector->data[index]);
}
