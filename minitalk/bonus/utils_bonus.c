/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:43:44 by aragragu          #+#    #+#             */
/*   Updated: 2024/03/26 10:02:25 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str++ - '0');
	}
	if (result > 99998)
		return (0);
	return ((int)(result * sign));
}

int	checkdigits(char *s)
{
	if (*s == '\0')
		return (0);
	while ((*s <= '9') && (*s >= '0'))
		s++;
	return (*s == '\0');
}

void	bad_pid(void)
{
	ft_printf("Invalid PID");
	exit(1);
}

void	bad_pid_limit(void)
{
	ft_printf("Bad PID : PID > 99998");
	exit(1);
}

void	synthax_error(void)
{
	ft_printf("Synthax Error: <Server_PID> <Message>");
	exit(1);
}
