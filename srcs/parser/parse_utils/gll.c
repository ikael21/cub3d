/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:51:15 by ikael             #+#    #+#             */
/*   Updated: 2021/11/02 21:37:34 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	get_longest_line(t_list *head)
{
	size_t	max;
	size_t	temp_len;

	max = ft_strlen((char *)head->content);
	while (head)
	{
		temp_len = ft_strlen((char *)head->content);
		if (temp_len > max)
			max = temp_len;
		head = head->next;
	}
	return (max);
}

size_t	get_map_size(t_list *head)
{
	size_t	size;

	size = 0;
	while (head)
	{
		if (ft_strcmp((char *)head->content, "") != 0)
			size++;
		head = head->next;
	}
	return (size);
}
