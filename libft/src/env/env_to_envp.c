/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:32:19 by ebini             #+#    #+#             */
/*   Updated: 2025/05/01 00:17:31 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "env.h"
#include "libft.h"

#include <stdio.h>

void	fill_envp(char **env_tab, char **result)
{
	size_t		var_count;
	size_t		i;

	var_count = 0;
	i = -1;
	while (env_tab[++i])
	{
		if (ft_strchr(env_tab[i], '='))
		{
			result[var_count] = env_tab[i];
			++var_count;
		}
	}
	result[var_count] = NULL;
}

char	**env_to_envp(t_env *env)
{
	char		**env_tab;
	size_t		var_count;
	size_t		i;
	char		**result;

	env_tab = env->data;
	var_count = 0;
	i = -1;
	while (env_tab[++i])
		if (ft_strchr(env_tab[i], '='))
			++var_count;
	result = malloc((var_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	fill_envp(env_tab, result);
	return (result);
}
