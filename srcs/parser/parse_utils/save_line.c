/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 04:27:28 by ikael             #+#    #+#             */
/*   Updated: 2021/11/05 04:27:47 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	save_line(t_list **head, char *line)
{
	t_list	*new;

	new = ft_lstnew(line);
	if (new == NULL)
		return (FAIL);
	ft_lstadd_back(head, new);
	return (SUCCESS);
}
