/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:28:32 by ebini             #+#    #+#             */
/*   Updated: 2025/01/11 16:20:52 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapped_str;

	mapped_str = malloc(ft_strlen(s) + 1);
	if (!mapped_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapped_str[i] = f(i, s[i]);
		i++;
	}
	mapped_str[i] = '\0';
	return (mapped_str);
}
