/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:50:32 by ebini             #+#    #+#             */
/*   Updated: 2025/04/05 17:19:55 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * This function will concatenate 2 strings and set the result
 * pointer to this new allocated string and then free s1.
 * It will return the length of s2 that was concatenated or -1 if
 * allocation fails.
 */
int	strjoin_nl(char **s1, t_reader *reader)
{
	size_t	pre_len;
	size_t	suf_len;
	char	*result;
	char	*suffix;

	pre_len = 0;
	if (*s1)
		pre_len = ft_strlen(*s1);
	suffix = reader->buffer + reader->pos;
	suf_len = ft_strnlen_nl(suffix, reader->to_read - reader->pos);
	result = malloc(pre_len + suf_len + 1);
	if (!result)
		return (-1);
	ft_memcpy(result, *s1, pre_len);
	ft_memcpy(result + pre_len, suffix, suf_len);
	result[pre_len + suf_len] = '\0';
	reader->pos += suf_len;
	if (*s1)
		free(*s1);
	*s1 = result;
	return (result[pre_len + suf_len - 1] != '\n');
}

int	secure_read(int fd, t_reader *reader, size_t buffer_size, char *result)
{
	reader->to_read = read(fd, reader->buffer, buffer_size);
	if (reader->to_read < 0 || (reader->to_read == 0 && !result))
		return (-1);
	reader->pos = 0;
	return (reader->to_read);
}

char	*get_next_line(int fd)
{
	static t_reader	reader[FOPEN_MAX];
	char			*result;
	int				return_value;

	if (fd >= FOPEN_MAX)
		return (NULL);
	result = NULL;
	while (1)
	{
		if (reader[fd].pos < reader[fd].to_read)
			return_value = strjoin_nl(&result, &reader[fd]);
		else
			return_value = secure_read(fd, &reader[fd], BUFFER_SIZE, result);
		if (return_value < 0)
		{
			free(result);
			return (NULL);
		}
		if (!return_value)
			return (result);
	}
}
