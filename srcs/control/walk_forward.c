/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:40:55 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 22:40:59 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walk_forward(t_data *data)
{
	data->player.posx += WALK_SPEED * cos(data->player.angle);
	data->player.posy += WALK_SPEED * sin(data->player.angle);
}
