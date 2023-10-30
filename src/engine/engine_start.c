/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:50:43 by azaher            #+#    #+#             */
/*   Updated: 2023/10/20 15:46:26 by azaher           ###   ########.fr       */
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
	game->player.xpos = x + (DISP_SIZE * i);
	game->player.ypos = y + (DISP_SIZE * j);
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

void	init_player(t_player *player)
{
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->velocity = 4.0;
	player->rotation_speed = 3 * (M_PI / 180);
	player->player_angle = M_PI / 2;
}

void	render_player(t_game *game, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	init_player(player);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				draw_circle(game, j, i, DISP_SIZE / 8);
			j++;
		}
		i++;
	}
}

int	engine_start(t_game *game, t_player *player)
{
	int			i;
	int			j;

	i = 0;
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
			else if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				draw_2d_space(&game->data, j, i);
			else if (game->map[i][j] == ' ')
				draw_2d_empty(&game->data, j, i);
			j++;
		}
		i++;
	}
	render_player(game, player);
	printf("pos x: %f pos y: %f\n", game->player.xpos, game->player.ypos);
	mlx_put_image_to_window(game->data.mlx, game->data.mlx_win, \
	game->data.img, 0, 0);
	return (0);
}
