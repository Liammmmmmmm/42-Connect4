#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "connect4.h"

#define MAX 100

static int is_column_full(t_grid *grid, int col)
{
	return grid->height == (unsigned int)grid->level[col];
}

static int get_available_row(t_grid *grid, int col)
{
	for (int row = grid->height - 1 ; row >= 0 ; row--)
	{
		if (GRID_AT(grid, row, col) == EMPTY)
			return row;
	}
	return -1;
}

static float minimax(t_grid *grid, int depth, int alpha, int beta, int maximizingPlayer, int width, int height)
{
	if (depth == 0)
		return evaluate_board(grid);

	if (maximizingPlayer)
	{
		int maxEval = -MAX;
		for (int col = 0 ; col < width ; col++)
		{
			if (is_column_full(grid, col)) continue;

			int row = get_available_row(grid, col);
			GRID_AT(grid, row, col) = BOT;

			int eval = minimax(grid, depth - 1, alpha, beta, 0, width, height);

			GRID_AT(grid, row, col) = EMPTY;

			maxEval = fmax(maxEval, eval);
			alpha = fmax(alpha, eval);

			if (beta <= alpha)
				break;
		}
		return maxEval;
	}
	else
	{
		int minEval = MAX;
		for (int col = 0 ; col < width ; col++)
		{
			if (is_column_full(grid, col)) continue;

			int row = get_available_row(grid, col);
			GRID_AT(grid, row, col) = PLAYER;

			int eval = minimax(grid, depth - 1, alpha, beta, 1, width, height);

			GRID_AT(grid, row, col) = EMPTY;

			minEval = fmin(minEval, eval);
			beta = fmin(beta, eval);

			if (beta <= alpha)
				break;
		}
		return minEval;
	}
}
		#include <stdio.h>

int find_best_move(t_grid *grid, int width, int height, int depth)
{
	int bestMove = -1;
	float maxEval = -INFINITY;

	for (int col = 0 ; col < width ; col++)
	{
		if (is_column_full(grid, col)) continue;

		int row = get_available_row(grid, col);
		GRID_AT(grid, row, col) = BOT;

		float eval = minimax(grid, depth - 1, -MAX, MAX, 0, width, height);

		GRID_AT(grid, row, col) = EMPTY;

		printf("%f %f", eval, maxEval);

		if (eval > maxEval)
		{
			maxEval = eval;
			bestMove = col;
		}
	}

	return bestMove;
}
