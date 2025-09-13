
#include <math.h>
#include "connect4.h"

int score_window(int countIA, int countADV, int countEmpty)
{
	if (countIA > 0 && countADV > 0) return 0;
	if (countIA == N_ALIGN) return INFINITY;    // victoire IA
	if (countADV == N_ALIGN) return -INFINITY;  // victoire ADV
	if (countIA > 0) return 10 * (int)pow(10, countIA - 1);
	if (countADV > 0) return -10 * (int)pow(10, countADV - 1);
	return 0;
}

int evaluate_board(t_grid grid, int width, int height)
{
	int score = 0;

	// Horizontales
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x <= width - N_ALIGN; x++)
		{
			int countIA = 0, countADV = 0, countEmpty = 0;
			for (int k = 0; k < N_ALIGN; k++)
			{
				if (GRID_AT(grid, x+k, y) == BOT) countIA++;
				else if (GRID_AT(grid, x+k, y) == PLAYER) countADV++;
				else countEmpty++;
			}
			score += score_window(countIA, countADV, countEmpty);
		}
	}

	// Verticales
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y <= height - N_ALIGN; y++)
		{
			int countIA = 0, countADV = 0, countEmpty = 0;
			for (int k = 0; k < N_ALIGN; k++)
			{
				if (GRID_AT(grid, x, y+k) == BOT) countIA++;
				else if (GRID_AT(grid, x, y+k) == PLAYER) countADV++;
				else countEmpty++;
			}
			score += score_window(countIA, countADV, countEmpty);
		}
	}

	// Diagonale ╲
	for (int y = 0; y <= height - N_ALIGN; y++)
	{
		for (int x = 0; x <= width - N_ALIGN; x++)
		{
			int countIA = 0, countADV = 0, countEmpty = 0;
			for (int k = 0; k < N_ALIGN; k++)
			{
				if (GRID_AT(grid, x+k, y+k) == BOT) countIA++;
				else if (GRID_AT(grid, x+k, y+k) == PLAYER) countADV++;
				else countEmpty++;
			}
			score += score_window(countIA, countADV, countEmpty);
		}
	}

	// Diagonale ╱
	for (int y = 0; y <= height - N_ALIGN; y++)
	{
		for (int x = N_ALIGN - 1; x < width; x++)
		{
			int countIA = 0, countADV = 0, countEmpty = 0;
			for (int k = 0; k < N_ALIGN; k++)
			{
				if (GRID_AT(grid, x-k, y+k) == BOT) countIA++;
				else if (GRID_AT(grid, x-k, y+k) == PLAYER) countADV++;
				else countEmpty++;
			}
			score += score_window(countIA, countADV, countEmpty);
		}
	}

	return score;
}
