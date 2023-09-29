/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:51:18 by azaher            #+#    #+#             */
/*   Updated: 2022/10/31 17:20:43 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int				ft_putchar(char c);
int				ft_putstr(char *str);
int				print_params(va_list ap, char s, int *i);
unsigned int	ft_unsigned_putnbr(unsigned int n);
int				ft_puthexa_low(unsigned int n);
int				ft_puthexa_up(unsigned int n);
int				ft_put_ptr(unsigned long n);
int				ft_printf(const char *s, ...);
int				ft_putnbr(int n);

#endif