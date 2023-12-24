/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:01:57 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/22 15:45:12 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int i, int *count)
{
	if (i >= 10)
	{
		ft_putunsigned(i / 10, count);
	}
	ft_putchar((i % 10) + '0', count);
}
