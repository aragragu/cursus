/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:48:01 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/22 16:00:22 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_list(t_stack **list)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *list;
	while (current)
	{
		current->position = i;
		i++;
		current = current->next;
	}
}

void	fill_index( t_stack **list)
{
	t_stack	*current;
	t_stack	*allo;
	int		index;

	current = *list;
	index = 1;
	while (current)
	{
		allo = *list;
		while (allo)
		{
			if (current->number > allo->number)
				index++;
			allo = allo->next;
		}
		current->index = index;
		index = 1;
		current = current->next;
	}
}

int	check_order(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_stack(t_stack **list_a, t_stack **list_b)
{
	position_list(list_a);
	fill_index(list_a);
	if (ft_lstsize(*list_a) == 2)
		sort_two(list_a);
	else if (ft_lstsize(*list_a) == 3)
		sort_three(list_a);
	else if (ft_lstsize(*list_a) == 4)
		sort_four(list_a, list_b);
	else if (ft_lstsize(*list_a) == 5)
		sort_five(list_a, list_b);
	else if (ft_lstsize(*list_a) > 5 && ft_lstsize(*list_a) <= 100)
		sort_hundred(list_a, list_b);
	else if (ft_lstsize(*list_a) > 100)
		sort_hundred(list_a, list_b);
}

void	sort_two(t_stack **list)
{
	if (check_order(list))
		return ;
	if ((*list)->number > (*list)->next->number)
		sa(list);
}
