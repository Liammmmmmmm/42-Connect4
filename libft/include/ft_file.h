/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:26:38 by ebini             #+#    #+#             */
/*   Updated: 2025/02/09 20:01:47 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H
# include "defs.h"
# include <fcntl.h>

typedef struct s_file
{
	int		fd;
	int		flags;
	char	buffer[MEMORY_SIZE];
	char	*line;
}			t_pointed_file;

typedef t_pointed_file*	t_file;

t_file	get_std_file(int fd);

#endif