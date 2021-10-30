/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:27:23 by ikael             #+#    #+#             */
/*   Updated: 2021/10/30 21:32:16 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_format(char *map_path)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (len)
		len--;
	while (len && map_path[len] != '.')
		len--;
	if (ft_strcmp(map_path + len + 1, "cub") != 0)
		return (FAIL);
	return (SUCCESS);
}

static int	parse_line(t_data *data, char *line)
{
	char	**ln_prt;
	int		ret;

	ret = FAIL;
	ln_prt = ft_split(line, ' ');
	if (!ln_prt)
		return (FAIL);
	if (!ft_strcmp(ln_prt[0], "NO") || !ft_strcmp(ln_prt[0], "SO")
		|| !ft_strcmp(ln_prt[0], "WE") || !ft_strcmp(ln_prt[0], "EA")
		|| !ft_strcmp(ln_prt[0], "F") || !ft_strcmp(ln_prt[0], "C"))
		ret = parse_identifiers(data, ln_prt);
	// else
	// 	ret = get_map_line(data, line);
	free_str_arr(ln_prt);
	free(line);
	return (ret);
}

static int	read_map_data(t_data *data, int map_fd)
{
	char	*line;
	int		gnl_ret;

	gnl_ret = get_next_line(map_fd, &line);
	while (gnl_ret && gnl_ret != -1)
	{
		if (parse_line(data, line) == FAIL)
			return (FAIL);
		gnl_ret = get_next_line(map_fd, &line);
	}
	if (gnl_ret == -1 || !data->textures.east.img || !data->textures.west.img
		|| !data->textures.south.img || !data->textures.north.img
		|| data->map.f_color == -1 || data->map.c_color == -1)
		return (FAIL);
	return (SUCCESS);
}

int	parser(t_data *data, char *map_path)
{
	int		map_fd;
	int		ret;

	if (check_format(map_path))
		return (FAIL);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (FAIL);
	ret = read_map_data(data, map_fd);
	close(map_fd);
	return (ret);
}
