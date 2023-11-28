/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:54:26 by azaher            #+#    #+#             */
/*   Updated: 2023/11/28 16:27:30 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_player(t_player *player)
{
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->velo = 1;
	player->rotation_speed = (M_PI / 200);
}

void	draw_2d_wall(t_game *g, t_data *data, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	while (x < DISP_SIZE)
	{
		y = 0;
		while (y < DISP_SIZE)
		{
			my_put_pixel(data, g->surface_scale * (x + (DISP_SIZE * i)), \
				g->surface_scale * (y + (DISP_SIZE * j)), 0x0B1747);
			y++;
		}
		x++;
	}
}

void	draw_sky(t_game *g, int x, int skysize)
{
	int	y;

	y = 0;
	while (y < skysize)
	{
		my_put_pixel(&g->data, x, y, 0xFFFFFF);
		y++;
	}
}

void	draw_wall(t_game *g, int x, int skysize, int wallheight)
{
	int	y;

	(void)wallheight;
	y = skysize;
	while (y < W_HEIGHT)
	{
		if (y >= 0 && y < W_HEIGHT)
		{
			if (g->rays.ray_direction[x] == NORTH)
				my_put_pixel(&g->data, x, y, 0xFF0000);
			else if (g->rays.ray_direction[x] == SOUTH)
				my_put_pixel(&g->data, x, y, 0x00FF00);
			else if (g->rays.ray_direction[x] == WEST)
				my_put_pixel(&g->data, x, y, 0x0000FF);
			else if (g->rays.ray_direction[x] == EAST)
				my_put_pixel(&g->data, x, y, 0xFFFF00);
		}
		y++;
	}
}

void	draw_floor(t_game *g, int x, double floorsize, double wallheight)
{
	double	y;

	(void)wallheight;
	y = floorsize;
	while (y < W_HEIGHT)
	{
		if (y >= 0 && y < W_HEIGHT)
			my_put_pixel(&g->data, x, y, 0x808080);
		y++;
	}
}
