#include "connect4.h"
#include "defs.h"
#include "libft.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

void	place_jeton(t_grid *grid, int x, char player)
{
	grid->data[grid->level[x] * grid->width + x] = player;
	grid->level[x]++;
}

// void	display_debug_grid(t_grid *grid)
// {
// 	ft_printf("%u:%u\n", grid->width, grid->height);
// 	ft_printf("%d %d %d %d %d %d %d %d\n", grid->level[0], grid->level[1], grid->level[2], grid->level[3], grid->level[4], grid->level[5], grid->level[6], grid->level[7]);
// 	for (int i = grid->height - 1; i >= 0; i--)
// 	{
// 		for (unsigned int j = 0; j < grid->width; j++)
// 		{
// 			ft_printf("%d", GRID_AT(grid, j, i));
// 		}
// 		ft_printf("\n");
// 	}
// }

int game_loop(t_game *game)
{
	while (!game->state)
	{
		display_grid(&game->grid);
		if (game->player_turn == PLAYER)
		{
			int player_move = read_valid_column(game->grid.width, game->grid.level, game->grid.height);
			place_jeton(&game->grid, player_move, PLAYER);

			if (evaluate_board(&game->grid) == -INFINITY)
			{
				display_grid(&game->grid);
				ft_printf("Player wins!\n");
				game->state = 1;
				return 0;
			}
		}
		else
		{
			int ai_move = find_best_move(&game->grid, game->grid.width, game->grid.height, 10);
			place_jeton(&game->grid, ai_move, BOT);

			if (evaluate_board(&game->grid) == INFINITY)
			{
				display_grid(&game->grid);
				ft_printf("AI wins!\n");
				game->state = 1;
				return 0;
			}
		}

		int is_draw = 1;
		for (unsigned int i = 0; i < game->grid.width; i++)
		{
			if (game->grid.level[i] != (int)game->grid.height)
				is_draw = 0;
		}
		if (is_draw)
		{
		    display_grid(&game->grid);
			ft_printf("It's a draw!\n");
			game->state = 1;
			return 0;
		}

		if (game->player_turn == PLAYER)
			game->player_turn = BOT;
		else
			game->player_turn = PLAYER;
	}
	return 0;
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

t_game	*g_game;

int	main(int ac, char **av)
{
	t_game	game;
	int		game_result;
	int		grid_width;
	int		grid_height;

	g_game = &game;
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
