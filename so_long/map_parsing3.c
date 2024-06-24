/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 02:11:19 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/24 19:35:21 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *allo)
{
	t_player	size;
	t_player	cur;

	player_position(allo->map2, &cur.x, &cur.y);
	size.x = ft_strlen(allo->map2[0]);
	size.y = ft_strlen2(allo->map2);
	flood(allo->map2, size, cur, '1');
	if (!check_map2(allo->map2))
	{
		write(2, "Error: Player cannot reach all parts of the map\n", 49);
		exit(1);
	}
	free_split(allo->map2);
}

void	flood(char **map, t_player size, t_player cur, char wall)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y \
		|| map[cur.y][cur.x] == wall || map[cur.y][cur.x] == 'F')
		return ;
	map[cur.y][cur.x] = 'F';
	flood(map, size, (t_player){cur.x - 1, cur.y}, wall);
	flood(map, size, (t_player){cur.x + 1, cur.y}, wall);
	flood(map, size, (t_player){cur.x, cur.y - 1}, wall);
	flood(map, size, (t_player){cur.x, cur.y + 1}, wall);
}

int	check_map2(char **whole_map)
{
	int	player;
	int	collectible;
	int	exit;
	int	i;

	player = 0;
	collectible = 0;
	exit = 0;
	i = 0;
	while (whole_map[i])
	{
		if (!count_element(whole_map[i], &player, &exit, &collectible))
			return (0);
		i++;
	}
	return (player == 0 && exit == 0 && collectible == 0);
}

int	check_collectibles(t_data *allo)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (allo->map[y])
	{
		while (allo->map[y][x])
		{
			if (allo->map[y][x] == 'C')
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	if (count > 0 && size > 9223372036854775807ULL / count)
		return (0);
	data = malloc(count * size);
	if (!data)
		return (NULL);
	ft_bzero(data, (count * size));
	return (data);
}
