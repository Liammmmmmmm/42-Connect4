#include "connect4.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

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
	else if (GRID_AT(grid, 0, yi) == BOT)
		ft_printf("┃ 🔴 ");
	else if (GRID_AT(grid, 0, yi) == PLAYER)
		ft_printf("┃ 🔵 "); // 🟢
	else if (GRID_AT(grid, 0, yi) == BOT_THINKING)
		ft_printf("┃ 🟠 ");
	else if (GRID_AT(grid, 0, yi) == PLAYER_THINKING)
		ft_printf("┃ 🟣 ");
	else
		ft_printf("┃ ⚠️ ");
	for (unsigned int xi = 0; xi < grid->width - 1; xi++)
	{
		if (!GRID_AT(grid, xi + 1, yi))
			ft_printf("│    ");
		else if (GRID_AT(grid, xi + 1, yi) == BOT)
			ft_printf("│ 🔴 ");
		else if (GRID_AT(grid, xi + 1, yi) == PLAYER)
			ft_printf("│ 🔵 ");
		else if (GRID_AT(grid, xi + 1, yi) == BOT_THINKING)
			ft_printf("│ 🟠 ");
		else if (GRID_AT(grid, xi + 1, yi) == PLAYER_THINKING)
			ft_printf("│ 🟣 ");
		else 
			ft_printf("│ ⚠️ ");
	}
	ft_printf("┃\n");
}

static inline void	display_endline(unsigned int width)
{
	ft_printf("┗━━━━");
	for (unsigned int xi = 0; xi < width; xi++)
		ft_printf("┷━━━━");
	ft_printf("┛\n");
	unsigned int	i = 1;
	ft_printf("  ");
	while (i <= width && i < 10)
		ft_printf("%d    ", i);
	while (i <= width && i < 100)
		ft_printf("%d   ", i);
	while (i <= width && i < 1000)
		ft_printf("%d  ", i);
	ft_printf("\n");
}

void	display_grid(t_grid *grid)
{
	ft_printf("\033[2J\033[H");
	for (unsigned int yi = 0; yi < grid->height; yi++)
	{
		display_delimitation(yi, grid->width - 1);
		display_line(grid, grid->height - yi - 1);
	}
	display_endline(grid->width - 1);
}
