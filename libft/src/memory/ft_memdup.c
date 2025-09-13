/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:42:23 by ebini             #+#    #+#             */
/*   Updated: 2025/01/22 20:45:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include <stdlib.h>

void	*ft_memdup(void *ptr, size_t n)
{
	char	*result;
	size_t	i;

	result = malloc(n * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < n)
		result[i] = ((char *)ptr)[i];
	return (result);
}
