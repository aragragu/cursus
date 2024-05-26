/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:34:00 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/26 05:23:46 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_back(t_stack **list_a, t_stack **list_b)
{
	int		i;
	int		size;
	t_stack	*max;

	i = 0;
	size = ft_lstsize(*list_b);
	while (size > 0)
	{
		position_list(list_b);
		max = find_max(list_b);
		if (max->position <= size / 2)
		{
			while ((*list_b)->number != max->number)
				rb(list_b);
		}
		else
		{
			while ((*list_b)->number != max->number)
				rrb(list_b);
		}
		pa(list_a, list_b);
		size--;
	}
}

t_stack	*find_max(t_stack **list)
{
	t_stack	*current;
	t_stack	*max;

	current = *list;
	max = current;
	while (current)
	{
		if (current->number > max->number)
			max = current;
		current = current->next;
	}
	return (max);
}

t_stack	*find_min(t_stack **list)
{
	t_stack	*current;
	t_stack	*min;

	current = *list;
	min = current;
	while (current)
	{
		if (current->number < min->number)
			min = current;
		current = current->next;
	}
	return (min);
}
