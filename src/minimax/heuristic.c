
#include <math.h>
#include <unistd.h>
#include "connect4.h"
#include "libft.h"

static float score_window(int countIA, int countADV /*int countEmpty*/)
{
	if (countIA == N_ALIGN) {
		// ft_printf("countIA : %d\n", countIA);
		// display_grid(g_game);
		return INFINITY;
	}    // victoire IA
	if (countADV == N_ALIGN) {
		// ft_printf("countADV : %d\n", countADV);
		// display_grid(g_game);
		return -INFINITY;
	}  // victoire ADV
	float ret = 0;
	if (countIA > 0) ret += 10 * (int)pow(10, countIA - 1);
	if (countADV > 0) ret += -10 * (int)pow(10, countADV - 1);
	return ret;
}
#include <stdio.h>
float evaluate_board(t_grid *grid)
{
	float score = 0;

	# if COOLNESS
	usleep(10000);
	display_grid(grid);
	# endif
	// Horizontales
	for (unsigned int y = 0; y < grid->height; y++)
	{
		for (unsigned int x = 0; x <= grid->width - N_ALIGN; x++)
		{
			int countIA = 0, countADV = 0, countEmpty = 0;
			for (int k = 0; k < N_ALIGN; k++)
			{
				if (GRID_AT(grid, x+k, y)  < 0) countIA++;
				else if (GRID_AT(grid, x+k, y) > 0) countADV++;
				else countEmpty++;
			}
			score += score_window(countIA, countADV /*countEmpty*/);
		}
	}

	// Verticales
	for (unsigned int x = 0; x < grid->width; x++)
	{
		for (unsigned int y = 0; y <= grid->height - N_ALIGN; y++)
		{
			int countIA = 0, countADV = 0, countEmpty = 0;
			for (int k = 0; k < N_ALIGN; k++)
			{
				if (GRID_AT(grid, x, y+k) < 0) countIA++;
				else if (GRID_AT(grid, x, y+k) > 0) countADV++;
				else countEmpty++;
				// ft_printf("%u %u -> %d\n", x, y+k, GRID_AT(grid, x, y+k));
			}
			// printf("%u %u: %d %d\n", x, y, countADV, countIA);
			score += score_window(countIA, countADV /*countEmpty*/);
		}
	}

	// Diagonale ╲
	for (unsigned int y = 0; y <= grid->height - N_ALIGN; y++)
	{
		for (unsigned int x = 0; x <= grid->width - N_ALIGN; x++)
		{
			int countIA = 0, countADV = 0, countEmpty = 0;
			for (int k = 0; k < N_ALIGN; k++)
			{
				if (GRID_AT(grid, x+k, y+k) < 0) countIA++;
				else if (GRID_AT(grid, x+k, y+k) > 0) countADV++;
				else countEmpty++;
			}
			score += score_window(countIA, countADV /*countEmpty*/);
		}
	}

	// Diagonale ╱
	for (unsigned int y = 0; y <= grid->height - N_ALIGN; y++)
	{
		for (unsigned int x = N_ALIGN - 1; x < grid->width; x++)
		{
			int countIA = 0, countADV = 0, countEmpty = 0;
			for (int k = 0; k < N_ALIGN; k++)
			{
				if (GRID_AT(grid, x-k, y+k) < 0) countIA++;
				else if (GRID_AT(grid, x-k, y+k) > 0) countADV++;
				else countEmpty++;
			}
			score += score_window(countIA, countADV /*countEmpty*/);
		}
	}

	return score;
}
