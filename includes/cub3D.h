/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:42 by azaher            #+#    #+#             */
/*   Updated: 2023/11/27 19:05:08 by azaher           ###   ########.fr       */
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
# define K_W 119
# define K_E 101
# define K_F 102
# define K_S 115
# define K_A 97
# define K_D 100
# define K_ARRR 65363
# define K_ARRL 65361
# define ESC 65307
# define FOV (1.0472)
# define W_WIDTH 1280
# define W_HEIGHT 720
# define NORTH 360
# define SOUTH 180
# define EAST 90
# define WEST 270
# define VERTICAL 1
# define HORIZONTAL 0

typedef struct s_rays
{
	float	rayAngle[W_WIDTH];
	float	ray_distance[W_WIDTH];
	float	inter_x[W_WIDTH];
	float	inter_y[W_WIDTH];
	int		ray_wall_coll[W_WIDTH];
	int		ray_direction[W_WIDTH];
}	t_rays;

typedef struct s_player
{
	float	xpos;
	float	ypos;
	int		radius;
	int		turn_dir;
	int		walk_dir;
	int		cwalk_dir;
	float	velo;
	float	rotation_speed;
	float	player_angle;
}	t_player;

typedef struct s_textures
{
	char	*path;
	void	*image;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
	int		w;
	int		h;

}	t_textures;

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
}	t_data;

typedef struct s_game
{
	t_textures	arr_text[4];
	t_data		data;
	t_player	player;
	t_rays		rays;
	float		Projection_distance;
	int			map_h;
	int			map_w;
	float		surface_scale;
	float		wall_height;
	float		sky_size;
	float		floor_size;
	char		**map;
}	t_game;

typedef	struct s_check_info
{
	char	*key;
	char	**value;
}	t_check_info;

typedef	struct s_parsing
{
	int				fd;
	char			*map_str;
	int				on_off;
	int				num_info;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	int				f_color;
	int				c_color;
	int				player_exit;
	t_check_info	*info;
	char			**map_2d;
}	t_parsing;

/*				engine functions					*/

void	print_2d(char **map);
void	draw_2d_space(t_game *g, t_data *data, int i, int j);
void	draw_player(t_game *game, int i, int j, int radius);
void	draw_circle(t_game *game, int i, int j, int radius);
void	my_put_pixel(t_data *data, int x, int y, int color);
void	draw_sky(t_game *g, int x, int skysize);
void	draw_wall(t_game *g, int x, int skysize, int wallheight);
void	draw_floor(t_game *g, int x,  double floorsize, double wallheight);
void	set_ray_data(t_game *g, int idx, float next_x, float next_y);
int		render_3d_scene(t_game *g);
void	init_player(t_player *player);
void	render_player(t_game *game, t_player *player);
int		update_player(t_game *g);
void	draw_2d_wall(t_game *g, t_data *data, int i, int j);
void	draw_collumn(t_game *g, int x, int y, int length);
void	draw_2d_empty(t_game *g, t_data *data, int i, int j);
void	cast_rays(t_game *g);
int		collided_wall(float x, float y, t_game *g, int mode);
int		engine_start(t_game *game, t_player *player);
int		key_press(int keycode, t_game *g);
int		key_release(int keycode, t_game *g);
void	print_error(char *error);
void	init_game(t_game *game);
int		ft_strcmp(const char *s1, const char *s2);
void	free_2d(char **arr);
int		arrlen(char **arr);
/*				parsing functions					*/
char	*parsing(t_game *s_game,int argc, char **av);
void	func_error(char *str);
int		check_file_name(char *str);
void	init_struct(t_parsing *s_pars);
// int		empty_line(char *str);
void	parse_info(t_parsing *s_pars,char *temp1);
void	stock_info(t_parsing *s_pars, char **arr_2d);
int		stock_colors(t_parsing *s_pars, char **arr_2d);
int		parse_colors(char *arr);
int		get_color(char **arr_2d);
int		calculate_comma(char	*str);
int		get_color_num(char	*str, int	i);
/*Parse Map*/
void	parse_map(t_parsing *s_pars, char *temp1);
void	check_free_lines(char *arr);
int		empty_line(char	*str);
void	is_it_full_walls(char *str);
#endif