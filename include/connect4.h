#ifndef CONNECT4_H
# define CONNECT4_H

# include "structs/game.h"


# define GRID_WIDTH_MIN 7
# define GRID_HEIGHT_MIN 6
# define GRID_WIDTH_MAX 100
# define GRID_HEIGHT_MAX 100

# define N_ALIGN 4

# define GRID_AT(g, x, y) ((g)->data[(y) * (g)->width + (x)])

# define EMPTY 0
# define PLAYER 1
# define BOT -1
# define PLAYER_THINKING 2
# define BOT_THINKING -2

# define COOLNESS 0
# define LOG_COOL 0

int		init_game(t_game *game, int g_width, int g_height);

void	put_usage(char *bin_name);

void	display_grid(t_grid *grid);

void	destroy_game(t_game *game);

int 	read_valid_column(int columns, int *grid_heights, int grid_height);

// ------ MINIMAX ------ //

float evaluate_board(t_grid *grid);
int find_best_move(t_grid *grid, int width, int height, int depth);

#endif
