/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:09:25 by ikael             #+#    #+#             */
/*   Updated: 2021/11/02 08:09:40 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_extra(const unsigned char c)
{
	int8_t				i;
	const int8_t		map_ids_size = 7;
	const unsigned char	map_ids[] =
	{
		' ', '0', '1', 'N', 'S', 'E', 'W'
	};

	i = -1;
	while (++i < map_ids_size)
		if (map_ids[i] == c)
			return (SUCCESS);
	return (FAIL);
}
