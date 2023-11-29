/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:54:26 by azaher            #+#    #+#             */
/*   Updated: 2023/11/29 13:47:07 by azaher           ###   ########.fr       */
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
		my_put_pixel(&g->data, x, y, g->data.c);
		y++;
	}
}

void	fetch_pixel_from_texture(t_game *g, int x, int y, int dir)
{
	int		color;
	double	tx;
	double	ty;
	double	text_scale;
	
	text_scale = (double)g->arr_text[dir].h / g->wall_index;
	if (dir == N_IDX || dir == S_IDX)
	{
		tx = (((int)g->rays.inter_x[x] % DISP_SIZE) * g->arr_text[dir].w) / DISP_SIZE;
		ty = (y - g->sky_size) * text_scale;
	}
	if (dir == E_IDX || dir == W_IDX)
	{
		tx = (((int)g->rays.inter_y[x] % DISP_SIZE) * g->arr_text[dir].w) / DISP_SIZE;
		ty = (y - g->sky_size) * text_scale;
	}
	// printf("%d\n", g->arr_text[dir].h);
	color = my_pixel_get(&g->arr_text[dir], tx, ty);
	my_put_pixel(&g->data, x, y, color);
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
				fetch_pixel_from_texture(g, x, y, N_IDX);
			else if (g->rays.ray_direction[x] == SOUTH)
				fetch_pixel_from_texture(g, x, y, S_IDX);
			else if (g->rays.ray_direction[x] == WEST)
				fetch_pixel_from_texture(g, x, y, W_IDX);
			else if (g->rays.ray_direction[x] == EAST)
				fetch_pixel_from_texture(g, x, y, E_IDX);
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
			my_put_pixel(&g->data, x, y, g->data.f);
		y++;
	}
}
