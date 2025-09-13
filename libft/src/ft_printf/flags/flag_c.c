/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:21:47 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:01:24 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "print_buffer.h"

size_t	print_c(t_pbuff *buffer, va_list value)
{
	char	c;
	int		write_size;

	c = va_arg(value, int);
	write_size = pbuff_write(buffer, &c, 1);
	if (write_size < 0)
		return (0);
	return (write_size);
}
