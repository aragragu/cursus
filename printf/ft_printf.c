/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:35:45 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/24 11:03:39 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag(va_list args, const char s, int *count)
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
		ft_putunsigned(va_arg(args, unsigned int), count);
	else if (s == 'x')
		ft_puthexa(va_arg(args, unsigned int), count, "0123456789abcdef");
	else if (s == 'X')
		ft_puthexa(va_arg(args, unsigned int), count, "0123456789ABCDEF");
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
