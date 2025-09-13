/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:32:46 by ebini             #+#    #+#             */
/*   Updated: 2025/03/06 01:02:57 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

t_file	std_file(int fd)
{
	static t_pointed_file	std_files[3] = {
	{fd: 0, flags: O_RDONLY},
	{fd: 1, flags: O_WRONLY},
	{fd: 2, flags: O_WRONLY}
	};

	return (std_files + fd);
}
