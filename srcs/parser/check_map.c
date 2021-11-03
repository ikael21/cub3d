/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:57:52 by ikael             #+#    #+#             */
/*   Updated: 2021/11/02 23:09:44 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_extra_chrs_plrs(t_list *head)
{
	int			i;
	char		*line;
	uint16_t	pl_count;

	pl_count = 0;
	while (head)
	{
		i = -1;
		line = (char *)head->content;
		while (line[++i])
		{
			if (is_extra(line[i]) == FAIL)
				return (FAIL);
			if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'W' || line[i] == 'E')
				pl_count++;
		}
		head = head->next;
	}
	if (pl_count != 1)
		return (FAIL);
	return (SUCCESS);
}

static int	is_map_one(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp && ft_strcmp((char *)temp->content, "") != 0)
	{
		if (is_only_spaces((char *)temp->content))
			return (FAIL);
		temp = temp->next;
	}
	while (temp && !ft_strcmp((char *)temp->content, ""))
		temp = temp->next;
	if (temp)
		return (FAIL);
	/*
		нужно дописать проверку на то, что нет дополнительной карты сбоку
	*/
	return (SUCCESS);
}

int	check_map(t_list *head)
{
	if (check_extra_chrs_plrs(head) == FAIL)
		return (FAIL);
	if (is_map_one(head) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
