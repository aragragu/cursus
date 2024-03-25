/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:13:07 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/28 16:34:37 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putadress(unsigned long n, int *count, char *s)
{
	if (n > 15)
	{
		ft_putadress(n / 16, count, s);
	}
	ft_putchar(s[n % 16], count);
}
