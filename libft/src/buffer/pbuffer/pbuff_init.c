/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbuff_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 06:27:42 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:30:51 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "print_buffer.h"

void	pbuff_init(t_pbuff *buffer, int fd)
{
	buffer->fd = fd;
	buffer->mem_left = MEMORY_SIZE;
}

t_pbuff	*pbuff_create(int fd)
{
	t_pbuff	*buffer;

	buffer = malloc(sizeof(t_pbuff));
	pbuff_init(buffer, fd);
	return (buffer);
}
