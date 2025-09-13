#ifndef GAME_H
# define GAME_H

# include "structs/grid.h"

typedef struct s_game
{
	t_grid	grid;
	int		player_turn;
	int		state;
}			t_game;

#endif
