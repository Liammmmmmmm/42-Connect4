/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:22:34 by ebini             #+#    #+#             */
/*   Updated: 2025/01/16 21:45:12 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include "defs.h"
#include <stddef.h>	

int	arrmax(int *arr, size_t n)
{
	int		result;
	size_t	i;

	i = 0;
	result = arr[i];
	while (++i < n)
		if (arr[i] > result)
			result = arr[i];
	return (result);
}
