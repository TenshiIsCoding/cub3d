/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:14:10 by azaher            #+#    #+#             */
/*   Updated: 2023/09/30 11:48:50 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!str1 || !str2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}	
	if (str1[i] > str2[i])
		return (1);
	else if (str1[i] < str2[i])
		return (-1);
	return (0);
}

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while(arr[i])
			free(arr[i++]);
		free(arr);
	}
}

int	arrlen(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while(arr[i])
			i++;
	}
	return (i);
}
