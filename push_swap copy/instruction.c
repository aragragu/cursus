/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:56:56 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/26 03:43:12 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **list_a)
{
	int		i;
	t_stack	*allo;

	allo = *list_a;
	if (!allo || !allo->next)
		return ;
	i = allo->number;
	allo->number = allo->next->number;
	allo->next->number = i;
	write(1, "sa\n", 3);
}

void	sb(t_stack **list_b)
{
	int		g;
	t_stack	*allo;

	allo = *list_b;
	if (!allo || !allo->next)
		return ;
	g = allo->number;
	allo->number = allo->next->number;
	allo->next->number = g;
	write(1, "sb\n", 3);
}

void	ss(t_stack **list_a, t_stack **list_b)
{
	int		i;
	int		g;
	t_stack	*allo;
	t_stack	*allo2;

	allo = *list_a;
	allo2 = *list_b;
	if (!allo || !allo->next)
		return ;
	i = allo->number;
	allo->number = allo->next->number;
	allo->next->number = i;
	if (!allo2 || !allo2->next)
		return ;
	g = allo2->number;
	allo2->number = allo2->next->number;
	allo2->next->number = g;
	write(1, "ss\n", 3);
}

void	pa(t_stack **list_a, t_stack **list_b)
{
	t_stack	*allo;

	if (!list_b)
		return ;
	allo = *list_b;
	*list_b = (*list_b)->next;
	allo->next = NULL;
	ft_lstadd_front(list_a, allo);
	write(1, "pa\n", 3);
}

void	pb(t_stack **list_a, t_stack **list_b)
{
	t_stack	*allo;

	if (!list_a)
		return ;
	allo = *list_a;
	*list_a = (*list_a)->next;
	allo->next = NULL;
	ft_lstadd_front(list_b, allo);
	write(1, "pb\n", 3);
}
