/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:51:21 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/30 04:25:47 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc >= 2)
	{
		check_argument(argv, &list_a);
		if (!check_order(&list_a))
			sort_stack(&list_a, &list_b);
		free_t_stack(&list_a);
	}
	else
		return (0);
}
