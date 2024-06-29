/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:47:24 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/29 13:01:24 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid_map(t_data *allo, char *argv)
{
	char	*whole_map;
	char	**map;

	whole_map = read_map(argv);
	if (!check_map(whole_map, allo))
	{
		free(whole_map);
		print_error("\n", 1);
	}
	map = ft_split(whole_map, '\n');
	if (!map_sides(map))
	{
		free(whole_map);
		free_split(map);
		print_error("\n", 1);
	}
	free(whole_map);
	whole_map = NULL;
	allo->map = map;
	flood_fill(allo);
}

char	*read_map(const char *argv)
{
	int		fd;
	char	*line;
	char	*whole_map;
	char	*tmp;

	fd = check_file(argv);
	line = get_next_line(fd);
	whole_map = ft_strdup("");
	while (line)
	{
		tmp = whole_map;
		whole_map = ft_strjoin(whole_map, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	return (whole_map);
}

int	check_map(char *whole_map, t_data *allo)
{
	int	player;
	int	collectible;
	int	exit;

	player = 0;
	collectible = 0;
	exit = 0;
	if (!whole_map || whole_map[0] == '\n')
	{
		write(2, "Error: Map is empty or starts with a newline", 44);
		return (0);
	}
	if (!count_element(whole_map, &player, &exit, &collectible))
	{
		write(2, "Error: Invalid map content", 26);
		return (0);
	}
	if (!(player == 1 && exit == 1 && collectible >= 1))
	{
		write(2, ERR_MISSING_ELEMENTS, ft_strlen(ERR_MISSING_ELEMENTS));
		return (0);
	}
	allo->collectibles = collectible;
	return (1);
}

int	map_sides(char **map)
{
	int	i;
	int	rows;
	int	cols;

	i = 0;
	rows = 0;
	cols = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != cols)
		{
			write(2, ERR_INVALID_COLS, ft_strlen(ERR_INVALID_COLS));
			return (0);
		}
		rows++;
		i++;
	}
	i = 0;
	if (!map_sides_2(map, cols, rows))
		return (0);
	return (1);
}

int	map_sides_2(char **map, int cols, int rows)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
		{
			write(2, ERR_INVALID_TOP_BOTTOM, ft_strlen(ERR_INVALID_TOP_BOTTOM));
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
		{
			write(2, ERR_INVALID_SIDES, ft_strlen(ERR_INVALID_SIDES));
			return (0);
		}
		i++;
	}
	return (1);
}
