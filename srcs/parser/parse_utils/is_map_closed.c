/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 03:54:36 by ikael             #+#    #+#             */
/*   Updated: 2021/11/05 03:33:10 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_needed_char(char c)
{
	uint8_t			i;
	const uint8_t	map_ids_size = 5;
	const char		map_ids[] = {
		'0', 'N', 'S', 'W', 'E'
	};

	i = 0;
	while (i < map_ids_size)
	{
		if (map_ids[i] == c)
			return (SUCCESS);
		i++;
	}
	return (FAIL);
}

int	is_map_closed(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (!is_needed_char(map[i][j]) && (map[i][j + 1] == ' '
					|| map[i][j - 1] == ' ' || map[i + 1][j] == ' '
					|| map[i - 1][j] == ' ' || map[i + 1][j + 1] == ' '
					|| map[i + 1][j - 1] == ' ' || map[i - 1][j - 1] == ' '
					|| map[i - 1][j + 1] == ' '))
				return (FAIL);
	}
	return (SUCCESS);
}
