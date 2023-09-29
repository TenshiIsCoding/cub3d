/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:42 by azaher            #+#    #+#             */
/*   Updated: 2023/09/29 18:44:27 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libraries/ft_printf/ft_printf.h"
#include "../libraries/libft/libft.h"
#include "../libraries/queue/queue.h"
#include "../libraries/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
    char    **map;
    int     W_map;
    int     H_map;
    int     S_map;
}   t_map;

typedef struct s_player
{
    float   xpos;
    float   ypos;
    float   velocity;
    float   rotation_speed;
    float   player_angle;
}   t_player;

typedef struct s_data
{
    char    *N_texture;
    char    *E_texture;
    char    *W_texture;
    char    *S_texture;
    int     f;
    int     c;
}  t_data;

typedef struct s_game
{
    t_data  data;
    int     player_x;
    int     player_y;
    int     map_h;
    int     map_w;
    char    **map;
}   t_game;

void print_error(char *error);
void init_game(t_game *game);
int ft_strcmp(const char *s1, const char *s2);


#endif