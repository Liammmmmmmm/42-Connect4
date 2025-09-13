/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbuff_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:31:17 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:16:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "print_buffer.h"

#include <stdio.h>

ssize_t	pbuff_write(t_pbuff *buffer, const char *data, size_t n)
{
	size_t	i;
	ssize_t	flush_result;
	ssize_t	flush_len;

	flush_len = 0;
	i = -1;
	while (++i < n)
	{
		buffer->data[MEMORY_SIZE - buffer->mem_left] = data[i];
		--(buffer->mem_left);
		if (data[i] == '\n' || !buffer->mem_left)
		{
			flush_result = pbuff_flush(buffer);
			if (flush_result < 0)
				return (-1);
			flush_len += flush_result;
		}
	}
	return (flush_len);
}
