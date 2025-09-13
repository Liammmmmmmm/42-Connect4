/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:36:02 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:01:24 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VFPRINTF_UTILS_H
# define FT_VFPRINTF_UTILS_H

# include <stdarg.h>
# include <stddef.h>

# include "print_buffer.h"

size_t	len_flag(const char *s);
size_t	print_base(t_pbuff *buffer, unsigned long long n, char *base,
			int base_len);

size_t	handle_flag(t_pbuff *buffer, const char *format, va_list args);

int		ft_vfprintf(int fd, const char *format, va_list args);

#endif