/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:34 by ebini             #+#    #+#             */
/*   Updated: 2025/01/22 22:37:08 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*result;

	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*result;

	result = malloc(n + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < n)
		result[i] = s[i];
	result[i] = 0;
	return (result);
}
