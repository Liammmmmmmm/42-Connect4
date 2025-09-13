/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmerge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:36:41 by ebini             #+#    #+#             */
/*   Updated: 2025/07/08 02:02:12 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char	*strmerge(char *s1, char *s2)
{
	char	*s3;
	size_t	s_pos;
	size_t	i;

	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = 0;
	s_pos = 0;
	while (s1[s_pos])
		s3[i++] = s1[s_pos++];
	s_pos = 0;
	while (s2[s_pos])
		s3[i++] = s2[s_pos++];
	s3[i] = '\0';
	free(s1);
	free(s2);
	return (s3);
}

char	*strmergen(char *s1, char *s2, size_t n)
{
	char	*s3;
	size_t	s_pos;
	size_t	i;

	s3 = malloc(ft_strlen(s1) + n + 1);
	if (!s3)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = 0;
	s_pos = 0;
	while (s1[s_pos])
		s3[i++] = s1[s_pos++];
	s_pos = 0;
	while (s_pos < n)
		s3[i++] = s2[s_pos++];
	s3[i] = '\0';
	free(s1);
	free(s2);
	return (s3);
}
