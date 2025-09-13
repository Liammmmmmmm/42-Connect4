/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:43:39 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:01:24 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include <stdarg.h>
# include <sys/types.h>

# include "print_buffer.h"

size_t	print_c(t_pbuff *buffer, va_list value);
size_t	print_s(t_pbuff *buffer, va_list value);
size_t	print_p(t_pbuff *buffer, va_list value);
size_t	print_i(t_pbuff *buffer, va_list value);
size_t	print_u(t_pbuff *buffer, va_list value);
size_t	print_low_x(t_pbuff *buffer, va_list value);
size_t	print_up_x(t_pbuff *buffer, va_list value);

#endif