/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:50:43 by azaher            #+#    #+#             */
/*   Updated: 2023/11/03 03:29:27 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}

void	init_player(t_player *player)
{
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->velo = 4.0;
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

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
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
}

int	move_player(int keycode, t_game *g)
{
	if(keycode == ESC)
		exit (0);
	if (keycode == K_W)
		g->player.ypos -=  g->player.velo;
	if (keycode == K_A)
		g->player.xpos -=  g->player.velo;
	if (keycode == K_S)
		g->player.ypos +=  g->player.velo;
	if (keycode == K_D)
		g->player.xpos +=  g->player.velo;
	render_map(g);
	draw_player(g, g->player.xpos, g->player.ypos, DISP_SIZE / 8);
	mlx_put_image_to_window(g->data.mlx, g->data.mlx_win, \
	g->data.img, 0, 0);
	return (0);
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
	// printf("pos x: %f pos y: %f\n", game->player.xpos, game->player.ypos);
	mlx_put_image_to_window(game->data.mlx, game->data.mlx_win, \
	game->data.img, 0, 0);
	return (0);
}
