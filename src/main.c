#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "connect4.h"

int	main(int ac, char **av)
{
	t_game	game;

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
	destroy_game(&game);
}
