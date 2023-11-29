/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:14:41 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/29 19:37:58 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long		x;

	x = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		x *= -1;
	}
	if (x >= 10)
	{
		ft_putnbr_fd((x / 10), fd);
	}
	ft_putchar_fd(((x % 10) + '0'), fd);
}
