/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_ids.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:27:23 by ikael             #+#    #+#             */
/*   Updated: 2021/11/02 02:30:47 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	gnl_sucks(int map_fd)
{
	char	*line;
	int		ret;

	ret = get_next_line(map_fd, &line);
	while (ret > 0)
	{
		free(line);
		ret = get_next_line(map_fd, &line);
	}
	free(line);
	if (ret == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	check_format(const char *map_path)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (len)
		len--;
	while (len && map_path[len] != '.')
		len--;
	if (!ft_strcmp(map_path + len + 1, "cub"))
		return (SUCCESS);
	return (FAIL);
}

static int	get_one_id(t_data *data, char *line)
{
	char	**ln_parts;
	int		ret;

	ln_parts = ft_split(line, ' ');
	if (!ln_parts)
		return (FAIL);
	ret = parse_identifiers(data, ln_parts);
	free_str_arr(ln_parts);
	return (ret);
}

static int	read_from_file(t_data *data, int map_fd)
{
	char	*line;
	int		ret;

	ret = get_next_line(map_fd, &line);
	if (ret == -1)
		return (FAIL);
	while (ret > 0 && !is_map_started(line))
	{
		if (ft_strcmp(line, "") != 0)
		{
			ret = get_one_id(data, line);
			free(line);
			if (ret == FAIL)
				return (FAIL);
		}
		else
			free(line);
		ret = get_next_line(map_fd, &line);
	}
	if (ret == FAIL)
		return (FAIL);
	if (ft_strcmp(line, "") != 0 && !is_map_started(line))
		ret = get_one_id(data, line);
	free(line);
	return (ret);
}

int	get_map_identifiers(t_data *data, const char *map_path)
{
	int	map_fd;
	int	ret;

	if (check_format(map_path) == FAIL)
		return (FAIL);
	map_fd = open(map_path, O_RDONLY);
	ret = read_from_file(data, map_fd);
	if (ret == FAIL || !data->textures.east.img
		|| !data->textures.west.img || !data->textures.north.img
		|| !data->textures.south.img || data->map.c_color == -1
		|| data->map.f_color == -1)
	{
		close(map_fd);
		return (FAIL);
	}
	ret = gnl_sucks(map_fd);
	close(map_fd);
	if (ret == FAIL)
		return (FAIL);
	return (SUCCESS);
}
