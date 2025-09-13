/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:39:54 by ebini             #+#    #+#             */
/*   Updated: 2025/03/05 17:58:18 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector.h"
#include "libft.h"

int	ivec_init(t_ivector *vector, int *array, size_t len)
{
	size_t	elem_capacity;

	elem_capacity = (MEMORY_SIZE / 64) / sizeof(int);
	while (elem_capacity < len)
		elem_capacity <<= 1;
	vector->data = malloc(elem_capacity * sizeof(int));
	if (!vector->data)
		return (1);
	vector->capacity = elem_capacity;
	if (array)
	{
		vector->len = len;
		ft_memcpy(vector->data, array, len * sizeof(int));
	}
	else
		vector->len = 0;
	return (0);
}

t_ivector	*ivec_create(int *array, size_t len)
{
	t_ivector	*vector;

	vector = malloc(sizeof(t_ivector));
	if (!vector)
		return (NULL);
	if (ivec_init(vector, array, len))
	{
		free(vector);
		return (NULL);
	}
	return (vector);
}
