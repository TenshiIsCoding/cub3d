/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:46:52 by adadoun           #+#    #+#             */
/*   Updated: 2023/11/23 10:49:22 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	skip_whitespace(char	*arr, int i)
{
	while (arr[i] && (arr[i] == 9 || arr[i] == 32))
		i++;
	return (i);
}

void	check_free_lines(char *arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		if (arr[i] == '\n')
		{
			i = skip_whitespace(arr, ++i);
			if (arr[i] == '\0' || arr[i] == '\n')
				func_error("Empty line in your map");
		}
	}
}

char	*get_map(t_parsing *s_pars)
{
	char	*temp1;

	temp1 = get_next_line(s_pars->fd);
	while (temp1 && s_pars->num_info < 6)
	{
		parse_info(s_pars, temp1);
		temp1 = get_next_line(s_pars->fd);
	}
	if (s_pars->num_info < 6 || !temp1)
		func_error("Make sure all ur infos and your map exist");
	while (temp1 && empty_line(temp1))
	{
		free(temp1);
		temp1 = get_next_line(s_pars->fd);
	}
	if (!temp1)
		func_error("Make sure you have a map in your file");
	parse_map(s_pars, temp1);
	return ("DONE");// i should change it
}

char	*parsing(int argc, char **av)
{
	t_parsing	s_pars;

	if (argc != 2)
		func_error("Usage: ./cub3D [map.cub]");
	s_pars.fd = check_file_name(av[1]);
	init_struct(&s_pars);
	get_map(&s_pars);
	// printf("info[3] = %s\n", *(s_pars.info[3].value));
	// printf("info[2] = %s\n", *(s_pars.info[2].value));
	// printf("info[1] = %s\n", *(s_pars.info[1].value));
	// printf("info[0] = %s\n", *(s_pars.info[0].value));
	// printf("info f  = %i\n", s_pars.f_color);
	// printf("info c  = %i\n", s_pars.c_color);
	// int i = -1;
	// while(s_pars.map_2d[++i])
	// 	printf("%s\n", s_pars.map_2d[i]);
	free(s_pars.no);
	free(s_pars.so);
	free(s_pars.we);
	free(s_pars.ea);
	free(s_pars.f);
	free(s_pars.c);
	free(s_pars.info);
	free_2d(s_pars.map_2d);
	close (s_pars.fd);//check why we should close fd
	return ("DONE");
}
