/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:55:24 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/23 18:04:15 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	check_flag(va_list args, const char s, int *count);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putstr(char *s, int *count);
void	ft_puthexa(unsigned int n, int *count, char *s);
void	ft_putunsigned(unsigned int i, int *count);
void	ft_putadress(unsigned long n, int *count, char *s);

#endif
