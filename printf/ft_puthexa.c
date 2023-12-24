/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:51:48 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/22 15:46:51 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int n, int *count, char *s)
{
	if (n > 15)
	{
		ft_puthexa(n / 16, count, s);
	}
	ft_putchar(s[n % 16], count);
}
