/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:38:07 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 22:38:09 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_game(void)
{
	exit(EXIT_SUCCESS);
}

int	close_window(void *params)
{
	(void)params;
	close_game();
	return (EXIT_SUCCESS);
}
