/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_tools_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 02:42:25 by azaher            #+#    #+#             */
/*   Updated: 2023/11/28 15:18:38 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// unsigned int	my_pixel_get(t_textures *text, int x, int y)
// {
//     char	dst;

// 	if (x > W_WIDTH)
// 		x = W_WIDTH;
// 	if (y > W_HEIGHT)
// 		y = W_HEIGHT;
// 	dst = text->addr + (y text->line_length + x * (text->bbp / 8));
// 	return((unsigned int)dst);
// }

// int    get_pixel_color(t_data data, int i, int h, int dir)
// {
//     double        tex_scale;
//     double        x;
//     double        y;

//     tex_scale = (double)data->text[dir].h / h;
//     if (dir == S_IDX || dir == N_IDX)
//     {
//         x = (((int)data->ray.ray_x % DISP_SIZE) data->text[dir].width) / DISP_SIZE;
//         y = (i - (W_HEIGHT / 2 - wall_height / 2)) * tex_scale;
//     }
//     if (dir == E_TEXT  dir == W_TEXT)
//     {
//         x = (((int)data->ray.ray_y % 64) * data->text[dir].w) / TILE_SIZE;
//         y = (i - (HEIGHT / 2 - h / 2)) * tex_scale;
//     }
//     if (x > data->text[dir].w  y > data->text[dir].w)
//     {
//         return (0);
//     }
//     return (my_mlx_pixel_get(&data->text[dir], x, y));
// }

int	check_collision(float x, float y, t_game *g)
{
	int	map_x;
	int	map_y;
	int	buff_x;
	int	buff_y;

	buff_x = floor((x + (DISP_SIZE / 9)) / DISP_SIZE);
	buff_y = floor((y + (DISP_SIZE / 9)) / DISP_SIZE);
	map_x = floor(x / DISP_SIZE);
	map_y = floor(y / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	buff_x = floor((x - (DISP_SIZE / 9)) / DISP_SIZE);
	buff_y = floor((y + (DISP_SIZE / 9)) / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	buff_x = floor((x - (DISP_SIZE / 9)) / DISP_SIZE);
	buff_y = floor((y - (DISP_SIZE / 9)) / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	buff_x = floor((x + (DISP_SIZE / 9)) / DISP_SIZE);
	buff_y = floor((y - (DISP_SIZE / 9)) / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	return ((g->map[map_y][map_x] == '1'));
}

int	check_ray_collision(float x, float y, t_game *g)
{
	int	map_x;
	int	map_y;

	
	map_x = floor(x / DISP_SIZE);
	map_y = floor(y / DISP_SIZE);
	return (g->map[map_y][map_x] == '1' \
			|| g->map[map_y][map_x] == '\n' \
			|| g->map[map_y][map_x] == '\0' \
			|| g->map[map_y][map_x] == ' ' );
}


int	collided_wall(float x, float y, t_game *g, int mode)
{
	float	step;
	float	cstep;
	float	p_angle;

	p_angle = g->player.player_angle + g->player.turn_dir * \
		g->player.rotation_speed;
	step = (float)g->player.walk_dir * g->player.velo;
	cstep = (float)g->player.cwalk_dir * g->player.velo;
	if (mode == 0 && step != 0)
	{
		x += cos(p_angle) * step;
		y += sin(p_angle) * step;
	}
	if (mode == 0 && (g->player.cwalk_dir == 1 || g->player.cwalk_dir == -1))
	{
		x += cos(p_angle + M_PI_2) * cstep;
		y += sin(p_angle + M_PI_2) * cstep;
	}
	if (mode == 0)
		return (check_collision(x, y, g));
	else
		return (check_ray_collision(x, y, g));
}
