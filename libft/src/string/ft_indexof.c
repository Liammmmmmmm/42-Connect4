/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:46:03 by ebini             #+#    #+#             */
/*   Updated: 2025/02/09 19:22:20 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

ssize_t	ft_indexof(const char *s, char c)
{
	size_t	i;

	i = -1;
	while (s[++i] && s[i] != c)
		;
	if (s[i] != c)
		return (-1);
	return (i);
}

ssize_t	ft_nindexof(const char *s, char c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n - 1 && s[i] != c)
		;
	if (s[i] != c)
		return (-1);
	return (i);
}
