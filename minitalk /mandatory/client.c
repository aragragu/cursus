/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:34:41 by aragragu          #+#    #+#             */
/*   Updated: 2024/03/25 00:33:35 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	check_sign(int sign)
{
	if (sign == (-1))
		return (0);
	return (-1);
}

static int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

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
		if (result > (9223372036854775807ULL - (*str - '0')) / 10)
			return (check_sign(sign));
		result = result * 10 + (*str++ - '0');
	}
	return ((int)(result * sign));
}

static void	send_byte(char c, int server_pid)
{
	int	k;
	int	a;

	a = 7;
	while (a >= 0)
	{
		if (((c >> a) & 1) == 1)
			k = kill(server_pid, SIGUSR1);
		else if (((c >> a) & 1) == 0)
			k = kill(server_pid, SIGUSR2);
		a--;
		usleep(1000);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		server_pid;
	char	*message;

	if (argc == 3)
	{
		i = 0;
		server_pid = ft_atoi(argv[1]);
		message = argv[2];
		while (message[i])
		{
			send_byte(message[i], server_pid);
			i++;
		}
		send_byte('\n', server_pid);
	}
	else
		ft_printf("usage: <server_pid> <message>");
	return (0);
}
