/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:53:45 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/29 20:09:03 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *allo)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	player_position(allo->map, &x, &y, 'P');
	if (allo->map[y - 1][x] == 'E' && !check_collectibles(allo->map))
	{
		allo->mouvement++;
		ft_printf("number of mouvement is : %d\n", allo->mouvement);
		ft_printf("player has finished the game\n");
		destroy_mlx(allo, 0);
	}
	if (allo->map[y - 1][x] == '0' || allo->map[y - 1][x] == 'C')
	{
		allo->map[y - 1][x] = 'P';
		allo->map[y][x] = '0';
		allo->mouvement++;
		ft_printf("number of mouvement is : %d\n", allo->mouvement);
	}
	mlx_clear_window(allo->mlx_ptr, allo->win_ptr);
	fill_window(allo);
	return ;
}

void	move_down(t_data *allo)
{
	int			x;
	int			y;
	t_player	exit;

	x = 0;
	y = 0;
	player_position(allo->map, &x, &y, 'P');
	player_position(allo->map, &exit.x, &exit.y, 'E');
	if (allo->map[y + 1][x] == 'E' && !check_collectibles(allo->map))
	{
		allo->mouvement++;
		ft_printf("number of mouvement is : %d\n", allo->mouvement);
		ft_printf("player has finished the game\n");
		destroy_mlx(allo, 0);
	}
	if (allo->map[y + 1][x] == '0' || allo->map[y + 1][x] == 'C')
	{
		allo->map[y + 1][x] = 'P';
		allo->map[y][x] = '0';
		allo->mouvement++;
		ft_printf("number of mouvement is : %d\n", allo->mouvement);
	}
	mlx_clear_window(allo->mlx_ptr, allo->win_ptr);
	fill_window(allo);
	return ;
}

void	move_right(t_data *allo)
{
	int			x;
	int			y;
	t_player	exit;

	x = 0;
	y = 0;
	player_position(allo->map, &x, &y, 'P');
	player_position(allo->map, &exit.x, &exit.y, 'E');
	if (allo->map[y][x + 1] == 'E' && !check_collectibles(allo->map))
	{
		allo->mouvement++;
		ft_printf("number of mouvement is : %d\n", allo->mouvement);
		ft_printf("player has finished the game\n");
		destroy_mlx(allo, 0);
	}
	if (allo->map[y][x + 1] == '0' || allo->map[y][x + 1] == 'C')
	{
		allo->map[y][x + 1] = 'P';
		allo->map[y][x] = '0';
		allo->mouvement++;
		ft_printf("number of mouvement is : %d\n", allo->mouvement);
	}
	mlx_clear_window(allo->mlx_ptr, allo->win_ptr);
	fill_window(allo);
	return ;
}

void	move_left(t_data *allo)
{
	int			x;
	int			y;
	t_player	exit;

	x = 0;
	y = 0;
	player_position(allo->map, &x, &y, 'P');
	player_position(allo->map, &exit.x, &exit.y, 'E');
	if (allo->map[y][x - 1] == 'E' && !check_collectibles(allo->map))
	{
		allo->mouvement++;
		ft_printf("number of mouvement is : %d\n", allo->mouvement);
		ft_printf("player has finished the game\n");
		destroy_mlx(allo, 0);
	}
	if (allo->map[y][x - 1] == '0' || allo->map[y][x - 1] == 'C')
	{
		allo->map[y][x - 1] = 'P';
		allo->map[y][x] = '0';
		allo->mouvement++;
		ft_printf("number of mouvement is : %d\n", allo->mouvement);
	}
	mlx_clear_window(allo->mlx_ptr, allo->win_ptr);
	fill_window(allo);
	return ;
}

void	player_position(char **map, int *x, int *y, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == c)
			{
				*y = j;
				*x = i;
				return ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
