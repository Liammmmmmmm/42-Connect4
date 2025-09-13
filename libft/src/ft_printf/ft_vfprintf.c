/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:01:46 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:42:25 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "print_buffer.h"
#include "./ft_vfprintf_utils.h"

size_t	print_text(t_pbuff *buffer, const char **format)
{
	size_t	offset;
	ssize_t	writed_len;

	offset = len_flag(*format);
	writed_len = pbuff_write(buffer, *format, offset);
	*format += offset;
	if (writed_len < 0)
		return (0);
	return (writed_len);
}

size_t	print_flag(t_pbuff *buffer, const char **format, va_list args)
{
	size_t	flag_value;

	++(*format);
	flag_value = handle_flag(buffer, *format, args);
	++(*format);
	return (flag_value);
}

int	ft_vfprintf(int fd, const char *format, va_list args)
{
	int		printed_len;
	ssize_t	flush_result;
	t_pbuff	buffer;

	if (!format)
		return (-1);
	pbuff_init(&buffer, fd);
	printed_len = 0;
	while (*format)
	{
		printed_len += print_text(&buffer, &format);
		if (*format)
			printed_len += print_flag(&buffer, &format, args);
	}
	flush_result = pbuff_flush(&buffer);
	if (flush_result < 0)
		return (printed_len);
	return (printed_len + flush_result);
}
