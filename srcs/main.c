/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 11:09:13 by ikael             #+#    #+#             */
/*   Updated: 2021/11/05 22:35:47 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_set(t_data *data)
{
	data->player.posx = data->player.posx * SIZE + SIZE / 2;
	data->player.posy = data->player.posy * SIZE + SIZE / 2;
	if (data->player.direct_view == 'E')
		data->player.angle = dtr(0);
	else if (data->player.direct_view == 'S')
		data->player.angle = dtr(90);
	else if (data->player.direct_view == 'W')
		data->player.angle = dtr(180);
	else if (data->player.direct_view == 'N')
		data->player.angle = dtr(270);
}

static void	game_int(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	data->img.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->player.keys.w = 0;
	data->player.keys.a = 0;
	data->player.keys.s = 0;
	data->player.keys.d = 0;
	data->player.keys.left = 0;
	data->player.keys.right = 0;
	data->textures.east.img = NULL;
	data->textures.west.img = NULL;
	data->textures.north.img = NULL;
	data->textures.south.img = NULL;
	data->map.f_color = -1;
	data->map.c_color = -1;
	data->map.map = NULL;
	data->delta_a = FOW / W_WIDTH;
	data->h_fow = FOW / 2;
	data->focus = (W_WIDTH / 2) * tan(dtr(data->h_fow));
}

static int	usage(void)
{
	printf(YELLOW "%s%s\n" RESET,
		"USAGE: ", "./cub3D [path to map]");
	printf(RED"!" YELLOW " Map format should be" MAGENTA " cub\n" RESET);
	return (EXIT_SUCCESS);
}

static int	print_error(char *str, char *path_map)
{
	printf(RED "%s\n" YELLOW "- %2s in " MAGENTA "%s" YELLOW " file!\n" RESET,
		"ERROR!", str, path_map);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (usage());
	game_int(&data);
	if (get_map_identifiers(&data, argv[1]) == FAIL)
		return (print_error("invalid identifiers", argv[1]));
	if (get_map(&data, argv[1]) == FAIL)
		return (print_error("invalid map", argv[1]));
	player_set(&data);
	mlx_hook(data.win, 2, 1L << 0, key_hook_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_hook_release, &data);
	mlx_hook(data.win, 17, 0, close_window, NULL);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
}
