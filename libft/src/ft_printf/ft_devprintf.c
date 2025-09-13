/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_devprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:03:43 by ebini             #+#    #+#             */
/*   Updated: 2025/05/13 16:02:38 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_vfprintf_utils.h"

#ifdef DEV

int	ft_devprintf(const char *format, ...)
{
	int		printf_return;
	va_list	args;

	va_start(args, format);
	printf_return = ft_vfprintf(2, format, args);
	va_end(args);
	return (printf_return);
}
#else

int	ft_devprintf(const char *format, ...)
{
	(void)format;
	return (0);
}
#endif
