/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 21:35:15 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/06 20:12:37 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		(sign == -1 && (-result) < INT_MIN))
		{
			*succes = 0;
			break ;
		}
	}
	result = result * sign;
	return ((int)result);
}

void	free_list(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	if (count > 0 && size > 9223372036854775807ULL / count)
		return (0);
	data = malloc(count * size);
	if (!data)
		return (NULL);
	ft_bzero(data, (count * size));
	return (data);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '+' || c == '-')
		return (1);
	else
		return (0);
}
