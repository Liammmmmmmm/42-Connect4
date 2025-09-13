/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:23:41 by ebini             #+#    #+#             */
/*   Updated: 2025/04/30 21:51:34 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;

	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}

char	*strjoinall(size_t count, ...)
{
	va_list	args;
	char	**tab;
	size_t	i;
	size_t	result_size;
	char	*result;

	tab = malloc(count * sizeof(char *));
	if (!tab)
		return (NULL);
	i = -1;
	result_size = 0;
	va_start(args, count);
	while (++i < count)
	{
		tab[i] = va_arg(args, char *);
		result_size += ft_strlen(tab[i]);
	}
	result = malloc(result_size * sizeof(char) + 1);
	i = -1;
	result_size = 0;
	while (++i < count)
		result_size += ft_strcpy_len(result + result_size, tab[i]);
	free(tab);
	return (result);
}
