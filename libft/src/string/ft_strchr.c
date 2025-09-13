/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:02:16 by ebini             #+#    #+#             */
/*   Updated: 2025/01/11 17:16:46 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	s--;
	while (*++s)
		if (*s == (char)c)
			return (((char *)s));
	if ((char)c == '\0')
		return (((char *)s));
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) + 1;
	while (--i > -1)
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (NULL);
}
