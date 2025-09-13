/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:33:43 by saumon            #+#    #+#             */
/*   Updated: 2025/03/08 10:47:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "defs.h"

typedef struct s_cvector
{
	char	*data;
	size_t	capacity;
	size_t	len;
}			t_cvector;

typedef struct s_ivector
{
	int		*data;
	size_t	capacity;
	size_t	len;
}			t_ivector;

t_ivector	*ivec_create(int *array, size_t len);
int			ivec_init(t_ivector *vector, int *array, size_t len);
int			ivec_push(t_ivector *vector, int element);
void		ivec_set(t_ivector *vector, ssize_t index, int value);
int			ivec_get(t_ivector *vector, ssize_t index);
bool		ivec_includes(t_ivector *vector, int el);
ssize_t		ivec_index(t_ivector *vector, int el);
int			ivec_pop(t_ivector *vector);
void		ivec_print(int fd, t_ivector *vector);
void		ivec_clear(t_ivector *vector);
void		ivec_destroy(t_ivector *vector);

typedef struct s_lvector
{
	long	*data;
	size_t	capacity;
	size_t	len;
}			t_lvector;

typedef struct s_fvector
{
	float	*data;
	size_t	capacity;
	size_t	len;
}			t_fvector;

typedef struct s_dvector
{
	double	*data;
	size_t	capacity;
	size_t	len;
}			t_dvector;

typedef struct s_pvector
{
	void	**data;
	size_t	capacity;
	size_t	len;
}			t_pvector;

#endif