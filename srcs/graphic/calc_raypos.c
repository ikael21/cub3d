/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_raypos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:13:35 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 20:13:37 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_raypos(t_data *data)
{
	data->ray.x = data->player.posx + data->ray.distance * cos(data->ray.angle);
	data->ray.y = data->player.posy + data->ray.distance * sin(data->ray.angle);
}
