/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:39:15 by ikael             #+#    #+#             */
/*   Updated: 2021/11/05 03:30:39 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*fucked_up_clear(t_list **head, char *str)
{
	if (head)
		ft_lstclear(head, free);
	if (str)
		free(str);
	return (NULL);
}

static int	save_line(t_list **head, char *line)
{
	t_list	*new;

	new = ft_lstnew(line);
	if (new == NULL)
		return (FAIL);
	ft_lstadd_back(head, new);
	return (SUCCESS);
}

static t_list	*read_map(int map_fd, char *last_line)
{
	t_list	*head;
	char	*line;
	int		ret;
	int		ret1;

	head = NULL;
	ret1 = 1;
	if (save_line(&head, last_line) == FAIL)
		ret1 = FAIL;
	ret = get_next_line(map_fd, &line);
	while (ret > 0 && ret1 > 0)
	{
		if (save_line(&head, line) == FAIL)
			ret1 = FAIL;
		if (ret1 > 0)
			ret = get_next_line(map_fd, &line);
	}
	if (ret == FAIL || ret1 == FAIL)
		return (fucked_up_clear(&head, line));
	ret1 = save_line(&head, line);
	if (ret1 == FAIL)
		return (fucked_up_clear(&head, line));
	return (head);
}

int	get_map(t_data *data, const char *map_path)
{
	char	*line;
	int		map_fd;
	int		ret;
	t_list	*head;

	map_fd = open(map_path, O_RDONLY);
	ret = get_next_line(map_fd, &line);
	while (ret > 0 && !is_map_started(line))
	{
		free(line);
		ret = get_next_line(map_fd, &line);
	}
	if (!ret || ret == FAIL)
		free(line);
	if (!ret || ret == FAIL)
		return (FAIL);
	head = read_map(map_fd, line);
	close(map_fd);
	if (!head)
		return (FAIL);
	ret = build_map(data, head);
	ft_lstclear(&head, free);
	return (ret);
}
