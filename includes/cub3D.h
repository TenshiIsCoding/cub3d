/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:42 by azaher            #+#    #+#             */
/*   Updated: 2023/10/19 15:12:23 by azaher           ###   ########.fr       */
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
# include <stdlib.h>
# include <mlx.h>
# define DISP_SIZE 64

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
	t_data	data;
	int		player_x;
	int		player_y;
	int		map_h;
	int		map_w;
	char	**map;
}	t_game;

/*				engine functions					*/
int		engine_start(t_game *game);
void	print_error(char *error);
void	init_game(t_game *game);
int		ft_strcmp(const char *s1, const char *s2);
void	free_2d(char **arr);
int		arrlen(char **arr);

#endif