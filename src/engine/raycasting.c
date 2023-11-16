/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:09:39 by azaher            #+#    #+#             */
/*   Updated: 2023/11/16 14:36:10 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
void	draw_line(t_game *g, int length)
{
	float	x;
	float	y;
	float	next_x;
	float	next_y;
	int i = 0;

	x = g->player.xpos;
	y = g->player.ypos;
	
	while(i <  length)
	{
		next_x =  x + (i * cos(g->player.rayAngle));
		next_y = y + (i * sin(g->player.rayAngle));
		if (collided_wall(next_x, next_y, g, 1))
			return ;
		my_put_pixel(&g->data, next_x, next_y, 0x00000000);
		i++;
	}

	
	
	// int dx_diff = abs((int)(next_x - g->player.xpos));
	// int dy_diff = abs((int)(next_y - g->player.ypos));
	
	// int steps;

	// if (dy_diff > dx_diff)
	//     steps = dy_diff;
	// else
	//     steps = dx_diff;
	// if(!collided_wall( g->player.xpos + (next_x - g->player.xpos) / steps, g->player.ypos + (next_y - g->player.ypos) / steps, g))
	// {
	// 	 for (int i = 0; i <= steps; i++) {
    //     mlx_pixel_put(g->data.mlx, g->data.mlx_win, g->player.xpos + i * (next_x - g->player.xpos) / steps, g->player.ypos + i * (next_y - g->player.ypos) / steps, 0x000000);
    // 	}
	// }
}

void	cast_rays(t_game *g)
{
	int		Ncolumn;

	Ncolumn = 0;
	g->player.rayAngle = g->player.player_angle - (FOV / 2);
	while (Ncolumn < W_WIDTH)
	{
		draw_line(g, 1000);
		Ncolumn++;
		g->player.rayAngle += FOV / W_WIDTH;
	}
}

