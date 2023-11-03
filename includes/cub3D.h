/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:42 by azaher            #+#    #+#             */
/*   Updated: 2023/11/03 02:50:48 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/libft.h"
# include "../libraries/queue/queue.h"
# include "../libraries/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# define DISP_SIZE 64

# define K_P 112
# define K_I 105
# define K_R 114
# define K_PLUS 61
# define K_MINUS 45
# define K_Q 113
# define K_W 119
# define K_E 101
# define K_F 102
# define K_S 115
# define K_A 97
# define K_D 100
# define ESC 65307

typedef struct s_map
{
	char	**map;
	int		w_map;
	int		h_map;
	int		s_map;
}	t_map;

typedef struct s_player
{
	float	xpos;
	float	ypos;
	int		radius;
	int		turn_dir;
	int		walk_dir;
	int		velo;
	float	rotation_speed;
	float	player_angle;
}	t_player;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
	char	*n_texture;
	char	*e_texture;
	char	*w_texture;
	char	*s_texture;
	int		f;
	int		c;
	int		w;
	int		a;
	int		s;
	int		d;
}	t_data;

typedef struct s_game
{
	t_data		data;
	t_player	player;
	int			player_x;
	int			player_y;
	int			map_h;
	int			map_w;
	char		**map;
}	t_game;

/*				engine functions					*/
void	draw_2d_space(t_data *data, int i, int j);
void	draw_player(t_game *game, int i, int j, int radius);
void	draw_circle(t_game *game, int i, int j, int radius);
void	my_put_pixel(t_data *data, int x, int y, int color);
void	init_player(t_player *player);
void	render_player(t_game *game, t_player *player);
int		move_player(int keycode, t_game *g);
void	draw_2d_wall(t_data *data, int i, int j);
void	draw_2d_empty(t_data *data, int i, int j) ;
int		engine_start(t_game *game, t_player *player);
int    key_press(int keycode, t_game *g);
int    key_release(int keycode, t_game *g);
int		move_player(int keycode, t_game *game);
void	print_error(char *error);
void	init_game(t_game *game);
int		ft_strcmp(const char *s1, const char *s2);
void	free_2d(char **arr);
int		arrlen(char **arr);

#endif