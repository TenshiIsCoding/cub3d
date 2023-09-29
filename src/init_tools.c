/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:14:47 by azaher            #+#    #+#             */
/*   Updated: 2023/09/29 19:13:23 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void init_game(t_game *game)
{
	game->map = NULL;
	game->map_h = 0;
	game->map_w = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->data.c = 0;
	game->data.f = 0;
	game->data.N_texture = NULL;
	game->data.E_texture = NULL;
	game->data.W_texture = NULL;
	game->data.S_texture = NULL;
}

int check_characters(char *line)
{
    int i;

    i = 0;
    while((line[i] && line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
        i++;
    if (line[i] && (line[i] == '1' || line[i] == '0'))
        return (0);
    return (1);
}

int read_map(t_game *game, char *map)
{
    int     fd;
    char    *line;

    if (!map || ft_strlen(map) < 5 || ft_strcmp(map + ft_strlen(map), ".cub"))
        return (0);
    fd = open(map, O_RDONLY);
    if ( fd == -1)
        return(!ft_printf("Couldn't open file\n"));
    line = get_next_line(fd);
    while(line && check_characters(line))
    {
        
    }
}
