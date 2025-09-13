/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:43:28 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:01:24 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "print_buffer.h"
#include "./flags.h"

size_t	handle_flag(t_pbuff *buffer, const char *format, va_list args)
{
	if (*format == 'c')
		return (print_c(buffer, args));
	else if (*format == 's')
		return (print_s(buffer, args));
	else if (*format == 'p')
		return (print_p(buffer, args));
	else if (*format == 'd' || *format == 'i')
		return (print_i(buffer, args));
	else if (*format == 'u')
		return (print_u(buffer, args));
	else if (*format == 'x')
		return (print_low_x(buffer, args));
	else if (*format == 'X')
		return (print_up_x(buffer, args));
	else if (*format == '%')
		return (pbuff_write(buffer, format, 1) > 0);
	return (-1);
}
