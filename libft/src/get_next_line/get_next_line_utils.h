/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:51:36 by ebini             #+#    #+#             */
/*   Updated: 2025/01/20 18:56:49 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <stddef.h>
# include "libft.h"

typedef struct s_reader
{
	char	(buffer[BUFFER_SIZE]);
	int		to_read;
	int		pos;
}			t_reader;

size_t		ft_strnlen_nl(const char *s, size_t n);

#endif
