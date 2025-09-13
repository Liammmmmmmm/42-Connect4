#include "connect4.h"
#include "defs.h"
#include "libft.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	game_loop(t_game *game)
{
	char	buffer[MEMORY_SIZE];

	while (!game->state)
	{
		// if (game->player_turn == PLAYER)
		read(STDIN_FILENO, buffer, MEMORY_SIZE);
		display_grid(game);
		//     prompt_to_play
		// else
		//     calc_best_move
		// apply_move
	}
	return (0);
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
			return (0);
		str++;
	}
	return (1);
}
int	main(int ac, char **av)
{
	t_game	game;
	int		game_result;
	int		grid_width;
	int		grid_height;










	if (ac != 3)
	{
		put_usage(av[0]);
		return (2);
	}
	if (ft_strlen(av[1]) > 5 || ft_strlen(av[2]) > 5 || !is_num_only(av[1])
		|| !is_num_only(av[2]))
	{
		ft_dprintf(STDERR_FILENO, "Invalid grid size\n");
		return (2);
	}

	grid_width = ft_atoi(av[1]);
	grid_height = ft_atoi(av[2]);
	if (grid_width > GRID_WIDTH_MAX || grid_height > GRID_HEIGHT_MAX)
	{
		ft_dprintf(STDERR_FILENO, "Grid too large\n");
		return (2);
	}
	if (grid_width < GRID_WIDTH_MIN || grid_height < GRID_HEIGHT_MIN)
	{
		ft_dprintf(STDERR_FILENO, "Grid too small\n");
		return (2);
	}











	srand(time(NULL));
	if (init_game(&game, grid_width, grid_height))
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
