/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 02:11:19 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/28 16:04:58 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *allo)
{
	t_player	size;
	t_player	cur;

	allo->map2 = copy_map(allo);
	allo->map3 = copy_map(allo);
	player_position(allo->map, &cur.x, &cur.y, 'P');
	size.x = ft_strlen(allo->map[0]);
	size.y = ft_strlen2(allo->map);
	if (!check_for_exit(allo->map2, size, cur) || \
		!check_for_collectibles(allo->map3, allo, size, cur))
	{
		free_split(allo->map2);
		free_split(allo->map3);
		free_split(allo->map);
		print_error("Error: Player cannot reach all parts of the map\n", 1);
	}
	free_split(allo->map2);
	free_split(allo->map3);
	if ((size.x > 163 || size.y > 163))
	{
		free_split(allo->map);
		print_error("map is too big\n", 1);
	}
}

int	check_for_exit(char **map, t_player size, t_player cur)
{
	if (!map)
		return (0);
	if (!flood_fill_exit(map, size, cur))
		return (0);
	return (1);
}

int	check_for_collectibles(char **map, t_data *allo, \
	t_player size, t_player cur)
{
	int	res;

	if (!map)
		return (0);
	res = flood_fill_collectibles(map, size, cur);
	if (res != allo->collectibles)
		return (0);
	return (1);
}

int	flood_fill_exit(char **map, t_player size, t_player cur)
{
	int	pah;

	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y \
		|| map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == 'F')
		return (false);
	if (map[cur.y][cur.x] == 'E')
		return (true);
	map[cur.y][cur.x] = 'F';
	pah = (flood_fill_exit(map, size, (t_player){cur.x - 1, cur.y})
			|| flood_fill_exit(map, size, (t_player){cur.x + 1, cur.y})
			|| flood_fill_exit(map, size, (t_player){cur.x, cur.y - 1})
			|| flood_fill_exit(map, size, (t_player){cur.x, cur.y + 1}));
	return (pah);
}

int	flood_fill_collectibles(char **map, t_player size, t_player cur)
{
	int	reached;

	reached = 0;
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y \
		|| map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == 'F' \
		|| map[cur.y][cur.x] == 'E')
		return (false);
	if (map[cur.y][cur.x] == 'C')
		reached++;
	map[cur.y][cur.x] = 'F';
	reached += flood_fill_collectibles(map, size, (t_player){cur.x + 1, cur.y});
	reached += flood_fill_collectibles(map, size, (t_player){cur.x - 1, cur.y});
	reached += flood_fill_collectibles(map, size, (t_player){cur.x, cur.y + 1});
	reached += flood_fill_collectibles(map, size, (t_player){cur.x, cur.y - 1});
	return (reached);
}
