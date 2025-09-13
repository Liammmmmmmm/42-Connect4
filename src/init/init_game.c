#include <stdlib.h>

#include "connect4.h"
#include "libft.h"

int	init_game(t_game *game, int g_width, int g_height)
{
	game->state = 0;
	game->player_turn = rand() % 2 ? PLAYER : BOT;
	game->grid.data = ft_calloc(g_width * g_height, sizeof(char));
	game->grid.heights = ft_calloc(g_width, sizeof(char));
	if (!game->grid.data || !game->grid.heights)
	{
		free(game->grid.data);
		free(game->grid.heights);
		return (1);
	}
	game->grid.width = g_width;
	game->grid.height = g_height;
	return (0);
}
