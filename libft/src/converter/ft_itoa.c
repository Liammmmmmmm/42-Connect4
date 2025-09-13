/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:46:32 by ebini             #+#    #+#             */
/*   Updated: 2025/01/07 16:34:32 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	int_size(int x)
{
	size_t	size;

	size = x <= 0;
	while (x)
	{
		size++;
		x /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	str_len;
	char	*str;

	str_len = int_size(n);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	str[str_len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		str[--str_len] = '0' - n % 10;
		n /= 10;
		n = -n;
	}
	while (n)
	{
		str[--str_len] = '0' + n % 10;
		n /= 10;
	}
	return (str);
}
