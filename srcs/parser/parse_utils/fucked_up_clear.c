/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucked_up_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 04:29:08 by ikael             #+#    #+#             */
/*   Updated: 2021/11/05 04:29:16 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*fucked_up_clear(t_list **head, char *str)
{
	if (head)
		ft_lstclear(head, free);
	if (str)
		free(str);
	return (NULL);
}
