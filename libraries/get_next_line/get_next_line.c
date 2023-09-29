/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:24:56 by azaher            #+#    #+#             */
/*   Updated: 2022/11/11 12:26:53 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nlsize(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*after_nline_store(char *buf_read)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (buf_read[i] && buf_read[i] != '\n')
		i++;
	if (!buf_read[i])
	{
		free(buf_read);
		return (NULL);
	}
	dst = ft_calloc(ft_strlen(buf_read) - i + 1, 1);
	if (!dst)
		return (NULL);
	i++;
	j = 0;
	while (buf_read[i])
		dst[j++] = buf_read[i++];
	dst[j] = '\0';
	free(buf_read);
	return (dst);
}

char	*before_nline_store(char *buf_read, char *s)
{
	size_t	i;

	i = 0;
	if (!buf_read[0])
	{
		free(s);
		return (0);
	}
	while (buf_read[i] != '\0' && buf_read[i] != '\n')
	{
		s[i] = buf_read[i];
		i++;
	}
	if (buf_read[i] == '\n')
		s[i] = '\n';
	return (s);
}

char	*read_line(char *buf_read, int fd)
{
	char	*buff;
	int		size_ret;

	size_ret = 1;
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (!ft_strchr(buff, '\n') && size_ret)
	{
		if (buff)
			size_ret = read(fd, buff, BUFFER_SIZE);
		if (!buff || size_ret == -1)
		{
			if (buff)
				free_buff(&buff);
			if (buf_read)
				free_buff(&buf_read);
			return (0);
		}
		buff[size_ret] = '\0';
		buf_read = ft_strjoin(buf_read, buff);
	}
	free_buff(&buff);
	return (buf_read);
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*buf_read;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf_read = read_line(buf_read, fd);
	if (!buf_read)
		return (0);
	i = nlsize(buf_read);
	i++;
	s = ft_calloc(i, sizeof(char));
	s = before_nline_store(buf_read, s);
	buf_read = after_nline_store(buf_read);
	return (s);
}
