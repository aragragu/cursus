/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_intialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:02:23 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/24 23:12:03 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialise_image(t_data *allo)
{
	char	*background;
	char	*coin;
	char	*door;
	char	*player;
	char	*wall;

	background = "images/background.xpm";
	coin = "images/coin5.xpm";
	door = "images/door.xpm";
	player = "images/player.xpm";
	wall = "images/wall.xpm";
	allo->width = 50;
	allo->height = 50;
	allo->textures[0] = mlx_xpm_file_to_image(allo->mlx_ptr, background, \
		&allo->width, &allo->height);
	allo->textures[1] = mlx_xpm_file_to_image(allo->mlx_ptr, coin, \
		&allo->width, &allo->height);
	allo->textures[2] = mlx_xpm_file_to_image(allo->mlx_ptr, door, \
		&allo->width, &allo->height);
	allo->textures[3] = mlx_xpm_file_to_image(allo->mlx_ptr, player, \
		&allo->width, &allo->height);
	allo->textures[4] = mlx_xpm_file_to_image(allo->mlx_ptr, wall, \
		&allo->width, &allo->height);
}

void	initialise_mlx(t_data *allo)
{
	int	lenght;
	int	weidth;

	allo->mlx_ptr = mlx_init();
	if (!allo->mlx_ptr)
		print_error("MLX ERROR\n");
	allo->mouvement = 0;
	lenght = ft_strlen(allo->map[0]) * 50;
	weidth = ft_strlen2(allo->map) * 50;
	allo->win_ptr = mlx_new_window(allo->mlx_ptr, lenght, weidth, "so_long");
	if (!allo->win_ptr)
	{
		free(allo->win_ptr);
		print_error("MLX ERROR\n");
	}
	initialise_image(allo);
	fill_window(allo);
}

void	fill_window(t_data *allo)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (allo->map[y])
	{
		while (allo->map[y][x])
		{
			if (allo->map[y][x] == '1')
				put_to_window(allo, 4, x, y);
			else if (allo->map[y][x] == '0')
				put_to_window(allo, 0, x, y);
			else if (allo->map[y][x] == 'P')
				put_to_window(allo, 3, x, y);
			else if (allo->map[y][x] == 'C')
				put_to_window(allo, 1, x, y);
			else if (allo->map[y][x] == 'E')
				put_to_window(allo, 2, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	put_to_window(t_data *allo, int image, int x, int y)
{
	if (allo->map[y][x] == 'P' || allo->map[y][x] == 'C')
		mlx_put_image_to_window(allo->mlx_ptr, allo->win_ptr, \
			allo->textures[0], (x * 50), (y * 50));
	else if (allo->map[y][x] == 'E')
		mlx_put_image_to_window(allo->mlx_ptr, allo->win_ptr, \
			allo->textures[4], (x * 50), (y * 50));
	mlx_put_image_to_window(allo->mlx_ptr, allo->win_ptr, \
		allo->textures[image], (x * 50), (y * 50));
}
