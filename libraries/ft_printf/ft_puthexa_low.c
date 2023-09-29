/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:59:42 by azaher            #+#    #+#             */
/*   Updated: 2022/10/31 16:43:54 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_low(unsigned int n)
{
	int		i;
	char	*lowbase;

	i = 0;
	lowbase = "0123456789abcdef";
	if (n > 15)
	{
		i += ft_puthexa_low(n / 16);
		i += ft_puthexa_low(n % 16);
	}
	else
	{
		i += ft_putchar(lowbase[n]);
	}
	return (i);
}
