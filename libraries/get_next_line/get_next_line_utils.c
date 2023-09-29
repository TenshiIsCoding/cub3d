/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:15:53 by azaher            #+#    #+#             */
/*   Updated: 2022/11/11 12:10:10 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	p = malloc(count * size);
	i = 0;
	if (!p)
		return (0);
	if (p)
	{
		while (i < count)
		{
			*((char *)p + i) = 0;
			i++;
		}
	}
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	s1len;

	if (s1)
		s1len = ft_strlen(s1);
	else
		s1len = 0;
	i = 0;
	j = 0;
	dest = ft_calloc((s1len + ft_strlen(s2) + 1), sizeof(char));
	if (!dest)
		return (0);
	while (i < s1len)
	{
		dest[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		dest[i++] = *(s2 + j++);
	free_buff(&s1);
	return (dest);
}

void	free_buff(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}
