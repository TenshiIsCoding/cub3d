/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:54:26 by azaher            #+#    #+#             */
/*   Updated: 2023/11/13 16:15:10 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_2d_wall(t_data *data, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	while (x < DISP_SIZE)
	{
		y = 0;
		while (y < DISP_SIZE)
		{
			my_put_pixel(data, x + (DISP_SIZE * i), y + (DISP_SIZE * j), \
			0x00FF0000);
			y++;
		}
		x++;
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
				my_put_pixel(&game->data, x + (DISP_SIZE * i), \
				y + (DISP_SIZE * j), 0x00000000);
			}
			y++;
		}
		x++;
	}
	game->player.xpos = (float)(DISP_SIZE * i);
	game->player.ypos = (float)(DISP_SIZE * j);
}

void	draw_player(t_game *game, int i, int j, int radius)
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
				my_put_pixel(&game->data, x + i, \
				y + j, 0x00000000);
			}
			y++;
		}
		x++;
	}
}

void	draw_2d_space(t_data *data, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	while (x < DISP_SIZE)
	{
		y = 0;
		while (y < DISP_SIZE)
		{
			if (x == 0 || y == 0)
				my_put_pixel(data, x + (DISP_SIZE * i), y + (DISP_SIZE * j), \
			0x000000);
			else
				my_put_pixel(data, x + (DISP_SIZE * i), y + (DISP_SIZE * j), \
			0xFFFFFF);
			y++;
		}
		x++;
	}
}

void	draw_2d_empty(t_data *data, int i, int j) 
{
	int	x;
	int	y;

	x = 0;
	while (x < DISP_SIZE)
	{
		y = 0;
		while (y < DISP_SIZE)
		{
			my_put_pixel(data, x + (DISP_SIZE * i), y + (DISP_SIZE * j), \
			0x00000000);
			y++;
		}
		x++;
	}
}
