/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_started.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:57:42 by ikael             #+#    #+#             */
/*   Updated: 2021/10/31 19:01:04 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_started(char *line)
{
	int		i;
	int8_t	is_ones;

	is_ones = 0;
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '1'))
	{
		if (line[i] == '1')
			is_ones = 1;
		i++;
	}
	if (!line[i] && is_ones)
		return (1);
	return (0);
}
