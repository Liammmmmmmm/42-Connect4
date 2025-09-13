#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "connect4.h"

int	game_loop(t_game *game)
{
	while (!game->state)
	{
		// if (game->player_turn == PLAYER)
		//     display_grid
		//     prompt_to_play
		// else
		//     calc_best_move
		// apply_move
	}
}

int	start_game(t_game *game)
{
	return (game_loop(game));
}

int	main(int ac, char **av)
{
	t_game	game;
	int		game_result;

	if (ac != 3)
	{
		put_usage(av[0]);
		return (2);
	}
	srand(time(NULL));
	if (init_game(&game, av + 1))
	{
		write(STDERR_FILENO, "Error: fatal error occured. Closing\n", 36);
		return (1);
	}
	game_result = start_game(&game);
	if (game_result)
		write(STDERR_FILENO, "Error: fatal error occured. Closing\n", 36);
	destroy_game(&game);
	return (game_result);
}
