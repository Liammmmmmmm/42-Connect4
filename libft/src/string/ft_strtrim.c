/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:48:42 by ebini             #+#    #+#             */
/*   Updated: 2025/02/06 14:33:00 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*strrchr_len(const char *s, int c, size_t len)
{
	while (--len + 1)
		if (s[len] == (char)c)
			return ((char *)s + len);
	return (NULL);
}

char	*ft_strtrimm(char const *s, char const *set)
{
	char	*result;
	size_t	result_len;
	size_t	i;

	while (*s && ft_strchr(set, *s))
		s++;
	result_len = ft_strlen(s);
	if (result_len)
		while (strrchr_len(set, s[result_len - 1], ft_strlen(set)))
			result_len--;
	result = malloc(result_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < result_len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/**
 * Unlike its brother above, this function will keep the same string memory bloc
 * allocated, but return a pointer to the first character not in set and replace
 * the first character of the last group of characters belonging to set by a \0
 */
char	*ft_strtrim(char *s, char const *set)
{
	size_t	result_len;

	while (*s && ft_strchr(set, *s))
		s++;
	result_len = ft_strlen(s);
	while (--result_len && ft_strchr(set, s[result_len]))
		;
	s[result_len + 1] = '\0';
	return (s);
}
