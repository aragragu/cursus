/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:51:48 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/21 12:56:55 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int n, int *count, char *s)
{
	long	nb;

	nb = (long)n;
	if (nb > 15)
	{
		ft_puthexa(nb / 16, count, s);
	}
	ft_putchar(s[nb % 16], count);
}
