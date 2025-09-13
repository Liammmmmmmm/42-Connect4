/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:25:13 by ebini             #+#    #+#             */
/*   Updated: 2025/06/30 19:05:43 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

#include <stdio.h>

void	env_unset(t_env *env, char *var_name)
{
	const size_t	name_len = ft_strlen(var_name);
	char			**env_tab;

	env_tab = env->data;
	while (*env_tab)
	{
		if (starts_by(*env_tab, var_name) && (*env_tab)[name_len] == '=')
			(*env_tab)[name_len] = '\0';
		++env_tab;
	}
}
