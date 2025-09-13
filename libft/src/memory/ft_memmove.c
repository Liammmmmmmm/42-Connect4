/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:36:25 by ebini             #+#    #+#             */
/*   Updated: 2025/01/08 13:30:52 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(const void *src, void *dest, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while ((--n) + 1 >= (size_t)(1))
			((char *)dest)[n] = ((char *)src)[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	*src = "this is a good nyancat !\r\n";
// 	char	dst1[0xF0];
// 	char	dst2[0xF0];
// 	int		size;

// 	size = strlen(src);
// 	memmove(dst1, src, size);
//     ft_memmove(dst2, src, size);
// 	printf("%s\n", dst1);
// 	printf("%s\n", dst2);
// }
