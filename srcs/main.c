/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 11:09:13 by ikael             #+#    #+#             */
/*   Updated: 2021/10/27 15:39:14 by ikael            ###   ########.fr       */
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
	t_data data;

	if (argc != 2)
		return (usage());
	game_int(&data);

	
	// mlx_hook(data.win, 2, 1L<<0, key_hook_press, &data);
	// mlx_hook(data.win, 3, 1L<<1, key_hook_release, &data);
	// mlx_loop_hook(data.mlx, render, &data);
	// mlx_loop(data.mlx);
}
