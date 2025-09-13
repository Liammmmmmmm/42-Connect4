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
	return 0;
}

int	start_game(t_game *game)
{
	return (game_loop(game));
}

int main() {
    int width = 7;
    int height = 6;

    test_grid grid;
    grid.width = width;
    grid.height = height;
    grid.grid = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++)
	{
        grid.grid[i] = (char *)malloc(width * sizeof(char));
        for (int j = 0; j < width; j++)
            grid.grid[i][j] = ' ';
    }

    int depth = 5;
    int bestMove = find_best_move(grid, width, height, depth);
    ft_printf("Best move for the IA is column %d\n", bestMove);

    for (int i = 0; i < height; i++)
        free(grid.grid[i]);
    free(grid.grid);

    return 0;
}

// int	main(int ac, char **av)
// {
// 	t_game	game;
// 	int		game_result;

// 	if (ac != 3)
// 	{
// 		put_usage(av[0]);
// 		return (2);
// 	}
// 	srand(time(NULL));
// 	if (init_game(&game, av + 1))
// 	{
// 		write(STDERR_FILENO, "Error: fatal error occured. Closing\n", 36);
// 		return (1);
// 	}
// 	game_result = start_game(&game);
// 	if (game_result)
// 		write(STDERR_FILENO, "Error: fatal error occured. Closing\n", 36);
// 	destroy_game(&game);
// 	return (game_result);
// }
