/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:49:09 by azaher            #+#    #+#             */
/*   Updated: 2022/10/31 15:55:42 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_countdigits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

unsigned int	ft_unsigned_putnbr(unsigned int n)
{
	int	count;

	count = ft_countdigits(n);
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_unsigned_putnbr(n / 10);
		ft_unsigned_putnbr(n % 10);
	}
	return (count);
}
