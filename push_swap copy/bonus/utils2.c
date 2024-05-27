/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 07:20:20 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/27 02:21:02 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_words(const char *s, char c)
{
	size_t		count;
	const char	*ptr;

	count = 0;
	ptr = s;
	while (*ptr)
	{
		while (*ptr == c)
			ptr++;
		if (*ptr)
		{
			while (*ptr && *ptr != c)
				ptr++;
			count++;
		}
	}
	return (count);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (!lst || !new)
		return ;
	ptr = ft_lstlast(*lst);
	if (!ptr)
		*lst = new;
	else
		ptr->next = new;
}

void	ft_lstadd_back2(t_instruction **lst, t_instruction *new)
{
	t_instruction	*ptr;

	if (!lst || !new)
		return ;
	ptr = ft_lstlast2(*lst);
	if (!ptr)
		*lst = new;
	else
		ptr->next = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_instruction	*ft_lstlast2(t_instruction *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
