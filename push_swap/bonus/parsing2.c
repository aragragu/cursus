/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:09:01 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/11 18:17:51 by aragragu         ###   ########.fr       */
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

void	free_t_stack(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	if (!a || !*a)
		return ;
	current = *a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*a = NULL;
}

void	ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*tmp;

	if (!del || !lst)
		return ;
	tmp = *lst;
	if (lst && *lst)
	{
		while (tmp)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
	}
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '+' || c == '-')
		return (1);
	else
		return (0);
}
