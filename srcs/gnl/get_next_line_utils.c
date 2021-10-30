/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:00:18 by ikael             #+#    #+#             */
/*   Updated: 2021/10/27 15:14:12 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	length(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

size_t	segment_length(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\n')
		i++;
	return (i);
}

char	*strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	size_t	len;
	size_t	i;

	len = length((char *)s1) + length((char *)s2);
	pointer = (char *)malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (i < len - length((char *)s2))
	{
		pointer[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		pointer[i] = s2[i - length((char *)s1)];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}

void	zeroing(char *buf, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		buf[i] = '\0';
		i++;
	}
}

int	is_n_here(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
