#include <unistd.h>

#include "libft.h"

void	put_usage(char *bin_name)
{
	ft_dprintf(STDERR_FILENO, "Usage: %s <height> <width>\n", bin_name);
	ft_dprintf(STDERR_FILENO, "    Start a Connect Four game with given board size.\n");
}
