/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:42 by azaher            #+#    #+#             */
/*   Updated: 2023/10/31 17:17:46 by azaher           ###   ########.fr       */
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
	float	velocity;
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
int		engine_start(t_game *game, t_player *player);
void	print_error(char *error);
void	init_game(t_game *game);
int		ft_strcmp(const char *s1, const char *s2);
void	free_2d(char **arr);
int		arrlen(char **arr);
/*				parsing functions					*/
char	*parsing(int argc, char **av);
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