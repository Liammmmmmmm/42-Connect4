/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_up_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:24:07 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:01:24 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vfprintf_utils.h"

#include "print_buffer.h"

size_t	print_up_x(t_pbuff *buffer, va_list value)
{
	return (print_base(buffer, va_arg(value, unsigned),
			"0123456789ABCDEF", 16));
}
