/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 02:16:38 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/27 02:54:56 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_lstnew1(int i)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = i;
	new_node->next = NULL;
	return (new_node);
}

t_instruction	*ft_lstnew2(char *line)
{
	t_instruction	*new_node;

	new_node = (t_instruction *)malloc(sizeof(t_instruction));
	if (!new_node)
		return (NULL);
	new_node->instruction = line;
	new_node->next = NULL;
	return (new_node);
}

void	use_instruct2(t_stack **a, t_stack **b, t_instruction *current)
{
	if (ft_strncmp(current->instruction, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(current->instruction, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(current->instruction, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(current->instruction, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(current->instruction, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(current->instruction, "rrr\n", 4) == 0)
		rrr(a, b);
}

int	check_order(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
