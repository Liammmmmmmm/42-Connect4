/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenvp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:04:28 by ebini             #+#    #+#             */
/*   Updated: 2025/05/08 14:22:37 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	**ft_getenvp(void)
{
	return (env_handle(ENV_TO_ENVP));
}
/**
echo test | cat > out && (echo coucou || echo oui) || echo non
 */