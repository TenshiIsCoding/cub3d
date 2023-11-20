/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:50:43 by azaher            #+#    #+#             */
/*   Updated: 2023/11/20 19:10:08 by azaher           ###   ########.fr       */
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

	if (x > W_WIDTH)
		x = W_WIDTH;
	if (y > W_HEIGHT)
		y = W_HEIGHT;
	dst = data->addr + (y * data->line_length + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}

void	init_player(t_player *player)
{
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->velo = 0.4;
	player->rotation_speed = (M_PI / 500);
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
			if (game->map[i][j] == 'S')
			{
				draw_circle(game, j, i, DISP_SIZE / 8);
				game->player.player_angle = 90 * (M_PI / 180);
			}
			else if (game->map[i][j] == 'N')
			{
				draw_circle(game, j, i, DISP_SIZE / 8);
				game->player.player_angle = 270 * (M_PI / 180);
			}
			else if (game->map[i][j] == 'W')
			{
				draw_circle(game, j, i, DISP_SIZE / 8);
				game->player.player_angle = 180 * (M_PI / 180);
			}
			else if (game->map[i][j] == 'E')
			{
				draw_circle(game, j, i, DISP_SIZE / 8);
				game->player.player_angle = 0;
			}
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
				draw_2d_wall(game, &game->data, j, i);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'S')
				draw_2d_space(game, &game->data, j, i);
			else if (game->map[i][j] == 'N' || game->map[i][j] == 'E')
				draw_2d_space(game, &game->data, j, i);
			else if (game->map[i][j] == 'W')
				draw_2d_space(game, &game->data, j, i);
			else if (game->map[i][j] == ' ')
				draw_2d_empty(game, &game->data, j, i);
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
	int	idx;

	idx = floor(1 / DISP_SIZE);
	map_x = floor(x / DISP_SIZE);
	map_y = floor(y / DISP_SIZE);
	// printf("map x : %d/ map y: %d\n", map_x, map_y);
	return (g->map[map_y][map_x] == '1' \
			|| g->map[map_y][map_x] == '\n' \
			|| g->map[map_y][map_x] == '\0' \
			|| g->map[map_y][map_x] == ' ' \
			|| g->map[map_y + idx][map_x + idx] == '1');
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

int	render_3d_scene(t_game *g)
{
	int		i;
	float	rayDistance;

	i = 0;
	g->Projection_distance = (float)(W_WIDTH / 2) / tan(FOV / 2);
	while(i < W_WIDTH)
	{
		rayDistance = g->rays.ray_distance[i] * cos(g->rays.rayAngle[i] - g->player.player_angle);
		g->wall_height = (DISP_SIZE / rayDistance) * g->Projection_distance;
		g->sky_size = (W_HEIGHT / 2.0) - (g->wall_height / 2.0);
		g->floor_size = (W_HEIGHT / 2.0) + (g->wall_height / 2.0);
		if (g->wall_height > W_HEIGHT)
			g->wall_height = W_HEIGHT;
		// printf("%f\n", g->wall_height);
		draw_sky(g, i, g->sky_size);
		draw_wall(g, i, g->sky_size, g->wall_height);
		draw_floor(g, i, g->floor_size, g->wall_height);
		// draw_collumn(g, i, (W_HEIGHT / 2) - (g->wall_height / 2), g->wall_height);
		i++;
	}
	return (0);
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
	render_3d_scene(g);
	render_map(g);
	draw_player(g, g->player.xpos, g->player.ypos, DISP_SIZE / 8);
	cast_rays(g);
	mlx_put_image_to_window(g->data.mlx, g->data.mlx_win, \
	g->data.img, 0, 0);
	return (0);
}

int	engine_start(t_game *game, t_player *player)
{
	game->data.img = mlx_new_image(game->data.mlx, W_WIDTH, \
	W_HEIGHT);
	game->data.addr = mlx_get_data_addr(game->data.img \
	, &game->data.bbp, &game->data.line_length, &game->data.endian);
	game->surface_scale = 20.0 / (game->map_w * game->map_h);
	printf("%f\n", game->surface_scale);
	render_map(game);
	render_player(game, player);
	cast_rays(game);
	printf("%f\n", game->rays.ray_distance[2]);
	(void)player;
	mlx_put_image_to_window(game->data.mlx, game->data.mlx_win, \
	game->data.img, 0, 0);
	return (0);
}
