/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:44:11 by azaher            #+#    #+#             */
/*   Updated: 2023/11/22 10:07:25 by azaher           ###   ########.fr       */
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
	game.map_h = 6;
	game.map_w = 6;
	game.map = ft_split("111111,100S01,100001,100001,100001,111111",',');
	// game.map = ft_split("11111111 ,100000101,10S000011,101001011,111111111",',');
	game.data.mlx = mlx_init();
	game.data.mlx_win = mlx_new_window(game.data.mlx, W_WIDTH, W_HEIGHT, "Cub3D");
	mlx_hook(game.data.mlx_win, 17, 0, close_window, &game.data);
	engine_start(&game, &game.player);
	mlx_hook(game.data.mlx_win, 2, 1L << 0, key_press, &game.data);
	mlx_hook(game.data.mlx_win, 3, 1L << 1, key_release, &game.data);
	mlx_loop_hook(game.data.mlx ,&update_player, &game);
	mlx_loop(game.data.mlx);
	(void)argv;
}
