#include "connect4.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

#define a "─━│┃┄┅┆┇┈┉┊┋┌┍┎┏┐┑┒┓└┕┖┗┘┙┚┛├┝┞┟┠┡┢┣┤┥┦┧┨┩┪┫┬┭┮┯┰┱┲┳┴┵┶┷┸┹┺┻┼┽┾┿╀╁╂╃╄╅╆╇╈╉╊╋╌╍╎╏"

static inline void	display_delimitation(unsigned int yi, unsigned int width)
{
	if (yi == 0)
	{
		printf("┏━━━━");
		for (unsigned int xi = 0; xi < width; xi++)
			printf("┯━━━━");
		printf("┓\n");
	}
	else
	{
		printf("┠    ");
		for (unsigned int xi = 0; xi < width; xi++)
			printf("┼    ");
		printf("┨\n");
	}
}

static inline void	display_line(t_grid *grid, unsigned int yi)
{
	if (!GRID_AT(grid, 0, yi))
		printf("┃    ");
	else if (GRID_AT(grid, 0, yi) == BOT)
		printf("┃ 🔴 ");
	else if (GRID_AT(grid, 0, yi) == PLAYER)
		printf("┃ 🔵 "); // 🟢
	else if (GRID_AT(grid, 0, yi) == BOT_THINKING)
		printf("┃ 🟠 ");
	else if (GRID_AT(grid, 0, yi) == PLAYER_THINKING)
		printf("┃ 🟣 ");
	else
		printf("┃ ⚠️ ");
	for (unsigned int xi = 0; xi < grid->width - 1; xi++)
	{
		if (!GRID_AT(grid, xi + 1, yi))
			printf("│    ");
		else if (GRID_AT(grid, xi + 1, yi) == BOT)
			printf("│ 🔴 ");
		else if (GRID_AT(grid, xi + 1, yi) == PLAYER)
			printf("│ 🔵 ");
		else if (GRID_AT(grid, xi + 1, yi) == BOT_THINKING)
			printf("│ 🟠 ");
		else if (GRID_AT(grid, xi + 1, yi) == PLAYER_THINKING)
			printf("│ 🟣 ");
		else 
			printf("│ ⚠️ ");
	}
	printf("┃\n");
}

static inline void	display_endline(unsigned int width)
{
	printf("┗━━━━");
	for (unsigned int xi = 0; xi < width; xi++)
		printf("┷━━━━");
	printf("┛\n");
}

void	display_grid(t_grid *grid)
{
	printf("\033[2J\033[H");
	for (unsigned int yi = 0; yi < grid->height; yi++)
	{
		display_delimitation(yi, grid->width - 1);
		display_line(grid, grid->height - yi - 1);
	}
	display_endline(grid->width - 1);
}
