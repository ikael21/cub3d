/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:27:23 by ikael             #+#    #+#             */
/*   Updated: 2021/10/27 15:14:35 by ikael            ###   ########.fr       */
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

	ln_prt = ft_split(line, ' ');
	if (!ln_prt)
		return (FAIL);
	if (!ft_strcmp(ln_prt[0], "NO") || !ft_strcmp(ln_prt[0], "SO")
		|| !ft_strcmp(ln_prt[0], "WE") || !ft_strcmp(ln_prt[0], "EA")
		|| !ft_strcmp(ln_prt[0], "F") || !ft_strcmp(ln_prt[0], "C"))
		ret = parse_identifiers(data, ln_prt);
	else
		ret = parse_map(data, line);
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
		if (!ft_strcmp(line, ""))
		{
			free(line);
			gnl_ret = get_next_line(map_fd, &line);
			continue ;
		}
		if (parse_line(data, line) == FAIL)
			return (FAIL);
		gnl_ret = get_next_line(map_fd, &line);
	}
}

int	parser(t_data *data, char *map_path)
{
	ssize_t	bytes_read;
	int		map_fd;

	if (check_format(map_path))
		return (FAIL);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (FAIL);
	return (read_map_data(data, map_fd));
}
