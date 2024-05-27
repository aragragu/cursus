/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 21:29:40 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/27 03:21:25 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **list_a, t_stack **list_b)
{
	t_stack	*allo;
	t_stack	*allo2;
	t_stack	*pah;
	t_stack	*pah2;

	if (!list_a || !list_b)
		return ;
	allo = ft_lstlast(*list_a);
	allo2 = ft_lstlast(*list_b);
	pah = *list_a;
	pah2 = *list_b;
	while_loop(pah);
	while_loop(pah2);
	ft_lstadd_front(list_a, allo);
	ft_lstadd_front(list_b, allo2);
	write(1, "rrr\n", 4);
}

void	while_loop(t_stack *pah)
{
	while (pah)
	{
		if (pah->next->next == NULL)
			pah->next = NULL;
		pah = pah->next;
	}
}
