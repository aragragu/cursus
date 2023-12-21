/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:35:45 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/21 13:01:14 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	check_flag(va_list args, const char s, int *count)
{
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (s == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (s == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (s == 'p')
	{
		ft_putstr("0x", count);
		ft_putadress(va_arg(args, unsigned long), count, "0123456789abcdef");
	}
	else if (s == 'u')
		ft_putunsigned(va_arg(args, int), count);
	else if (s == 'x')
		ft_puthexa(va_arg(args, unsigned int), count, "0123456789abcdef");
	else if (s == 'X')
		ft_puthexa(va_arg(args, int), count, "0123456789ABCDEF");
	else if (s == '%')
		ft_putchar(s, count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ptr;

	count = 0;
	va_start(ptr, format);
	if (write(1, "", 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_flag(ptr, *format, &count);
		}
		else
		{
			ft_putchar(*format, &count);
		}
		format++;
	}
	return (count);
}
