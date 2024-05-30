/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 21:24:17 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/29 19:08:36 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack **list_a)
{
	t_stack	*allo;

	if (!*list_a)
		return ;
	allo = *list_a;
	*list_a = (*list_a)->next;
	allo->next = NULL;
	ft_lstadd_back(list_a, allo);
}

void	rb(t_stack **list_b)
{
	t_stack	*allo2;

	if (!*list_b)
		return ;
	allo2 = *list_b;
	*list_b = (*list_b)->next;
	allo2->next = NULL;
	ft_lstadd_back(list_b, allo2);
}

void	rr(t_stack **list_a, t_stack **list_b)
{
	t_stack	*allo;
	t_stack	*allo2;

	if (!*list_a || !*list_b)
		return ;
	allo = *list_a;
	allo2 = *list_b;
	*list_a = (*list_a)->next;
	*list_b = (*list_b)->next;
	allo->next = NULL;
	allo2->next = NULL;
	ft_lstadd_back(list_a, allo);
	ft_lstadd_back(list_b, allo2);
}

void	rra(t_stack **list_a)
{
	t_stack	*allo;
	t_stack	*pah;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return ;
	allo = *list_a;
	pah = NULL;
	while (allo->next)
	{
		pah = allo;
		allo = allo->next;
	}
	allo = ft_lstlast(*list_a);
	pah->next = NULL;
	allo->next = *list_a;
	*list_a = allo;
}

void	rrb(t_stack **list_b)
{
	t_stack	*allo2;
	t_stack	*pah2;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return ;
	allo2 = *list_b;
	pah2 = NULL;
	while (allo2->next)
	{
		pah2 = allo2;
		allo2 = allo2->next;
	}
	allo2 = ft_lstlast(*list_b);
	pah2->next = NULL;
	allo2->next = *list_b;
	*list_b = allo2;
}
