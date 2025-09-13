/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:25:53 by ebini             #+#    #+#             */
/*   Updated: 2025/03/08 10:47:25 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

ssize_t	ivec_index(t_ivector *vector, int el)
{
	size_t	i;

	i = -1;
	while (++i < vector->len)
		if (vector->data[i] == el)
			return (i);
	return (-1);
}
