/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:30:56 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/30 16:56:42 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **list)
{
	if (check_order(list))
		return ;
	position_list(list);
	if (find_max(list)->position == 0)
	{
		ra(list);
		sort_two(list);
	}
	else if (find_max(list)->position == 1)
	{
		rra(list, 1);
		sort_two(list);
	}
	else
		sort_two(list);
}

void	sort_four(t_stack **list_a, t_stack **list_b)
{
	t_stack	*min;

	min = find_min(list_a);
	if (check_order(list_a))
		return ;
	while (min->number != (*list_a)->number)
	{
		if (min->position <= ft_lstsize(*list_a) / 2)
			ra(list_a);
		else
			rra(list_a, 1);
		position_list(list_a);
	}
	if (check_order(list_a))
		return ;
	pb(list_a, list_b);
	position_list(list_a);
	sort_three(list_a);
	pa(list_a, list_b);
}

void	sort_five(t_stack **list_a, t_stack **list_b)
{
	t_stack	*min;

	min = find_min(list_a);
	if (check_order(list_a))
		return ;
	while (min->number != (*list_a)->number)
	{
		if (min->position <= ft_lstsize(*list_a) / 2)
			ra(list_a);
		else
			rra(list_a, 1);
		position_list(list_a);
	}
	pb(list_a, list_b);
	position_list(list_a);
	sort_four(list_a, list_b);
	pa(list_a, list_b);
}

void	sort_hundred(t_stack **list_a, t_stack **list_b)
{
	push_to_b(list_a, list_b);
	bring_back(list_a, list_b);
}

void	push_to_b(t_stack **list_a, t_stack **list_b)
{
	int	x;
	int	i;

	i = 0;
	if (ft_lstsize(*list_a) <= 100)
		x = 16;
	else
		x = 36;
	while (ft_lstsize(*list_a) > 0)
	{
		if ((*list_a)->index <= i)
		{
			pb(list_a, list_b);
			i++;
		}
		else if ((*list_a)->index <= i + x)
		{
			pb(list_a, list_b);
			rb(list_b);
			i++;
		}
		else
			ra(list_a);
	}
}
