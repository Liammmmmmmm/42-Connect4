/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:32:20 by ebini             #+#    #+#             */
/*   Updated: 2025/01/22 18:58:30 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

void	lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		(lst) = &((*lst)->next);
	(*lst)->next = new;
}
