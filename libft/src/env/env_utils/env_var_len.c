/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:41:42 by ebini             #+#    #+#             */
/*   Updated: 2025/06/15 01:01:19 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "env.h"

size_t	env_var_len(const char *var_name)
{
	size_t	len;

	len = 0;
	if (is_env_var_start(*var_name))
		++len;
	else
		return (0);
	while (is_env_var_char(var_name[len]))
		++len;
	return (len);
}
