/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:01:57 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/21 12:56:12 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(int i, int *count)
{
	unsigned int	nb;

	nb = (unsigned)i;
	if (nb >= 10)
	{
		ft_putunsigned(nb / 10, count);
	}
	ft_putchar((nb % 10) + '0', count);
}
