/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:02:17 by ebini             #+#    #+#             */
/*   Updated: 2025/04/30 21:58:05 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "env.h"

void	env_clear(t_env *env)
{
	size_t	i;

	i = -1;
	while (env->data[++i])
		free(env->data[i]);
	free(env->data);
}
