/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:44:11 by azaher            #+#    #+#             */
/*   Updated: 2023/10/30 03:03:28 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	close_window(void *param)
{
	(void)param;
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("Usage: ./cub3D [map.cub]\n"));
	game.map_h = 4;
	game.map_w = 9;
	game.map = ft_split("111111111,\
						 1P0000001,\
						 100000001,\
						 111111111", \
						 ',');
	game.data.mlx = mlx_init();
	game.data.mlx_win = mlx_new_window(game.data.mlx, game.map_w * DISP_SIZE, game.map_h * DISP_SIZE, "Cub3D");
	mlx_hook(game.data.mlx_win, 17, 0L, close_window, game.data.mlx);
	engine_start(&game, &game.player);
	mlx_loop(game.data.mlx);
	(void)argv;
}
