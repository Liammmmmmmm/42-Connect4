/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:45:21 by ebini             #+#    #+#             */
/*   Updated: 2025/01/22 18:58:38 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

void	lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*child;

	if (!(*lst))
		return ;
	while (*lst)
	{
		child = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = child;
	}
	*lst = NULL;
}
