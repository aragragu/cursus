/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:18:36 by aragragu          #+#    #+#             */
/*   Updated: 2024/11/29 20:47:40 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	valid_numbers(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!check_args(argv[i]))
		{
			my_perror("invalid argc\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str, int *succes)
{
	int					sign;
	long long			result;

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
		if ((sign == 1 && result > INT_MAX) || \
		(sign == -1))
		{
			*succes = 0;
			break ;
		}
	}
	result = result * sign;
	return ((int)result);
}
