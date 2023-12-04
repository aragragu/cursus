/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:46:05 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/04 15:32:43 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(int sign)
{
	if (sign == (-1))
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long		result;
	int					count;

	sign = 1;
	result = 0;
	count = 0;
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
		count++;
	}
	if (result < INT_MAX)
		return (result * sign);
	else if (count >= 19)
		return (check_sign(sign));
	return ((int)(result * sign));
}
