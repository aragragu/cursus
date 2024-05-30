/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:51:12 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/26 04:08:23 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argument(char **argv, t_stack **list)
{
	int	i;
	int	word_count;

	i = 1;
	while (argv[i])
	{
		word_count = count_words(argv[i], ' ');
		if (word_count == 0)
		{
			write(2, "Error\n", 7);
			exit(1);
		}
		else if (!check_args(argv[i]))
		{
			write(2, "Error\n", 7);
			exit(1);
		}
		i++;
	}
	i = 1;
	while (argv[i])
		fill_stack(argv[i++], list);
}

void	fill_stack(char *argv, t_stack **list)
{
	int		i;
	int		num;
	char	**str;
	t_stack	*allo;

	num = 0;
	allo = NULL;
	i = 0;
	str = ft_split(argv, ' ');
	if (!str)
	{
		free_t_stack(list);
		exit(1);
	}
	while (str[i])
	{
		checker(str, &num, i, list);
		allo = ft_lstnew(num);
		ft_lstadd_back(list, allo);
		i++;
	}
	free_split(str);
}

void	checker(char **num, int *number, int i, t_stack **list)
{
	if (!convert_numbers(num[i], number))
	{
		free_split(num);
		free_t_stack(list);
		write(2, "Error\n", 7);
		exit(1);
	}
	if (check_list(list, *number))
	{
		free_split(num);
		free_t_stack(list);
		write(2, "Error\n", 7);
		exit(1);
	}
}

int	convert_numbers(char *str, int *num)
{
	long long	x;

	x = ft_atoi(str);
	if (x > INT_MAX || x < INT_MIN)
		return (0);
	*num = (int)x;
	return (1);
}

int	check_list(t_stack **list, int num)
{
	t_stack	*head;

	head = *list;
	while (head)
	{
		if (head->number == num)
			return (1);
		head = head->next;
	}
	return (0);
}
