/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 02:42:25 by azaher            #+#    #+#             */
/*   Updated: 2023/11/22 09:56:57 by azaher           ###   ########.fr       */
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
