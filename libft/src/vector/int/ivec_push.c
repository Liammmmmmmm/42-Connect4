/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:20:30 by ebini             #+#    #+#             */
/*   Updated: 2025/03/05 17:57:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector.h"
#include "libft.h"

int	ivec_push(t_ivector *vector, int element)
{
	int	*new_area;

	if (vector->len == vector->capacity)
	{
		new_area = malloc((vector->capacity << 1) * sizeof(int));
		if (!new_area)
			return (1);
		ft_memcpy(new_area, vector->data, vector->capacity * sizeof(int));
		free(vector->data);
		vector->data = new_area;
		vector->capacity = vector->capacity << 1;
	}
	vector->data[vector->len] = element;
	++(vector->len);
	return (0);
}
