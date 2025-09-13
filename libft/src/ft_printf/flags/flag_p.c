/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:24:07 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:01:24 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

#include "print_buffer.h"
#include "../ft_vfprintf_utils.h"

size_t	print_p(t_pbuff *buffer, va_list value)
{
	uintptr_t	p;
	ssize_t		write_size;

	p = va_arg(value, uintptr_t);
	if (!p)
	{
		write_size = pbuff_write(buffer, "(nil)", 5);
		if (write_size < 0)
			return (0);
		return (write_size);
	}
	write_size = pbuff_write(buffer, "0x", 2);
	if (write_size < 0)
		write_size = 0;
	return (write_size + print_base(buffer, p, "0123456789abcdef", 16));
}
