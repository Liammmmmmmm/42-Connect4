
#include <math.h>
#include "connect4.h"

static int score_window(int countIA, int countADV /*int countEmpty*/)
{
	if (countIA > 0 && countADV > 0) return 0;
	if (countIA == N_ALIGN) return INFINITY;    // victoire IA
	if (countADV == N_ALIGN) return -INFINITY;  // victoire ADV
	if (countIA > 0) return 10 * (int)pow(10, countIA - 1);
	if (countADV > 0) return -10 * (int)pow(10, countADV - 1);
	return 0;
}

int evaluate_board(t_grid *grid)
{
	int score = 0;

	// Horizontales
	for (unsigned int y = 0; y < grid->height; y++)
	{
		for (unsigned int x = 0; x <= grid->width - N_ALIGN; x++)
		{
			int countIA = 0, countADV = 0, countEmpty = 0;
			for (int k = 0; k < N_ALIGN; k++)
			{
				if (GRID_AT(grid, x+k, y) == BOT) countIA++;
				else if (GRID_AT(grid, x+k, y) == PLAYER) countADV++;
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
				if (GRID_AT(grid, x, y+k) == BOT) countIA++;
				else if (GRID_AT(grid, x, y+k) == PLAYER) countADV++;
				else countEmpty++;
			}
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
				if (GRID_AT(grid, x+k, y+k) == BOT) countIA++;
				else if (GRID_AT(grid, x+k, y+k) == PLAYER) countADV++;
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
				if (GRID_AT(grid, x-k, y+k) == BOT) countIA++;
				else if (GRID_AT(grid, x-k, y+k) == PLAYER) countADV++;
				else countEmpty++;
			}
			score += score_window(countIA, countADV /*countEmpty*/);
		}
	}

	return score;
}
