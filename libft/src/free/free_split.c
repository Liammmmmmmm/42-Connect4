/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:39:44 by ebini             #+#    #+#             */
/*   Updated: 2025/01/17 16:43:34 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_split(char **splitted_string)
{
	int	i;

	i = -1;
	while (splitted_string[++i])
		free(splitted_string[i]);
	free(splitted_string);
}
