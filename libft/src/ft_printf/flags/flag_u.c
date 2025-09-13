/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:34:32 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:01:24 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "print_buffer.h"
#include "../ft_vfprintf_utils.h"

size_t	print_unsigned(t_pbuff *buffer, unsigned int n)
{
	char	c;
	size_t	child_len;

	c = '0' + n % 10;
	n /= 10;
	if (n)
		child_len = print_unsigned(buffer, n);
	else
		child_len = 0;
	child_len += pbuff_write(buffer, &c, 1) > 0;
	return (child_len);
}

size_t	print_u(t_pbuff *buffer, va_list value)
{
	return (print_unsigned(buffer, va_arg(value, unsigned)));
}
