/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:28:00 by ebini             #+#    #+#             */
/*   Updated: 2025/01/19 18:49:28 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_split_len(char const *s, const char *set)
{
	size_t	count;

	count = *s && *s != 0;
	while (*++s)
		if (!ft_strchr(set, *s) && ft_strchr(set, *(s - 1)))
			count++;
	return (count);
}

static size_t	strlenchr(char const *s, const char *set)
{
	size_t	i;

	i = 0;
	while (s[i] && !ft_strchr(set, s[i]))
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

char	**ft_strtok(char const *s, const char *set)
{
	char	**splitted_str;
	size_t	substr_idx;
	size_t	substr_len;

	splitted_str = ft_calloc(count_split_len(s, set) + 1, sizeof(char *));
	if (!splitted_str)
		return (NULL);
	substr_idx = 0;
	while (*s)
	{
		if (!ft_strchr(set, *s))
		{
			substr_len = strlenchr(s, set);
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
