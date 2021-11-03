/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:56:59 by ikael             #+#    #+#             */
/*   Updated: 2021/11/02 00:04:04 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	cleaning_buffer(char *buf, size_t len)
{
	char	*temp_buf;
	char	*to_buf;
	int		i;

	temp_buf = (char *)malloc(sizeof(char) * (len + 1));
	if (temp_buf == NULL)
		return (-1);
	temp_buf[len] = '\0';
	to_buf = buf + length(buf) + 1;
	while (len--)
		temp_buf[len] = to_buf[len];
	zeroing(buf, BUFFER_SIZE);
	i = -1;
	while (temp_buf[++i])
		buf[i] = temp_buf[i];
	free(temp_buf);
	return (1);
}

static int	creating_line(char *buf, char **line)
{
	char	*temp;
	int		len_rest;
	int		clean_value;

	len_rest = BUFFER_SIZE - segment_length(buf) - 1;
	buf[segment_length(buf)] = '\0';
	temp = strjoin(*line, buf);
	free(*line);
	if (temp == NULL)
		return (-1);
	*line = temp;
	clean_value = cleaning_buffer(buf, len_rest);
	if (clean_value == -1)
		return (-1);
	return (2);
}

static int	processing_buffer(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*temp;

	if (length(buf) == 0)
		if (read(fd, buf, BUFFER_SIZE) < 0)
			return (-1);
	while (length(buf) > 0)
	{
		if (is_n_here(buf) > 0)
			return (creating_line(buf, &*line));
		temp = strjoin(*line, buf);
		free(*line);
		if (temp == NULL)
			return (-1);
		*line = temp;
		zeroing(buf, BUFFER_SIZE);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int	reading;

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	*line = (char *)malloc(sizeof(char));
	if (*line == NULL)
		return (-1);
	**line = '\0';
	reading = 1;
	while (reading > 0)
	{
		reading = processing_buffer(fd, &*line);
		if (reading == 2)
			return (1);
	}
	if (reading == 0)
		return (0);
	free(*line);
	*line = NULL;
	return (-1);
}
