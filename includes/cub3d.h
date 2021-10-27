/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:40:39 by ikael             #+#    #+#             */
/*   Updated: 2021/10/26 14:32:21 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

// window size
# define W_WIDTH 	1024
# define W_HEIGHT	768

// size of one cell
#define SIZE 64

//
#define ROT_SPEED 1.5

// keys
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define ESC 53

/* STRUCT FOR KEYS */
typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_keys;

/* STRUCT FOR PLAYER */
typedef struct s_player
{
	t_keys	keys;
	double	posx;
	double	posy;
	double	angle;
}	t_player;

/* STRUCT FOR ONE TEXTURE */
typedef struct s_texture
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_texture;

/* STRUCT FOR ALL TEXTURES OF WALL */
typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
}	t_textures;

/* STRUCT FOR MAP */
typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

/* STRUCT FOR RENDER IMAGE */
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

/* MAIN STRUCT */
typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		next;
	t_player	player;
	t_textures 	textures;
	t_map		map;
}	t_data;

/* GRAPHIC */
int		render(t_data *data);
void	pixel_put(t_data *data, int x, int y, int color);

/* PARSER */

/* CONTROL */
int		key_hook_press(int keycode, void *params);
int		key_hook_release(int keycode, void *params);
int		move(t_data *data);
void	close_game(void);
void	walk_forward(t_data *data);
void	walk_backward(t_data *data);
void	turn_left(t_data *data);
void	turn_right(t_data *data);
void	strafe_left(t_data *data);
void	strafe_right(t_data *data);

#endif
