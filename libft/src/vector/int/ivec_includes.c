/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec_includes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:22:53 by ebini             #+#    #+#             */
/*   Updated: 2025/03/08 10:47:16 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

bool	ivec_includes(t_ivector *vector, int el)
{
	size_t	i;

	i = -1;
	while (++i < vector->len)
		if (vector->data[i] == el)
			return (true);
	return (false);
}
