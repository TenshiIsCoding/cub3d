/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:10:27 by azaher            #+#    #+#             */
/*   Updated: 2022/10/31 17:22:06 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_adress(unsigned long n)
{
	int		i;
	char	*lowbase;

	i = 0;
	lowbase = "0123456789abcdef";
	if (n > 15)
	{
		i += print_adress(n / 16);
		i += print_adress(n % 16);
	}
	else
	{
		i += ft_putchar(lowbase[n]);
	}
	return (i);
}

int	ft_put_ptr(unsigned long n)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += print_adress(n);
	return (i);
}
