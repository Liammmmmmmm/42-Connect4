#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "connect4.h"

#define N_ALIGN 4
#define MAX 100
#define BOT 'X'
#define PLAYER 'O'

int is_column_full(test_grid grid, int col)
{
    return grid.grid[0][col] != ' ';
}

int get_available_row(test_grid grid, int col)
{
    for (int row = grid.height - 1; row >= 0; row--)
	{
        if (grid.grid[row][col] == ' ')
            return row;
    }
    return -1;
}

int minimax(test_grid grid, int depth, int alpha, int beta, int maximizingPlayer, int width, int height)
{
    if (depth == 0 || game_over(grid, width, height))
        return evaluate_board(grid, width, height);

    if (maximizingPlayer)
	{
        int maxEval = -MAX;
        for (int col = 0; col < width; col++)
		{
            if (is_column_full(grid, col)) continue;

            int row = get_available_row(grid, col);
            grid.grid[row][col] = BOT;

            int eval = minimax(grid, depth - 1, alpha, beta, 0, width, height);

            grid.grid[row][col] = ' ';

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
        for (int col = 0; col < width; col++)
		{
            if (is_column_full(grid, col)) continue;

            int row = get_available_row(grid, col);
            grid.grid[row][col] = PLAYER;

            int eval = minimax(grid, depth - 1, alpha, beta, 1, width, height);

            grid.grid[row][col] = ' ';

            minEval = fmin(minEval, eval);
            beta = fmin(beta, eval);

            if (beta <= alpha)
                break;
        }
        return minEval;
    }
}

int find_best_move(test_grid grid, int width, int height, int depth)
{
    int bestMove = -1;
    int maxEval = -MAX;

    for (int col = 0; col < width; col++)
	{
        if (is_column_full(grid, col)) continue;

        int row = get_available_row(grid, col);
        grid.grid[row][col] = BOT;

        int eval = minimax(grid, depth - 1, -MAX, MAX, 0, width, height);

        grid.grid[row][col] = ' ';

        if (eval > maxEval)
		{
            maxEval = eval;
            bestMove = col;
        }
    }

    return bestMove;
}

int game_over(test_grid grid, int width, int height)
{
    return 0;
}
