/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 02:42:25 by azaher            #+#    #+#             */
/*   Updated: 2023/11/03 03:02:29 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


int	key_press(int keycode, t_game *g)
{
    if (keycode == ESC)
    {
        exit (0);
    }
    if (keycode == K_W)
        g->data.w = 1;
    if (keycode == K_A)
        g->data.a = 1;
    if (keycode == K_S)
        g->data.s = 1;
    if (keycode == K_D)
	{
        g->data.d = 1;
	}
	return (0);
}

int	key_release(int keycode, t_game *g)
{
    if (keycode == K_W)
        g->data.w = 0;
    if (keycode == K_A)
        g->data.a = 0;
    if (keycode == K_S)
        g->data.s = 0;
    if (keycode == K_D)
	{
        g->data.d = 0;
	}
	return (0);
}
