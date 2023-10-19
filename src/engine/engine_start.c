/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:50:43 by azaher            #+#    #+#             */
/*   Updated: 2023/10/19 15:26:34 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}

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

int	engine_start(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->data.img = mlx_new_image(game->data.mlx, game->map_w * DISP_SIZE, \
	game->map_h * DISP_SIZE);
	game->data.addr = mlx_get_data_addr(game->data.img \
	, &game->data.bbp, &game->data.line_length, &game->data.endian);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				draw_2d_wall(&game->data, j, i);
			else if (game->map[i][j] == '0')
				draw_2d_space(&game->data, j, i);
			else if (game->map[i][j] == ' ')
				draw_2d_empty(&game->data, j, i);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->data.mlx, game->data.mlx_win, \
	game->data.img, 0, 0);
	return (0);
}
