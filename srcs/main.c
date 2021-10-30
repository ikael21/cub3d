/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 11:09:13 by ikael             #+#    #+#             */
/*   Updated: 2021/10/29 13:33:59 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
}

static int	usage(void)
{
	/*
		print how to use the binary
	*/
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		parser_res;

	if (argc != 2)
		return (usage());
	game_int(&data);

	parser_res = parser(&data, argv[1]);
	printf("parsing result: ");
	(parser_res == FAIL) ? printf("FAIL\n") : printf("SUCCESS\n");
	printf("f-color: %X\n", data.map.f_color);
	printf("c-color: %X\n", data.map.c_color);
	printf("no_texture: %p  %s\n", data.textures.north.img, data.textures.north.path);
	printf("so_texture: %p  %s\n", data.textures.south.img, data.textures.south.path);
	printf("ea_texture: %p  %s\n", data.textures.east.img, data.textures.east.path);
	printf("we_texture: %p  %s\n", data.textures.west.img, data.textures.west.path);

	// mlx_hook(data.win, 2, 1L<<0, key_hook_press, &data);
	// mlx_hook(data.win, 3, 1L<<1, key_hook_release, &data);
	// mlx_loop_hook(data.mlx, render, &data);
	// mlx_loop(data.mlx);
}
