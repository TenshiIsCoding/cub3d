/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:54:26 by azaher            #+#    #+#             */
/*   Updated: 2023/11/20 18:55:53 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


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
			my_put_pixel(data,  g->surface_scale * (x + (DISP_SIZE * i)), g->surface_scale *  (y + (DISP_SIZE * j)), \
			0x0B1747);
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
		my_put_pixel(&g->data, x , y, 0xFFFFFF);
		y++;
	}
	// printf("%d\n", y);
}

void	draw_wall(t_game *g, int x, int skysize, int wallheight)
{
	(void)wallheight;
	int	y;

	y = skysize;
	while (y < W_HEIGHT)
	{
		if (y >= 0 && y < W_HEIGHT)
			my_put_pixel(&g->data, x , y, 0x0B1747);
		y++;
	}
}

void	draw_floor(t_game *g, int x,  double floorsize, double wallheight)
{
	(void)wallheight;
	double	y;

	y = floorsize;
	// printf("%f\n", y);
	while(y < W_HEIGHT)
	{
		if (y >= 0 && y < W_HEIGHT)
			my_put_pixel(&g->data, x , y, 0x808080);
		y++;
	}
}

void	draw_circle(t_game *game, int i, int j, int radius)
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
				my_put_pixel(&game->data, game->surface_scale * (x + (DISP_SIZE * i)), \
				game->surface_scale * (y + (DISP_SIZE * j)), 0x00000000);
			}
			y++;
		}
		x++;
	}
	game->player.xpos = (float)(DISP_SIZE * i);
	game->player.ypos = (float)(DISP_SIZE * j);
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
			my_put_pixel(data, g->surface_scale * (x + (DISP_SIZE * i)), g->surface_scale * (y + (DISP_SIZE * j)), \
			0x808080);
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
			my_put_pixel(data, g->surface_scale * (x + (DISP_SIZE * i)), g->surface_scale * (y + (DISP_SIZE * j)), \
			0x00FFFFFF);
			y++;
		}
		x++;
	}
}
