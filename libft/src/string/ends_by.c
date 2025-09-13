/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ends_by.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:33:20 by ebini             #+#    #+#             */
/*   Updated: 2025/04/05 19:38:47 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ends_by(const char *s, const char *pattern)
{
	size_t	offset;
	size_t	pattern_len;

	pattern_len = ft_strlen(pattern);
	offset = ft_strlen(s) - pattern_len;
	while (pattern_len--)
	{
		if (s[offset + pattern_len] != pattern[pattern_len])
			return (false);
	}
	return (true);
}
