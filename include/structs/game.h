#ifndef GAME_H
# define GAME_H

# include "structs/grid.h"

typedef struct s_game
{
	t_grid	grid;
	int		player_turn;
	int		state;
}			t_game;


int is_column_full(test_grid grid, int col);
int get_available_row(test_grid grid, int col);
int minimax(test_grid grid, int depth, int alpha, int beta, int maximizingPlayer, int width, int height);
int find_best_move(test_grid grid, int width, int height, int depth);
int game_over(test_grid grid, int width, int height);


#endif
