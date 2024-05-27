/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 21:24:17 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/27 02:15:31 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack **list_a)
{
	t_stack	*allo;

	allo = *list_a;
	*list_a = (*list_a)->next;
	allo->next = NULL;
	ft_lstadd_back(list_a, allo);
}

void	rb(t_stack **list_b)
{
	t_stack	*allo2;

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

	allo = ft_lstlast(*list_a);
	pah = *list_a;
	while (pah)
	{
		if (pah->next->next == NULL)
			pah->next = NULL;
		pah = pah->next;
	}
	ft_lstadd_front(list_a, allo);
}

void	rrb(t_stack **list_b)
{
	t_stack	*allo2;
	t_stack	*pah2;

	allo2 = ft_lstlast(*list_b);
	pah2 = *list_b;
	while (pah2)
	{
		if (pah2->next->next == NULL)
			pah2->next = NULL;
		pah2 = pah2->next;
	}
	ft_lstadd_front(list_b, allo2);
}
