/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:45:36 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/27 03:19:49 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_in(char *line, t_instruction **instructions, t_stack **a)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		fill_instruction(line, instructions);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		fill_instruction(line, instructions);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		fill_instruction(line, instructions);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		fill_instruction(line, instructions);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		fill_instruction(line, instructions);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		fill_instruction(line, instructions);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		fill_instruction(line, instructions);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		fill_instruction(line, instructions);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		fill_instruction(line, instructions);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		fill_instruction(line, instructions);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		fill_instruction(line, instructions);
	else
		ft_error(instructions, a);
}

void	final_check(t_stack **a, t_stack **b)
{
	if (check_order(a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_t_stack(a);
	free_t_stack(b);
}

int	main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;
	t_instruction	*instructions;
	char			*line;

	a = NULL;
	b = NULL;
	instructions = NULL;
	if (argc >= 2)
	{
		line = get_next_line(0);
		check_argument(argv, &a);
		while (line)
		{
			check_in(line, &instructions, &a);
			line = get_next_line(0);
			if (!line)
				break ;
		}
		use_instruct(&a, &b, &instructions);
		final_check(&a, &b);
	}
	else
		write(2, "Error\n", 6);
}
