/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:56:56 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/27 02:15:09 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack **list_a)
{
	int		i;
	t_stack	*allo;

	if (!list_a)
		return ;
	allo = *list_a;
	if (!allo || !allo->next)
		return ;
	i = allo->number;
	allo->number = allo->next->number;
	allo->next->number = i;
}

void	sb(t_stack **list_b)
{
	int		g;
	t_stack	*allo;

	if (!list_b)
		return ;
	allo = *list_b;
	if (!allo || !allo->next)
		return ;
	g = allo->number;
	allo->number = allo->next->number;
	allo->next->number = g;
}

void	ss(t_stack **list_a, t_stack **list_b)
{
	int		i;
	int		g;
	t_stack	*allo;
	t_stack	*allo2;

	if (!list_a || !list_b)
		return ;
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
}

void	pa(t_stack **list_a, t_stack **list_b)
{
	t_stack	*allo;

	if (!list_b || !*list_b || !list_a)
		return ;
	allo = *list_b;
	*list_b = (*list_b)->next;
	allo->next = NULL;
	ft_lstadd_front(list_a, allo);
}

void	pb(t_stack **list_a, t_stack **list_b)
{
	t_stack	*allo;

	if (!list_a || !*list_a || !list_b)
		return ;
	allo = *list_a;
	*list_a = (*list_a)->next;
	allo->next = NULL;
	ft_lstadd_front(list_b, allo);
}
