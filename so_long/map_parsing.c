/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:47:24 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/09 22:16:58 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_valid_map(char *argv)
{
	char	*whole_map;
	char	**map;


	whole_map = read_map(argv);
	if (!check_map(whole_map))
	{
		write(2, "wrong charater\n", 16);
		exit(1);
	}
	map = ft_split(whole_map, '\n');
	if (!map_sides(map))
	{
		write(2, "map sides error or line lenght\n", 32);
		exit(1);
	}
	printf("valid map\n");
	free(whole_map);
	return (map);
}

char	*read_map(const char *argv)
{
	int		fd;
	char	*line;
	char	*whole_map;
	char	*tmp;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
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

int		check_map(char *whole_map)
{
	int	player;
	int	collectible;
	int	exit;
	int i;

	player = 0;
	collectible = 0;
	exit = 0;
	i = 0;
	if(whole_map[0] == '\n')
		return (0);
	while (whole_map[i])
	{
		if (whole_map[i] == 'P')
		{
			player++;
		}
		else if (whole_map[i] == 'E')
		{
			exit++;
		}
		else if (whole_map[i] == 'C')
		{
			collectible++;
		}
		else if (whole_map[i] == '\n')
		{
			if (whole_map[i + 1] == '\n')
				return (0);
		}
		else if (whole_map[i] != '1' && whole_map[i] != '0')
			return (0);
		i++;
	}
	if (player == 1 && exit == 1 && collectible >= 1)
		return (1);
	return (0);
}

int	map_sides(char **map)
{
	int i;
	int	rows;
	int	cols;

	i = 0;
	rows = 0;
	cols = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != cols)
			return (0);
		rows++;
		i++;
	}
	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
void	free_split(char	**allo)
 {
	int	i = 0;
	while (allo[i])
	{
		free(allo[i++]);
	}
	free(allo);
 }