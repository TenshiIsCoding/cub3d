/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:09:39 by azaher            #+#    #+#             */
/*   Updated: 2023/11/20 18:49:00 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

float	set_ray_distance(t_game *g, int idx)
{
	return (sqrt((g->rays.inter_x[idx] - g->player.xpos) * (g->rays.inter_x[idx] - g->player.xpos) \
			+ (g->rays.inter_y[idx] - g->player.ypos) * (g->rays.inter_y[idx] - g->player.ypos)));
}

void	draw_line(t_game *g, int idx, int length)
{
	float	x;
	float	y;
	float	next_x;
	float	next_y;
	int i;

	x = g->player.xpos;
	y = g->player.ypos;
	i = 0;
	while(i < length)
	{
		next_x =  x + (i * cos(g->rays.rayAngle[idx]));
		next_y = y + (i * sin(g->rays.rayAngle[idx]));
		if (collided_wall(next_x, next_y, g, 1))
		{
			g->rays.inter_x[idx] = next_x;
			g->rays.inter_y[idx] = next_y;
			g->rays.ray_distance[idx] = set_ray_distance(g, idx);
			// printf("%f\n", g->rays.ray_distance[479]);
			return ;
		}
		my_put_pixel(&g->data, g->surface_scale * next_x, g->surface_scale * next_y, 0xFFFF00);
		i++;
	}
}

void	cast_rays(t_game *g)
{
	int		Ncolumn;
	float	anglebuff;

	Ncolumn = 0;
	g->rays.rayAngle[Ncolumn] = g->player.player_angle - (FOV / 2);
	while (Ncolumn < W_WIDTH)
	{
		anglebuff = g->rays.rayAngle[Ncolumn];
		draw_line(g, Ncolumn, 1000);
		Ncolumn++;
		g->rays.rayAngle[Ncolumn] = anglebuff + FOV / W_WIDTH;
	}
}

