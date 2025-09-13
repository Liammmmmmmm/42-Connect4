#ifndef GRID_H
# define GRID_H

typedef struct s_grid
{
	unsigned int	width;
	unsigned int	height;
	char			*data;
	int				*level;
}			t_grid;

#endif
