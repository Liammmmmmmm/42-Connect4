/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbuff_flush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:37:20 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:01:24 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "print_buffer.h"

ssize_t	pbuff_flush(t_pbuff *buffer)
{
	ssize_t	written;

	written = write(buffer->fd, buffer->data, MEMORY_SIZE - buffer->mem_left);
	buffer->mem_left = MEMORY_SIZE;
	return (written);
}
