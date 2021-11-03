/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:26:24 by ikael             #+#    #+#             */
/*   Updated: 2021/11/02 21:08:40 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color(char *color_part)
{
	int		i;
	char	**rgb;

	rgb = ft_split(color_part, ',');
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
	{
		free_str_arr(rgb);
		return (FAIL);
	}
	if (ft_atoi(rgb[0]) == -1 || ft_atoi(rgb[1]) == -1
		|| ft_atoi(rgb[2]) == -1)
	{
		free_str_arr(rgb);
		return (FAIL);
	}
	i = rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_str_arr(rgb);
	return (i);
}

static int	get_texture(void *mlx,
						t_texture *texture,
						char *texture_path)
{
	if (texture->img)
		return (FAIL);
	texture->img = mlx_xpm_file_to_image(mlx, texture_path,
			&texture->width, &texture->height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, &texture->ll, &texture->end);
	if (!texture->img)
		return (FAIL);
	return (SUCCESS);
}

static int	init_identifier(t_data *data,
							char **ln_prt,
							const uint8_t iter)
{
	int				color;
	const t_texture	*texture[] = {
		&data->textures.north, &data->textures.south,
		&data->textures.west, &data->textures.east
	};

	color = 0;
	if (iter < 4)
		if (get_texture(data->mlx,
				(t_texture *)texture[iter], ln_prt[1]) == FAIL)
			return (FAIL);
	if (iter == 4 || iter == 5)
		color = get_color(ln_prt[1]);
	if ((iter == 4 || iter == 5) && color == -1)
		return (FAIL);
	if (iter == 4)
		data->map.f_color = color;
	if (iter == 5)
		data->map.c_color = color;
	return (SUCCESS);
}

int	parse_identifiers(t_data *data, char **ln_prt)
{
	unsigned int	i;
	uint8_t			j;
	const uint8_t	ids_size = 6;
	const char		*identifiers[] = {
		"NO", "SO", "WE", "EA", "F", "C"
	};

	i = 0;
	while (ln_prt[i])
		i++;
	if (i != 2)
		return (FAIL);
	j = 0;
	while (j < ids_size)
	{
		if (!ft_strcmp(identifiers[j], ln_prt[0]))
			break ;
		j++;
	}
	if (j == ids_size)
		return (FAIL);
	return (init_identifier(data, ln_prt, j));
}
