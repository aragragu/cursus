/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:35:45 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/24 23:29:21 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c, int *count)
{
	write (1, &c, 1);
	(*count)++;
}

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

void	check_flag(va_list args, const char s, int *count)
{
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (s == 'c')
		ft_putchar(va_arg(args, int), count);
	else
		ft_putchar(s, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		count;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(ptr, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && !*(format + 1))
			break ;
		else if (*format == '%')
		{
			format++;
			check_flag(ptr, *format, &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(ptr);
	return (count);
}
