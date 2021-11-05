/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:40:34 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 22:40:35 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_data *data)
{
	if (data->player.angle < dtr(360.0))
		data->player.angle += dtr(ROT_SPEED);
	if (data->player.angle > dtr(359.0))
		data->player.angle = dtr(0.0);
}
