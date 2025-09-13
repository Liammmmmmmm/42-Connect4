/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstpop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:51:33 by ebini             #+#    #+#             */
/*   Updated: 2025/04/14 11:28:56 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

#include "libft.h"

void	*lstpop(t_list **lst)
{
	void	*content;
	t_list	*parent;
	t_list	*last;

	last = *lst;
	if (!last)
		return (NULL);
	parent = NULL;
	while (last->next)
	{
		parent = last;
		last = last->next;
	}
	content = last->content;
	if (parent)
		parent->next = NULL;
	else
		*lst = NULL;
	free(last);
	return (content);
}
