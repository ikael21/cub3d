#include "cub3d.h"

void close_game(void)
{
	exit(EXIT_SUCCESS);
}

int	close_window(void *params)
{
	(void)params;
	close_game();
	return (EXIT_SUCCESS);
}
