/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:26:24 by ikael             #+#    #+#             */
/*   Updated: 2021/10/27 22:54:54 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const char	*g_identifiers[] =
{
	"NO", "SO",
	"WE", "EA",
	"F", "C"
};

const int8_t	g_identifiers_size = 6;

static int	rgb_to_hex(int red, int green, int blue)
{
	return ((((red * 256) + green) * 256) + blue);
}

static int	get_color(char *color_part)
{
	int		i;
	int		j;
	char	**rgb;

	rgb = ft_split(color_part, ',');
	i = -1;
	while (rgb[++i])
	{
		j = -1;
		while (++j < ft_strlen(rgb[i]))
			if (!ft_isdigit(rgb[i][j]))
				return (FAIL);
	}
	if (i != 3)
		return (FAIL);
	if (ft_atoi(rgb[0]) == -1 || ft_atoi(rgb[1]) == -1
		|| ft_atoi(rgb[2]) == -1)
		return (FAIL);
	return (rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2])));
}

static int	init_identifier(t_data *data, char **ln_prt, int8_t iter)
{
	t_texture	*texture;
	int			color;

	color = 0;
	texture = NULL;
	if (!iter)
		texture = &data->textures.north;
	else if (iter == 1)
		texture = &data->textures.south;
	else if (iter == 2)
		texture = &data->textures.west;
	else if (iter == 3)
		texture = &data->textures.east;
	else if (iter == 4 || iter == 5)
		color = get_color(ln_prt[1]);
	/*
		get_texture
	*/
}

int	parse_identifiers(t_data *data, char **ln_prt)
{
	int		i;
	int8_t	j;

	i = 0;
	while (ln_prt[i])
		i++;
	if (i != 2)
		return (FAIL);
	j = -1;
	while (++j < g_identifiers_size)
		if (!ft_strcmp(g_identifiers[j], ln_prt[0]))
			break ;
	if (j == g_identifiers_size)
		return (FAIL);
	return (init_identifier(data, ln_prt, j));
}
