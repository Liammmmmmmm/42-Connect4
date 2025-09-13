#ifndef GRID_H
# define GRID_H

typedef struct s_grid
{
	unsigned int	width;
	unsigned int	height;
	char			*data;
}			t_grid;

typedef struct
{
    char **grid;
    int width;
    int height;
} test_grid;

#endif
