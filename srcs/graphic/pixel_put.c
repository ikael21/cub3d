#include "cub3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->next.addr + (y * data->next.line_length + x * (data->next.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}