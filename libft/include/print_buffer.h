/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buffer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:32:59 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:36:08 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_BUFFER_H
# define PRINT_BUFFER_H

# include "defs.h"

typedef struct s_pbuff
{
	int		fd;
	char	data[MEMORY_SIZE];
	size_t	mem_left;
}			t_pbuff;

t_pbuff	*pbuff_create(int fd);
void	pbuff_init(t_pbuff *buffer, int fd);
ssize_t	pbuff_flush(t_pbuff *buffer);
ssize_t	pbuff_write(t_pbuff *buffer, const char *data, size_t n);

#endif