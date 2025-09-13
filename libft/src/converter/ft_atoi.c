/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:41:15 by ebini             #+#    #+#             */
/*   Updated: 2025/03/04 16:41:48 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	sign;
	long	result;

	while (('\t' <= nptr[0] && nptr[0] <= '\r') || nptr[0] == ' ')
		nptr++;
	sign = 1;
	if (nptr[0] == '+')
		nptr++;
	else if (nptr[0] == '-')
	{
		nptr++;
		sign = -1;
	}
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		++nptr;
	}
	result = sign * result;
	if (result > INT_MAX)
		return (INT_MAX);
	else if (result < INT_MIN)
		return (INT_MIN);
	return ((int)result);
}
