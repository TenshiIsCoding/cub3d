/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:44:11 by azaher            #+#    #+#             */
/*   Updated: 2023/09/29 18:08:58 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int main(int argc, char **argv)
{
	t_game game;
	
	if (argc != 2)
		return(ft_printf("Usage: ./cub3D [map.cub]\n"));
	init_game(&game);
	
	
}