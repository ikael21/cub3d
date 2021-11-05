/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:40:25 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 22:40:26 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_data *data)
{
	if (data->player.angle >= dtr(0.0))
		data->player.angle -= dtr(ROT_SPEED);
	if (data->player.angle < dtr(0.0))
		data->player.angle = dtr(359.0);
}
