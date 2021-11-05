/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:22:31 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 22:22:34 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	select_color(t_data *data, double tex_posy, char direct)
{
	int	tex_posx;

	tex_posx = 0;
	if (direct == 'h')
		tex_posx = ((int)(data->ray.x
					- ((int)(data->ray.x / SIZE) *SIZE))) / 2;
	else if (direct == 'v')
		tex_posx = ((int)(data->ray.y
					- ((int)(data->ray.y / SIZE) *SIZE))) / 2;
	return (*(int *)(data->ray.texture.addr
		+ (int)tex_posy * data->ray.texture.ll
		+ tex_posx * (data->ray.texture.bpp / 8)));
}
