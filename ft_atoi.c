/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:46:05 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/29 18:35:04 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_num(int sign)
{
	if (sign == (-1))
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;
	int				count;

	i = 0;
	sign = 1;
	result = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		count++;
	}
	if (result > __LONG_MAX__ && count >= 20)
		return (check_num(sign));
	return (result * sign);
}
