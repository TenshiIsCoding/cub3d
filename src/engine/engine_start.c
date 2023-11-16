/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:50:43 by azaher            #+#    #+#             */
/*   Updated: 2023/11/16 14:24:05 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_2d(char **map)
{
	int i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			printf("%c", map[i][j]);
			j++;	
		}
		printf("\n");
		i++;
	}
}

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

//TODO:
//protect WIDTH AND HEIGHT
	dst = data->addr + (y * data->line_length + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}

void	init_player(t_player *player)
{
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->velo = 0.3;
	player->rotation_speed =  (M_PI / 500);
	player->player_angle = 3 * (M_PI / 2);
}

void	render_player(t_game *game, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	init_player(player);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				draw_circle(game, j, i, DISP_SIZE / 8);
			j++;
		}
		i++;
	}
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				draw_2d_wall(&game->data, j, i);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				draw_2d_space(&game->data, j, i);
			else if (game->map[i][j] == ' ')
				draw_2d_empty(&game->data, j, i);
			j++;
		}
		i++;
	}
}

int	check_collision(float x, float y, t_game *g)
{
	int	map_x;
	int	map_y;
	int	buff_x;
	int	buff_y;
	int	radius;

	radius = DISP_SIZE / 9;
	buff_x = floor((x + radius) / DISP_SIZE);
	buff_y = floor((y + radius) / DISP_SIZE);
	map_x = floor(x / DISP_SIZE);
	map_y = floor(y / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	buff_x = floor((x - radius) / DISP_SIZE);
	buff_y = floor((y + radius) / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	buff_x = floor((x - radius) / DISP_SIZE);
	buff_y = floor((y - radius) / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	buff_x = floor((x + radius) / DISP_SIZE);
	buff_y = floor((y - radius) / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	return ((g->map[map_y][map_x] == '1'));
}

int check_ray_collision(float x, float y, t_game *g)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / DISP_SIZE);
	map_y = floor(y / DISP_SIZE);
	return ((g->map[map_y][map_x] == '1'));
}

int	collided_wall(float x, float y, t_game *g, int mode)
{
	float	step;
	float	cstep;
	float	pAngle;
	
	pAngle = g->player.player_angle + g->player.turn_dir * g->player.rotation_speed;
	step = (float)g->player.walk_dir * g->player.velo;
	cstep = (float)g->player.cwalk_dir * g->player.velo;
	if (step != 0)
	{	
		x += cos(pAngle) * step;
		y += sin(pAngle) * step;
	}
	if (g->player.cwalk_dir == 1 || g->player.cwalk_dir == -1)
	{
		x += cos(pAngle + M_PI_2) * cstep;
		y += sin(pAngle + M_PI_2) * cstep;
	}
	if (mode == 0)
		return (check_collision(x, y, g));
	else
		return (check_ray_collision(x, y, g));
}

int	update_player(t_game *g)
{
	float step;
	float cstep;
	
	g->player.player_angle += g->player.turn_dir * g->player.rotation_speed;
	step = (float)g->player.walk_dir * g->player.velo;
	cstep = (float)g->player.cwalk_dir * g->player.velo;
	if(!collided_wall(g->player.xpos, g->player.ypos, g, 0))
	{	
		if (step != 0)
		{	
			g->player.xpos += cos(g->player.player_angle) * step;
			g->player.ypos += sin(g->player.player_angle) * step;
		}
		if (g->player.cwalk_dir == 1 || g->player.cwalk_dir == -1)
		{	
			g->player.xpos += cos(g->player.player_angle + M_PI_2) * cstep;
			g->player.ypos += sin(g->player.player_angle + M_PI_2) * cstep;
		}
	}
	render_map(g);
	draw_player(g, g->player.xpos, g->player.ypos, DISP_SIZE / 8);
	cast_rays(g);
	mlx_put_image_to_window(g->data.mlx, g->data.mlx_win, \
	g->data.img, 0, 0);
	return (0);
}

int	engine_start(t_game *game, t_player *player)
{
	game->data.img = mlx_new_image(game->data.mlx, game->map_w * DISP_SIZE, \
	game->map_h * DISP_SIZE);
	game->data.addr = mlx_get_data_addr(game->data.img \
	, &game->data.bbp, &game->data.line_length, &game->data.endian);
	render_map(game);
	render_player(game, player);
	(void)player;
	mlx_put_image_to_window(game->data.mlx, game->data.mlx_win, \
	game->data.img, 0, 0);
	return (0);
}
