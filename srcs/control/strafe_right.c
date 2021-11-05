/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strafe_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:40:11 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 22:40:13 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	strafe_right(t_data *data)
{
	data->player.posx -= WALK_SPEED * sin(data->player.angle);
	data->player.posy += WALK_SPEED * cos(data->player.angle);
}
