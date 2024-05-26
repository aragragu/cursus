/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 21:29:40 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/26 06:08:27 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_stack **list_a, t_stack **list_b)
{
	t_stack	*allo;
	t_stack	*allo2;
	t_stack	*pah;
	t_stack	*pah2;

	allo = ft_lstlast(*list_a);
	allo2 = ft_lstlast(*list_b);
	pah = *list_a;
	pah2 = *list_b;
	while (pah)
	{
		if (pah->next->next == NULL)
			pah->next = NULL;
		pah = pah->next;
	}
	while (pah2)
	{
		if (pah2->next->next == NULL)
			pah2->next = NULL;
		pah2 = pah2->next;
	}
	ft_lstadd_front(list_a, allo);
	ft_lstadd_front(list_b, allo2);
	write(1, "rrr\n", 4);
}
