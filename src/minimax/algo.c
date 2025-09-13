#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "connect4.h"
#include "libft.h"

#define MAX 100

static double ft_fmax(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

static double ft_fmin(double a, double b)
{
	if (a < b)
		return a;
	else
		return b;
}

static int is_column_full(t_grid *grid, int col)
{
	return grid->height == (unsigned int)grid->level[col];
}

#include "libft.h"
void	display_debug_grid(t_grid *grid)
{
	ft_printf("%u:%u\n", grid->width, grid->height);
	ft_printf("%d %d %d %d %d %d %d %d\n", grid->level[0], grid->level[1], grid->level[2], grid->level[3], grid->level[4], grid->level[5], grid->level[6], grid->level[7]);
	for (int i = grid->height - 1; i >= 0; i--)
	{
		for (unsigned int j = 0; j < grid->width; j++)
		{
			ft_printf("%d", GRID_AT(grid, j, i));
		}
		ft_printf("\n");
	}
}

static float minimax(t_grid *grid, int depth, float alpha, float beta, int maximizingPlayer, int width, int height)
{
	if (depth == 0 || alpha == INFINITY || beta == -INFINITY)
		return evaluate_board(grid);

	if (maximizingPlayer)
	{
		float minEval = INFINITY;
		for (int col = 0 ; col < width ; col++)
		{
			if (is_column_full(grid, col)) continue;
	
			int row = grid->level[col];
			grid->level[col]++;
			GRID_AT(grid, col, row) = PLAYER;
			
			if (evaluate_board(grid) == INFINITY)
			{
				grid->level[col]--;
				GRID_AT(grid, col, row) = EMPTY;
				return INFINITY;
			}

			float eval = minimax(grid, depth - 1, alpha, beta, 0, width, height);
	
			grid->level[col]--;
			GRID_AT(grid, col, row) = EMPTY;
	
			minEval = ft_fmin(minEval, eval);
			beta = ft_fmin(beta, eval);
	
			if (beta <= alpha)
				break;
		}
		return minEval;
	}
	else
	{
		float maxEval = -INFINITY;
		for (int col = 0 ; col < width ; col++)
		{
			if (is_column_full(grid, col)) continue;
	
			int row = grid->level[col];
			grid->level[col]++;
			GRID_AT(grid, col, row) = BOT;
	
			if (evaluate_board(grid) == -INFINITY)
			{
				grid->level[col]--;
				GRID_AT(grid, col, row) = EMPTY;
				return -INFINITY;
			}
	
			float eval = minimax(grid, depth - 1, alpha, beta, 1, width, height);
	
			grid->level[col]--;
			GRID_AT(grid, col, row) = EMPTY;
			maxEval = ft_fmax(maxEval, eval);
			alpha = ft_fmax(alpha, eval);
	
			if (beta <= alpha)
				break;
		}
		return maxEval;
	}
}

int find_best_move(t_grid *grid, int width, int height, int depth)
{
	int bestMove = -1;
	float maxEval = -INFINITY;

	for (int col = 0 ; col < width ; col++)
	{
		if (is_column_full(grid, col)) continue;
		
		int row = grid->level[col];
		grid->level[col]++;
		GRID_AT(grid, col, row) = BOT;
		float eval = minimax(grid, depth - 1, -INFINITY, INFINITY, 1, width, height);
		grid->level[col]--;
		GRID_AT(grid, col, row) = EMPTY;
		printf("Col %d: eval %f\n",col, eval);
		
		if (eval > maxEval)
		{
			maxEval = eval;
			bestMove = col;
		}
	}

	// Ajouter une secu : si -1 prendre du random jsuqu'a tomber sur une col vide

	return bestMove;
}
