/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:03:25 by ebini             #+#    #+#             */
/*   Updated: 2025/01/19 18:53:34 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_vfprintf_utils.h"
#include <stdarg.h>

int	ft_dprintf(int fd, const char *format, ...)
{
	int		printf_return;
	va_list	args;

	va_start(args, format);
	printf_return = ft_vfprintf(fd, format, args);
	va_end(args);
	return (printf_return);
}
