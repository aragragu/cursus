/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:54:28 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/27 02:53:04 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	fill_instruction(char *line, t_instruction **instructions)
{
	t_instruction	*new_node;
	t_instruction	*last;

	last = ft_lstlast2(*instructions);
	if (!*instructions)
	{
		new_node = ft_lstnew2(line);
		ft_lstadd_back2(instructions, new_node);
	}
	else
	{
		new_node = ft_lstnew2(line);
		last->next = new_node;
	}
}

void	ft_error(t_instruction **instructions, t_stack **a)
{
	free_t_stack(a);
	free_instruction(instructions);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_instruction(t_instruction **head)
{
	t_instruction	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void	use_instruct(t_stack **a, t_stack **b, t_instruction **instructions)
{
	t_instruction	*current;

	current = *instructions;
	while (current)
	{
		if (ft_strncmp(current->instruction, "sa\n", 3) == 0)
			sa(a);
		else if (ft_strncmp(current->instruction, "sb\n", 3) == 0)
			sb(b);
		else if (ft_strncmp(current->instruction, "ss\n", 3) == 0)
			ss(a, b);
		else if (ft_strncmp(current->instruction, "pa\n", 3) == 0)
			pa(a, b);
		else if (ft_strncmp(current->instruction, "pb\n", 3) == 0)
			pb(a, b);
		use_instruct2(a, b, current);
		current = current->next;
	}
}
