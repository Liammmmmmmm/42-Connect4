/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:32:08 by ebini             #+#    #+#             */
/*   Updated: 2025/01/22 18:58:41 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

void	lstdelone(t_list *lst, void (*del)(void *))
{
	if (del)
		(*del)(lst->content);
	free(lst);
}
