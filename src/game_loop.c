#include <stdio.h>
#include <stdlib.h>

#include "../libft/include/libft.h"

int is_numeric(const char *str)
{
    if (*str == '\0') return 0;

    for (int i = 0; str[i]; i++)
	{
        if (!ft_isdigit(str[i])) return 0;
	}

	return 1;
}

int read_valid_column(int columns, int *grid_heights, int grid_height)
{
	char *buffer = NULL;
	int col;

	while (1)
	{
		ft_printf("Choose a column (1 to %d): ", columns);

		buffer = get_next_line(0);

		if (buffer == NULL) {
			ft_printf("Read error.\n");
			continue;
		}

		size_t len = ft_strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		if (!is_numeric(buffer))
		{
			ft_printf("Invalid input: please enter a number.\n");
			free(buffer);
			continue;
		}

		col = ft_atoi(buffer);
		free(buffer);

		if (col <= 0 || col > columns)
		{
			ft_printf("Invalid column: out of bounds.\n");
			continue;
		}

		if (grid_heights[col - 1] >= grid_height)
		{
			ft_printf("Column full. Choose another one.\n");
			continue;
		}

		return col;
	}
}
