/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 02:42:25 by azaher            #+#    #+#             */
/*   Updated: 2023/11/22 12:23:08 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_press(int keycode, t_game *g)
{
	if (keycode == ESC)
		exit (0);
	if (keycode == K_W)
		g->player.walk_dir = +1;
	if (keycode == K_S)
		g->player.walk_dir = -1;
	if (keycode == K_A)
		g->player.cwalk_dir = -1;
	if (keycode == K_D)
		g->player.cwalk_dir = +1;
	if (keycode == K_ARRL)
		g->player.turn_dir = -1;
	if (keycode == K_ARRR)
	{
		g->player.turn_dir = +1;
	}
	return (0);
}

int	key_release(int keycode, t_game *g)
{
	if (keycode == ESC)
		exit (0);
	if (keycode == K_W)
		g->player.walk_dir = 0;
	if (keycode == K_S)
		g->player.walk_dir = 0;
	if (keycode == K_A)
		g->player.cwalk_dir = 0;
	if (keycode == K_D)
		g->player.cwalk_dir = 0;
	if (keycode == K_ARRL)
		g->player.turn_dir = 0;
	if (keycode == K_ARRR)
		g->player.turn_dir = 0;
	return (0);
}

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > W_WIDTH)
		x = W_WIDTH;
	if (y > W_HEIGHT)
		y = W_HEIGHT;
	dst = data->addr + (y * data->line_length + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}

void	set_player(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'S')
	{
		draw_circle(game, j, i, DISP_SIZE / 8);
		game->player.player_angle = 90 * (M_PI / 180);
	}
	else if (game->map[i][j] == 'N')
	{
		draw_circle(game, j, i, DISP_SIZE / 8);
		game->player.player_angle = 270 * (M_PI / 180);
	}
	else if (game->map[i][j] == 'W')
	{
		draw_circle(game, j, i, DISP_SIZE / 8);
		game->player.player_angle = 180 * (M_PI / 180);
	}
	else if (game->map[i][j] == 'E')
	{
		draw_circle(game, j, i, DISP_SIZE / 8);
		game->player.player_angle = 0;
	}
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
			set_player(game, i, j);
			j++;
		}
		i++;
	}
}
