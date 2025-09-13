/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:58 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:01:24 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "print_buffer.h"
#include "../ft_vfprintf_utils.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

size_t	print_s(t_pbuff *buffer, va_list value)
{
	char	*s;
	ssize_t	write_size;

	s = va_arg(value, char *);
	if (!s)
	{
		write_size = pbuff_write(buffer, "(null)", 6);
		if (write_size < 0)
			return (0);
		return (write_size);
	}
	write_size = pbuff_write(buffer, s, ft_strlen(s));
	if (write_size < 0)
		return (0);
	return (write_size);
}
