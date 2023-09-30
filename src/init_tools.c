/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:14:47 by azaher            #+#    #+#             */
/*   Updated: 2023/09/30 14:43:31 by azaher           ###   ########.fr       */
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

int store_check(char **arr, t_data *data)
{
	if (arrlen(arr) != 2)
		return (!ft_printf("cub3D: Invalid element\n"));
	if(!ft_strcmp(arr[0], "NO") && !data->N_texture)
		data->N_texture = ft_strdup(arr[1]);
	else if(!ft_strcmp(arr[0], "EA") && !data->N_texture)
		data->E_texture = ft_strdup(arr[1]);
	else if(!ft_strcmp(arr[0], "WE") && !data->N_texture)
		data->W_texture = ft_strdup(arr[1]);
	else if(!ft_strcmp(arr[0], "SO") && !data->N_texture)
		data->S_texture = ft_strdup(arr[1]);
	else if(!ft_strcmp(arr[0], "F") && !data->N_texture)
	{
		if (parse_color(&data, arr[1], 'F'))
			return (!ft_printf("cub3D: Invalid color\n"));
	}
	else if(!ft_strcmp(arr[0], "C") && !data->N_texture)
	{
		if (parse_color(&data, arr[1], 'C'))
			return (!ft_printf("cub3D: Invalid color\n"));
	}
	else
		return (!ft_printf("cub3D: Invalid element\n"));
}

int check_new_elements(char *line, t_data *data)
{
	char	*tmp;
	char	**arr;

	tmp = line;
	if (tmp[0] != '\n')
	{
		line = ft_strtrim(line, "\n");
		free(tmp);
	}
	else if (tmp[0] == '\n')
		return(free(line), 1);
	arr = ft_split(line, ' ');
	free(line);
	if (store_check(arr, &data))
	{}
}

int read_map(t_game *game, char *map)
{
	int		fd;
	char	*line;

	if (!map || ft_strlen(map) < 5 || ft_strcmp(map + ft_strlen(map), ".cub"))
		return (0);
	fd = open(map, O_RDONLY);
	if ( fd == -1)
		return(!ft_printf("Couldn't open file\n"));
	line = get_next_line(fd);
	while(line && check_characters(line))
	{
		if (!check_new_elements(line, &game->data))
			return (0);
		
	}
}
