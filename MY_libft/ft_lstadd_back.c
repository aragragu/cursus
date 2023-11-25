/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:34:37 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/25 19:56:39 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst)
		return ;
	ptr = ft_lstlast(*lst);
	if (!ptr)
		*lst = new;
	else
		ptr->next = new;
}


// int main()
// {
// 	t_list *head, *current, *new_node, *xd;
// 	int a, b, c, d, e;

// 	a = 1;
// 	b = 2;
// 	c = 3;
// 	d = 4;
// 	e = 5;

// 	head = ft_lstnew(&a);
// 	current = ft_lstnew(&b);
// 	head->next = current;
// 	current = ft_lstnew(&c);
// 	head->next->next = current;
// 	current = ft_lstnew(&d);
// 	head->next->next->next = current;
// 	new_node = ft_lstnew(&e);
// 	ft_lstadd_back(&head, new_node);
// 	xd = ft_lstlast(head);
// 	printf("%d", *(int *)xd->content);
// }