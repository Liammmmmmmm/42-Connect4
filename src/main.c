#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "connect4.h"
#include "libft.h"

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

int	is_num_only(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return 0;
		str++;
	}
	return (1);
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

	if (ft_strlen(av[1]) > 5 || ft_strlen(av[2] > 5)
		|| !is_num_only(av[1]) || !is_num_only(av[2]))
	{
		ft_dprintf(STDERR_FILENO, "Invalid grid size\n");
		return (1);
	}
	int g_width = ft_atoi(av[1]);
	int g_height = ft_atoi(av[2]);
	if (g_width > GRID_WIDTH_MAX || g_height > GRID_HEIGHT_MAX)
	{
		ft_dprintf(STDERR_FILENO, "Grid too large\n");
		return (1);
	}
	if (g_width < GRID_WIDTH_MIN || g_height < GRID_HEIGHT_MIN)
	{
		ft_dprintf(STDERR_FILENO, "Grid too large\n");
		return (1);
	}

	srand(time(NULL));
	if (init_game(&game, g_width, g_height))
	{
		ft_dprintf(STDERR_FILENO, "Error: fatal error occured. Closing\n");
		return (1);
	}
	game_result = start_game(&game);
	if (game_result)
		ft_dprintf(STDERR_FILENO, "Error: fatal error occured. Closing\n");
	destroy_game(&game);
	return (game_result);
}
