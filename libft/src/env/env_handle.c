/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:12:48 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 02:25:07 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "env.h"

static void	get_args(int action, va_list args, void **arg1, void **arg2)
{
	if (action == ENV_INIT)
		*arg1 = va_arg(args, char **);
	else if (action == ENV_SET)
	{
		*arg1 = va_arg(args, char *);
		*arg2 = va_arg(args, char *);
	}
	else if (action == ENV_GET)
		*arg1 = va_arg(args, char *);
	else if (action == ENV_UNSET)
		*arg1 = va_arg(args, char *);
}

static void	*switch_action(int action, va_list args, t_env *env)
{
	void	*arg1;
	void	*arg2;

	get_args(action, args, &arg1, &arg2);
	if (action == ENV_INIT)
		return ((void *)(unsigned long)env_init(env, arg1));
	else if (action == ENV_SET)
		return ((void *)(unsigned long)env_set(env, arg1, arg2));
	else if (action == ENV_GET)
		return (env_get(env, arg1));
	else if (action == ENV_UNSET)
		env_unset(env, arg1);
	else if (action == ENV_TO_ENVP)
		return (env_to_envp(env));
	else if (action == ENV_CLEAR)
		env_clear(env);
	return (NULL);
}

void	*env_handle(int action, ...)
{
	static t_env	env;
	va_list			args;
	void			*result;

	va_start(args, action);
	result = switch_action(action, args, &env);
	va_end(args);
	return (result);
}
