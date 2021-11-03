/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:40:39 by ikael             #+#    #+#             */
/*   Updated: 2021/11/03 19:50:20 by ikael            ###   ########.fr       */
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
# include "get_next_line.h"
# include "libft.h"

// window size
# define W_WIDTH 	1024
# define W_HEIGHT	768

// size of one cell
#define SIZE		256

//
#define ROT_SPEED 2
#define WALK_SPEED 10
#define FOW 66.0
#define H_FOW FOW/2
#define DELTA_A FOW/W_WIDTH
#define FOCUS (W_WIDTH/2)*tan(dtr(H_FOW))

// keys
# define W			13
# define A			0
# define S			1
# define D			2
# define LEFT		123
# define RIGHT		124
# define ESC		53

# define FAIL		-1
# define SUCCESS	0

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
	double	posx; //парсер
	double	posy; //парсер
	double	angle;
	char	direct_view;
}	t_player;

/* STRUCT FOR ONE TEXTURE */
typedef struct s_texture
{
	void	*img; //парсер
	int		width; //парсер
	int		height; //парсер
}	t_texture;

/* STRUCT FOR ALL TEXTURES OF WALL */
typedef struct s_textures
{
	t_texture	north; //парсер
	t_texture	south; //парсер
	t_texture	west; //парсер
	t_texture	east; //парсер
}	t_textures;

/* STRUCT FOR MAP */
typedef struct s_map
{
	char	**map; //парсер
	int		width; //парсер
	int		height; //парсер
	int		f_color;
	int		c_color;
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
	t_player	player; //парсер
	t_textures 	textures; //парсер
	t_map		map; //парсер
}	t_data;

/* GRAPHIC */
double	dtr(double degree);
int		render(t_data *data);
void	pixel_put(t_data *data, int x, int y, int color);

/* PARSER */
int		get_map_identifiers(t_data *data, const char *map_path);
int		parse_identifiers(t_data *data, char **ln_prt);
int		get_map(t_data *data, const char *map_path);
int		check_map(t_list *head);
int		is_map_closed(char **map);
int		build_map(t_data *data, t_list *head);

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

/* UTILS */
void	free_str_arr(char **str_arr);
int		rgb_to_hex(int red, int green, int blue);
int		is_map_started(char *line);
size_t	get_longest_line(t_list *head);
size_t	get_map_size(t_list *head);
int		is_extra(const unsigned char c);
int		is_only_spaces(char *line);

#endif
