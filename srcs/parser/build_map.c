/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:31:52 by ikael             #+#    #+#             */
/*   Updated: 2021/11/03 18:32:29 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_spaces_line(size_t len)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line[len] = '\0';
	line = ft_memset(line, ' ', len);
	return (line);
}

static char	*get_map_line(char *map_line, size_t len)
{
	char	*line;
	size_t	i;

	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line[len] = '\0';
	line[0] = ' ';
	i = 0;
	while (i < ft_strlen(map_line))
	{
		line[i + 1] = map_line[i];
		i++;
	}
	while (++i < len)
		line[i] = ' ';
	return (line);
}

static int	copy_map(char **map, t_list *head, size_t map_size)
{
	size_t	i;
	size_t	len;

	len = get_longest_line(head);
	i = 0;
	while (i < map_size)
	{
		if (!i || i + 1 == map_size)
			map[i] = get_spaces_line(len + 2);
		else
		{
			map[i] = get_map_line((char *)head->content, len + 2);
			head = head->next;
		}
		if (!map[i])
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static void	init_player(t_data *data)
{
	int	i;
	int	j;
	char	**map;

	map = data->map.map;
	data->map.width = ft_strlen(map[0]);
	i = 0;
	while (map[i])
		i++;
	data->map.height = i;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				data->player.direct_view = map[i][j];
				data->player.posx = (double)j;
				data->player.posy = (double)i;
			}
		}
	}
}

int	build_map(t_data *data, t_list *head)
{
	size_t	map_size;

	if (check_map(head) == FAIL)
		return (FAIL);
	map_size = get_map_size(head);
	data->map.map = (char **)malloc(sizeof(char *) * (map_size + 3));
	if (!data->map.map)
		return (FAIL);
	data->map.map[map_size + 2] = NULL;
	if (copy_map(data->map.map, head, map_size + 2) == FAIL)
		return (FAIL);
	if (is_map_closed(data->map.map) == FAIL)
		return (FAIL);
	init_player(data);
	return (SUCCESS);
}
