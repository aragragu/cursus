/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:18:07 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/19 16:11:21 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, count);
	}
	ft_putchar((nb % 10) + '0', count);
}
