/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saumon <saumon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:22:00 by ebini             #+#    #+#             */
/*   Updated: 2025/03/03 07:33:40 by saumon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <sys/types.h>

# define MEMORY_SIZE 4096

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

#endif
