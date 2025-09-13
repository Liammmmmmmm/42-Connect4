/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:40:02 by ebini             #+#    #+#             */
/*   Updated: 2025/03/05 17:58:12 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector.h"

void	ivec_clear(t_ivector *vector)
{
	free(vector->data);
}

void	ivec_destroy(t_ivector *vector)
{
	free(vector->data);
	free(vector);
}
