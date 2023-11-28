/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_tools_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:53:21 by azaher            #+#    #+#             */
/*   Updated: 2023/11/28 16:22:47 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_circle(t_game *game, int i, int j, int radius)
{
	(void)radius;
	game->player.xpos = (float)(DISP_SIZE * i) + (DISP_SIZE / 2);
	game->player.ypos = (float)(DISP_SIZE * j) + (DISP_SIZE / 2);
}

void	draw_player(t_game *g, int i, int j, int radius)
{
	int	x;
	int	y;

	x = -radius;
	while (x < radius)
	{
		y = -radius;
		while (y < radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				my_put_pixel(&g->data, g->surface_scale * (x + i), \
				g->surface_scale * (y + j), 0x00000000);
			}
			y++;
		}
		x++;
	}
}

void	draw_2d_space(t_game *g, t_data *data, int i, int j)
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
				g->surface_scale * (y + (DISP_SIZE * j)), 0x808080);
			y++;
		}
		x++;
	}
}

void	draw_2d_empty(t_game *g, t_data *data, int i, int j)
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
			g->surface_scale * (y + (DISP_SIZE * j)), 0x00FFFFFF);
			y++;
		}
		x++;
	}
}
