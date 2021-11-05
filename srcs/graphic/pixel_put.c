/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:04:41 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 20:04:43 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->next.addr
		+ (y * data->next.line_length + x * (data->next.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
