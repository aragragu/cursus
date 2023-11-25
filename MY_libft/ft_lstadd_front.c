/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:06:01 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/25 21:20:26 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
// int main()
// {
// 	t_list *head, *current, *new_node;

// 	head = ft_lstnew(ft_strdup("hello0"));
// 	current = ft_lstnew(ft_strdup("hello1"));
// 	head->next = current;
// 	current = ft_lstnew(ft_strdup("hello2"));
// 	head->next->next = current;
// 	current = ft_lstnew(ft_strdup("hello3"));
// 	head->next->next->next = current;
// 	new_node = ft_lstnew(ft_strdup("hello4"));
// 	ft_lstadd_front(&head, new_node);
// 	printf("%d", *(int *)head->content);
// }