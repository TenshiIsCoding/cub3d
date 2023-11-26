/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:09:39 by azaher            #+#    #+#             */
/*   Updated: 2023/11/26 12:09:38 by azaher           ###   ########.fr       */
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

void	draw_line(t_game *g, int idx, int length)
{
	float	x;
	float	y;
	float	next_x;
	float	next_y;
	int		i;

	x = g->player.xpos;
	y = g->player.ypos;
	i = 0;
	while (i < length)
	{
		next_x = x + (i * cos(g->rays.rayAngle[idx]));
		next_y = y + (i * sin(g->rays.rayAngle[idx]));
		if (collided_wall(next_x, next_y, g, 1) || \
			collided_wall(next_x, next_y + 1, g, 1))
		{
			set_ray_data(g, idx, next_x, next_y);
			return ;
		}
		my_put_pixel(&g->data, g->surface_scale * next_x, \
			g->surface_scale * next_y, 0xFFFF00);
		i++;
	}
}
void	set_ray_direction(t_game *g, int ncolumn, float rayangle)
{
	if (rayangle >= (M_PI / 4) && rayangle < ((3 * M_PI) / 4))
		g->rays.ray_direction[ncolumn] = SOUTH;
	else if (rayangle >= ((5 * M_PI) / 4) && rayangle < ((7 * M_PI) / 4))
		g->rays.ray_direction[ncolumn] = NORTH;
	else if (rayangle >= ((3 * M_PI) / 4) && rayangle < ((5 * M_PI) / 4))
		g->rays.ray_direction[ncolumn] = WEST;
	else if ((rayangle >= 0 && rayangle < (M_PI / 4)) || (rayangle >= 0 && rayangle < ((7 * M_PI) / 4)))
		g->rays.ray_direction[ncolumn] = EAST;

	if (ncolumn == W_WIDTH / 2)
	{
		if (g->rays.ray_direction[ncolumn] == SOUTH)
			printf("SOUTH\n");
		else if (g->rays.ray_direction[ncolumn] == NORTH)
			printf("NORTH\n");
		else if (g->rays.ray_direction[ncolumn] == EAST)
			printf("EAST\n");
		else if (g->rays.ray_direction[ncolumn] == WEST)
			printf("WEST\n");
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
		draw_line(g, ncolumn, 1000);
		ncolumn++;
		g->rays.rayAngle[ncolumn] = anglebuff + FOV / W_WIDTH;
		if (g->rays.rayAngle[ncolumn] > (2 * M_PI))
			g->rays.rayAngle[ncolumn] -= (2 * M_PI);
		else if (g->rays.rayAngle[ncolumn] < 0)
			g->rays.rayAngle[ncolumn] += (2 * M_PI);
		set_ray_direction(g, ncolumn, g->rays.rayAngle[ncolumn]);
	}
}
