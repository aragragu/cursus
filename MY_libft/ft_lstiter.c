/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:26:14 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/25 21:18:48 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	f(void *content)
{
	if (content)
		printf("%s\n", (char *)content);
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
// 	ft_lstiter(head, f);
// }