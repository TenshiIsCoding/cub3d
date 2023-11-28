/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:09:39 by azaher            #+#    #+#             */
/*   Updated: 2023/11/27 19:00:25 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

float	set_ray_distance(t_game *g, int idx)
{
	return (sqrt((g->rays.inter_x[idx] - g->player.xpos) * \
				(g->rays.inter_x[idx] - g->player.xpos) + \
				(g->rays.inter_y[idx] - g->player.ypos) * \
				(g->rays.inter_y[idx] - g->player.ypos)));
}

void	set_ray_data(t_game *g, int idx, float next_x, float next_y)
{
	g->rays.inter_x[idx] = next_x;
	g->rays.inter_y[idx] = next_y;
	g->rays.ray_distance[idx] = set_ray_distance(g, idx);
}

void	set_wall_intersection(t_game *g, float first_coord, float second_coord, int idx)
{
	float	result;

	result = first_coord - second_coord;
	if (result < 0 && g->rays.ray_wall_coll[idx] == VERTICAL)
		g->rays.ray_direction[idx] = WEST;
	else if (result > 0 && g->rays.ray_wall_coll[idx] == VERTICAL)
		g->rays.ray_direction[idx] = EAST;
	else if (result < 0 && g->rays.ray_wall_coll[idx] == HORIZONTAL)
		g->rays.ray_direction[idx] = SOUTH;
	else if (result > 0 && g->rays.ray_wall_coll[idx] == HORIZONTAL)
		g->rays.ray_direction[idx] = NORTH;
}

void	draw_line(t_game *g, int idx)
{
	float	next_x;
	float	next_y;
	int		i;

	next_y = g->player.ypos;
	i = -1;
	while (1)
	{
		next_x = g->player.xpos + (++i * cos(g->rays.rayAngle[idx]));
		if (collided_wall(next_x, next_y, g, 1))
		{
			g->rays.ray_wall_coll[idx] = VERTICAL;
			set_wall_intersection(g, g->player.xpos, next_x, idx);
			set_ray_data(g, idx, next_x, next_y);
			return ;
		}
		next_y = g->player.ypos + (i * sin(g->rays.rayAngle[idx]));
		if (collided_wall(next_x, next_y, g, 1))
		{
			g->rays.ray_wall_coll[idx] = HORIZONTAL;
			set_wall_intersection(g, g->player.ypos, next_y, idx);
			set_ray_data(g, idx, next_x, next_y);
			return ;
		}
		my_put_pixel(&g->data, g->surface_scale * next_x, \
			g->surface_scale * next_y, 0xFFFF00);
	}
}

void	cast_rays(t_game *g)
{
	int		ncolumn;
	float	anglebuff;

	ncolumn = 0;
	g->rays.rayAngle[ncolumn] = g->player.player_angle - (FOV / 2);
	if (g->rays.rayAngle[ncolumn] > (2 * M_PI))
		g->rays.rayAngle[ncolumn] -= (2 * M_PI);
	else if (g->rays.rayAngle[ncolumn] < 0)
		g->rays.rayAngle[ncolumn] += (2 * M_PI);
	while (ncolumn < W_WIDTH)
	{
		anglebuff = g->rays.rayAngle[ncolumn];
		draw_line(g, ncolumn);
		ncolumn++;
		if (ncolumn < W_WIDTH)
		{
		g->rays.rayAngle[ncolumn] = anglebuff + FOV / W_WIDTH;
		if (g->rays.rayAngle[ncolumn] > (2 * M_PI))
			g->rays.rayAngle[ncolumn] -= (2 * M_PI);
		else if (g->rays.rayAngle[ncolumn] < 0)
			g->rays.rayAngle[ncolumn] += (2 * M_PI);
		}
	}
}
