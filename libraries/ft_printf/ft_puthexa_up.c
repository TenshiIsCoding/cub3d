/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:50:27 by azaher            #+#    #+#             */
/*   Updated: 2022/10/31 16:51:22 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_up(unsigned int n)
{
	int		i;
	char	*lowbase;

	i = 0;
	lowbase = "0123456789ABCDEF";
	if (n > 15)
	{
		i += ft_puthexa_up(n / 16);
		i += ft_puthexa_up(n % 16);
	}
	else
	{
		i += ft_putchar(lowbase[n]);
	}
	return (i);
}
