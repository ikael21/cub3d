/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:39:24 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 22:39:26 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move(t_data *data)
{
	if (data->player.keys.w == 1)
		walk_forward(data);
	if (data->player.keys.s == 1)
		walk_backward(data);
	if (data->player.keys.a == 1)
		strafe_left(data);
	if (data->player.keys.d == 1)
		strafe_right(data);
	if (data->player.keys.left == 1)
		turn_left(data);
	if (data->player.keys.right == 1)
		turn_right(data);
	return (1);
}
