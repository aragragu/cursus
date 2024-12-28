/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:03:29 by aragragu          #+#    #+#             */
/*   Updated: 2024/11/28 16:41:22 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->forks)
		free(data->forks);
	data->forks = NULL;
	if (data->philos)
		free(data->philos);
	data->philos = NULL;
	free(data);
	data = NULL;
}

void	my_perror(char *str)
{
	write(2, str, ft_strlen(str));
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int	check_args(char *argv)
{
	int	a;

	a = 0;
	if (argv[0] == '\0')
		return (0);
	while (argv[a])
	{
		if (!ft_isdigit(argv[a]))
			return (0);
		else if (argv[a] == '+' || argv[a] == '-')
		{
			if (argv[a + 1] == '+' || argv[a + 1] == '-' || argv[a + 1] == '\0' \
			|| argv[a + 1] == ' ')
				return (0);
		}
		else if (argv[a] >= '0' && argv[a] <= '9')
		{
			if (argv[a + 1] == '+' || argv[a + 1] == '-')
				return (0);
		}
		a++;
	}
	return (1);
}
