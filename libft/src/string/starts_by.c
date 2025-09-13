/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts_by.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:33:20 by ebini             #+#    #+#             */
/*   Updated: 2025/04/05 19:41:06 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	starts_by(const char *s, const char *pattern)
{
	while (*pattern)
	{
		if (*s != *pattern)
			return (false);
		++pattern;
		++s;
	}
	return (true);
}
