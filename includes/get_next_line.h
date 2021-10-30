/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:57:25 by ikael             #+#    #+#             */
/*   Updated: 2021/10/27 09:48:48 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE	100

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*strjoin(char const *s1, char const *s2);
void	zeroing(char *buf, size_t size);
size_t	length(char *string);
size_t	segment_length(char *string);
int		is_n_here(char *buff);

#endif
