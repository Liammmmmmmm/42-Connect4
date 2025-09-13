/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:44:25 by ebini             #+#    #+#             */
/*   Updated: 2025/01/11 17:22:30 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_s_size;
	size_t	i;
	char	*sub_s;

	if (start >= ft_strlen(s))
		sub_s_size = 0;
	else
		sub_s_size = min(len, ft_strlen(s + start));
	sub_s = malloc(sub_s_size + 1);
	if (!sub_s)
		return (NULL);
	i = 0;
	while (i < sub_s_size)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = 0;
	return (sub_s);
}

// int	main(int ac, char **av)
// {
// 	char	*sub_s;

// 	if (ac > 3)
// 	{
// 		sub_s = ft_substr(av[1], ft_atoi(av[2]), ft_atoi(av[3]));
// 		printf("%s\n", sub_s);
// 		free(sub_s);
// 		return (0);
// 	}
// }
