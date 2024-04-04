/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 06:43:10 by aragragu          #+#    #+#             */
/*   Updated: 2024/03/26 03:12:45 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_byte(char c, int server_pid)
{
	int	a;

	a = 7;
	while (a >= 0)
	{
		if (((c >> a) & 1) == 1)
		{
			if (kill(server_pid, SIGUSR1) != 0)
			{
				ft_printf("Kill Error or Invalid PID");
				exit(1);
			}
		}
		else if (((c >> a) & 1) == 0)
		{
			if (kill(server_pid, SIGUSR2) != 0)
			{
				ft_printf("Kill Error or Invalid PID");
				exit(1);
			}
		}
		a--;
		usleep(1000);
	}
}

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message Received Successfully");
}

int	main(int argc, char *argv[])
{
	int		i;
	int		server_pid;
	char	*message;

	if (argc == 3)
	{
		i = 0;
		signal(SIGUSR1, handler);
		if (checkdigits(argv[1]) == 0)
			bad_pid();
		server_pid = ft_atoi(argv[1]);
		if (server_pid == 0)
			bad_pid_limit();
		message = argv[2];
		while (message[i])
		{
			send_byte(message[i++], server_pid);
		}
		send_byte('\n', server_pid);
	}
	else
		synthax_error();
	return (0);
}
