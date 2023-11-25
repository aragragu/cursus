/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:11:10 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/25 21:19:27 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void del(void *content)
{
	free(content);
}


// int main()
// {
// 	t_list *head, *current1,*current2, *new_node;


// 	head = ft_lstnew(ft_strdup("hello"));
// 	current1 = ft_lstnew(ft_strdup("hello"));
// 	current2 = ft_lstnew(ft_strdup("hello"));

// 	head->next = current1;
// 	current1->next = current2;

// 	new_node = ft_lstnew(ft_strdup("gg"));
// 	ft_lstadd_back(&head, new_node);
// 	printf("|%s|", new_node->content);
// 	ft_lstdelone(new_node, del);
// 	printf("|%s|", new_node->content);
// }