/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saumon <saumon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:02:01 by ebini             #+#    #+#             */
/*   Updated: 2025/03/03 16:15:49 by saumon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	int		*write_dest;
	int		*read_src;
	size_t	size_limit;
	size_t	i;

	write_dest = dest;
	read_src = src;
	size_limit = n / sizeof(int);
	i = -1;
	while (++i < size_limit)
		write_dest[i] = read_src[i];
	i = i * sizeof(int) - 1;
	while (++i < n)
		((char *)write_dest)[i] = ((char *)read_src)[i];
	return (dest);
}
