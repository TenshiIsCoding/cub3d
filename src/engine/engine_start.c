/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:50:43 by azaher            #+#    #+#             */
/*   Updated: 2023/11/29 13:33:07 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

int	render_3d_scene(t_game *g)
{
	int		i;
	float	raydistance;

	i = 0;
	g->Projection_distance = (float)(W_WIDTH / 2) / tan(FOV / 2);
	while (i < W_WIDTH)
	{
		raydistance = g->rays.ray_distance[i] \
			* cos(g->rays.rayAngle[i] - g->player.player_angle);
		g->wall_height = (DISP_SIZE / raydistance) * g->Projection_distance;
		g->sky_size = (W_HEIGHT / 2.0) - (g->wall_height / 2.0);
		g->floor_size = (W_HEIGHT / 2.0) + (g->wall_height / 2.0);
		g->wall_index = g->wall_height; 
		if (g->wall_height > W_HEIGHT)
			g->wall_height = W_HEIGHT;
		draw_sky(g, i, g->sky_size);
		draw_wall(g, i, g->sky_size, g->wall_height);
		draw_floor(g, i, g->floor_size, g->wall_height);
		i++;
	}
	return (0);
}

int	update_player(t_game *g)
{
	float	step;
	float	cstep;

	g->player.player_angle += g->player.turn_dir * g->player.rotation_speed;
	step = (float)g->player.walk_dir * g->player.velo;
	cstep = (float)g->player.cwalk_dir * g->player.velo;
	if (!collided_wall(g->player.xpos, g->player.ypos, g, 0))
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
	// draw_player(g, g->player.xpos, g->player.ypos, DISP_SIZE / 8);
	cast_rays(g);
	// printf("%f\n", g->rays.rayAngle[W_WIDTH / 2]);
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
	// render_map(game);
	render_player(game, player);
	cast_rays(game);
	mlx_put_image_to_window(game->data.mlx, game->data.mlx_win, \
	game->data.img, 0, 0);
	return (0);
}
