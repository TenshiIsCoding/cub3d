/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:05:28 by azaher            #+#    #+#             */
/*   Updated: 2022/11/08 14:01:57 by azaher           ###   ########.fr       */
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

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_mstrcat(char *s1, char *s2, char *dest);
char	*ft_strjoin(char *s1, char *s2);
void	free_buff(char **p);
char	*get_next_line(int fd);

#endif