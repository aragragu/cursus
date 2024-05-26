/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:09:01 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/26 05:56:59 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			if (argv[a + 1] == '+' || argv[a + 1] == '-' || argv[a + 1] == '\0')
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

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_t_stack(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
