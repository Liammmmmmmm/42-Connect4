#include <stdlib.h>

#include "connect4.h"

int	init_game(t_game *game, char **args)
{
	game->state = 0;
	game->player_turn = rand() % 2 ? 1 : -1;
	(void)args;
	game->grid.data = malloc(GRID_WIDTH_MIN * GRID_HEIGHT_MIN * sizeof(char));
	if (!game->grid.data)
		return (1);
	game->grid.width = GRID_WIDTH_MIN;
	game->grid.width = GRID_HEIGHT_MIN;
	return (0);
}
