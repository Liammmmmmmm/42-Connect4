/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:34:33 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 04:10:16 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	int	av_len;
// 	int	i;

// 	(void)ac;
// 	av_len = ft_strlen(av[1]);
// 	i = -1;
// 	while (++i < av_len)
// 		av[1][i] = ft_tolower(av[1][i]);
// 	printf("%s\n", av[1]);
// 	return (0);
// }
