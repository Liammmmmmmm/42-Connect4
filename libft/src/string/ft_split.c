/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:15:30 by ebini             #+#    #+#             */
/*   Updated: 2025/01/19 18:27:46 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_split_len(char const *s, char c)
{
	size_t	count;

	count = *s && *s != c;
	while (*++s)
		if (*s != c && *(s - 1) == c)
			count++;
	return (count);
}

static size_t	strlenchr(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

/**
 * This function will create a new string from the original
 * s with at most n + 1 (it adds null-byte) characters in it.
 * This function is only used by split this is why it is
 * not secure and it will not handle inappropriate sizes
 */
static char	*split_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*result;

	result = malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_str;
	size_t	substr_idx;
	size_t	substr_len;

	splitted_str = ft_calloc(count_split_len(s, c) + 1, sizeof(char *));
	if (!splitted_str)
		return (NULL);
	substr_idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			substr_len = strlenchr(s, c);
			splitted_str[substr_idx++] = split_strndup(s, substr_len);
			if (!splitted_str[substr_idx - 1])
			{
				free_n(splitted_str, substr_idx - 1);
				return (NULL);
			}
			s += substr_len;
		}
		else
			s++;
	}
	return (splitted_str);
}
