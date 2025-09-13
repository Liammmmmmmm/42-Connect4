#include <stdlib.h>

#include "structs/game.h"

void	destroy_game(t_game *game)
{
	free(game->grid.data);
	free(game->grid.heights);
}
