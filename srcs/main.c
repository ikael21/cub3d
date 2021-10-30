/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 11:09:13 by ikael             #+#    #+#             */
/*   Updated: 2021/10/30 21:52:52 by ikael            ###   ########.fr       */
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

	// if (argc != 2)
	// 	return (usage());
	game_int(&data);
	if (parser(&data, argv[1]) == FAIL)
		return (1);
	/* обрабатывается в парсере от сюда*/
	data.map.height = 10;
	data.map.width = 10;
	data.map.map = (char **)malloc(sizeof(char *) * 11);
	data.map.map[0] = "1111111111";
	data.map.map[1] = "1000000001";
	data.map.map[2] = "1011111101";
	data.map.map[3] = "1010000101";
	data.map.map[4] = "1010110101";
	data.map.map[5] = "1010100101";
	data.map.map[6] = "101010N101";
	data.map.map[7] = "1010111101";
	data.map.map[8] = "1010000001";
	data.map.map[9] = "1111111111";
	data.map.map[10] = NULL;
	data.player.posx = 6 * SIZE + SIZE/2;
	data.player.posy = 6 * SIZE + SIZE/2;
	data.player.angle = dtr(270);
	/* до сюда */
	mlx_hook(data.win, 2, 1L<<0, key_hook_press, &data);
	mlx_hook(data.win, 3, 1L<<1, key_hook_release, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
}
