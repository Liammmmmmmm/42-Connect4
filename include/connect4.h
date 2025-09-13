#ifndef CONNECT4_H
# define CONNECT4_H

# include "structs/grid.h"
# include "structs/game.h"

# define GRID_WIDTH_MIN 7
# define GRID_HEIGHT_MIN 6

int		init_game(t_game *game, char **args);

void	put_usage(char *bin_name);

void	destroy_game(t_game *game);

#endif
