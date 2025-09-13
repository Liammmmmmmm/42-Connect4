/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 06:44:00 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 06:51:48 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"

void	ft_perror(const char *message)
{
	if (message)
		ft_dprintf(STDERR_FILENO, "%s: %s\n", message, strerror(errno));
	else
		ft_dprintf(STDERR_FILENO, "%s\n", strerror(errno));
}

void	ft_dperror(int fd, const char *message)
{
	if (message)
		ft_dprintf(fd, "%s: %s\n", message, strerror(errno));
	else
		ft_dprintf(fd, "%s\n", strerror(errno));
}
