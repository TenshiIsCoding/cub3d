/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:05:28 by azaher            #+#    #+#             */
/*   Updated: 2023/10/19 10:58:35 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include<stdlib.h>
# include<stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(char *c);
char	*ft_res_gnl(char *s1, char *s2, char *p);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_second(char *buf);
char	*ft_first(char	*buf);
char	*ft_read(int fd, char *buf);

#endif