/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:18:53 by azaher            #+#    #+#             */
/*   Updated: 2022/11/03 09:58:16 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_increment(int *i)
{
	*i = *i + 2;
	return (1);
}

int	print_params(va_list ap, char s, int *i)
{
	int	n;

	n = 0;
	if (s == 'c' && ft_increment(i))
		n += ft_putchar(va_arg(ap, int));
	else if (s == 's' && ft_increment(i))
		n += ft_putstr(va_arg(ap, char *));
	else if ((s == 'd' || s == 'i') && ft_increment(i))
		n += ft_putnbr(va_arg(ap, int));
	else if (s == 'u' && ft_increment(i))
		n += ft_unsigned_putnbr(va_arg(ap, unsigned int));
	else if (s == 'x' && ft_increment(i))
		n += ft_puthexa_low(va_arg(ap, unsigned int));
	else if (s == 'X' && ft_increment(i))
		n += ft_puthexa_up(va_arg(ap, unsigned int));
	else if (s == '%' && ft_increment(i))
		n += ft_putchar('%');
	else if (s == 'p' && ft_increment(i))
		n += ft_put_ptr(va_arg(ap, unsigned long));
	else
	{
		ft_increment(i);
		return (ft_putchar(s));
	}
	return (n);
}
