/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:12:42 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/28 17:22:11 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_closing(void *param)
{
	t_data	*allo;

	allo = (t_data *)param;
	write(2, "the game has been closed.\n", 26);
	destroy_mlx(allo, 0);
	return (0);
}

int	handle_input(int key, void *param)
{
	t_data	*allo;

	allo = (t_data *)param;
	if (key == 13 || key == 126)
		move_up(allo);
	else if (key == 1 || key == 125)
		move_down(allo);
	else if (key == 2 || key == 124)
		move_right(allo);
	else if (key == 0 || key == 123)
		move_left(allo);
	else if (key == 53)
	{
		write(2, "Escape key has been pressed. Exiting game.\n", 43);
		destroy_mlx(allo, 0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2)
	{
		check_valid_map(&data, argv[1]);
		initialise_mlx(&data);
		mlx_key_hook(data.win_ptr, handle_input, &data);
		mlx_hook(data.win_ptr, 17, 0, handle_closing, &data);
		mlx_loop(data.mlx_ptr);
		destroy_mlx(&data, 1);
	}
	else
		print_error("Invalid args\n", 1);
}
