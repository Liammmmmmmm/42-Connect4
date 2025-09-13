#include "connect4.h"
#include "libft.h"
#include <unistd.h>

#define a "─━│┃┄┅┆┇┈┉┊┋┌┍┎┏┐┑┒┓└┕┖┗┘┙┚┛├┝┞┟┠┡┢┣┤┥┦┧┨┩┪┫┬┭┮┯┰┱┲┳┴┵┶┷┸┹┺┻┼┽┾┿╀╁╂╃╄╅╆╇╈╉╊╋╌╍╎╏"

static inline void	display_delimitation(unsigned int yi, unsigned int width)
{
	if (yi == 0)
	{
		ft_printf("┏━━━━");
		for (unsigned int xi = 0; xi < width; xi++)
			ft_printf("┯━━━━");
		ft_printf("┓\n");
	}
	else
	{
		ft_printf("┠    ");
		for (unsigned int xi = 0; xi < width; xi++)
			ft_printf("┼    ");
		ft_printf("┨\n");
	}
}

static inline void	display_line(t_grid *grid, unsigned int yi)
{
	if (!GRID_AT(grid, 0, yi))
		ft_printf("┃    ");
	else if (GRID_AT(grid, 0, yi) < 0)
		ft_printf("┃ 🔴 ");
	else
		ft_printf("┃ 🔵 "); // 🟢
	for (unsigned int xi = 0; xi < grid->width - 1; xi++)
	{
		if (!GRID_AT(grid, xi + 1, yi))
			ft_printf("│    ");
		else if (GRID_AT(grid, xi + 1, yi) < 0)
			ft_printf("│ 🔴 ");
		else
			ft_printf("│ 🔵 ");
	}
	ft_printf("┃\n");
}

static inline void	display_endline(unsigned int width)
{
	ft_printf("┗━━━━");
	for (unsigned int xi = 0; xi < width; xi++)
		ft_printf("┷━━━━");
	ft_printf("┛\n");
}

void	display_grid(t_game *game)
{
	for (unsigned int yi = 0; yi < game->grid.height; yi++)
	{
		display_delimitation(yi, game->grid.width - 1);
		display_line(&game->grid, yi);
	}
	display_endline(game->grid.width - 1);
}
