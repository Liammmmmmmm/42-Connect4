/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:52:50 by ebini             #+#    #+#             */
/*   Updated: 2025/07/19 23:36:52 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "env.h"
#include "libft.h"

int	env_init(t_env *env, char **envp)
{
	size_t	capacity;
	size_t	i;

	capacity = ENV_MIN_CAPACITY;
	i = -1;
	while (envp[++i])
		if (i >= capacity - 1)
			capacity *= 2;
	env->data = malloc((capacity + 1) * sizeof(char *));
	if (!env->data)
		return (1);
	env->capacity = capacity;
	i = -1;
	while (envp[++i])
	{
		env->data[i] = ft_strdup(envp[i]);
		if (!env->data[i])
		{
			free_n(env->data, i);
			return (2);
		}
	}
	env->data[i] = NULL;
	return (0);
}

t_env	*env_create(char **envp)
{
	t_env	*result;

	if (!envp)
		return (NULL);
	result = malloc(sizeof(t_env));
	if (!result)
		return (NULL);
	if (env_init(result, envp))
	{
		free(result);
		return (NULL);
	}
	return (result);
}
