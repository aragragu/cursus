/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 06:44:58 by aragragu          #+#    #+#             */
/*   Updated: 2024/03/25 01:08:27 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handler(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned char	holder;
	static int				bits;
	static int				pid;

	(void)context;
	if (siginfo->si_pid != pid)
	{
		bits = 8;
		holder = 0;
		pid = siginfo->si_pid;
	}
	if (bits == 0)
		bits = 8;
	if (signum == SIGUSR1)
		holder = holder << 1 | 1;
	else if (signum == SIGUSR2)
		holder = holder << 1;
	bits--;
	if (bits == 0)
	{
		write (1, &holder, 1);
		if (holder == '\n')
			kill(siginfo->si_pid, SIGUSR1);
		holder = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("server PID : %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
