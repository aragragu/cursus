/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:52:49 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/29 21:52:23 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(const char *argv)
{
	int		fd;
	int		lenght;
	char	*path;

	fd = 0;
	lenght = ft_strlen(argv);
	if (lenght >= 4 && !ft_strncmp(&argv[lenght - 4], ".ber", 4))
	{
		path = (char *)(argv);
		fd = open(path, O_RDONLY);
		if (fd == -1)
			print_error("Error: Can't open map file\n", 1);
	}
	else
		print_error("Error: Wrong map file extension\n", 1);
	return (fd);
}

int	count_element(char *whole_map, int *player, int *exit, int *collectible)
{
	int		i;

	i = 0;
	while (whole_map[i])
	{
		if (whole_map[i] == 'P')
			(*player)++;
		else if (whole_map[i] == 'E')
			(*exit)++;
		else if (whole_map[i] == 'C')
			(*collectible)++;
		else if (whole_map[i] == '\n')
		{
			if (whole_map[i + 1] == '\n')
				return (0);
		}
		else if (whole_map[i] != '1' && whole_map[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	**copy_map(t_data *allo)
{
	char	**map2;
	int		rows;
	int		i;

	rows = ft_strlen2(allo->map);
	i = 0;
	map2 = (char **)malloc((rows + 1) * sizeof(char *));
	if (!map2)
		return (NULL);
	while (allo->map[i])
	{
		map2[i] = (char *)malloc((ft_strlen(allo->map[i]) + 1) * sizeof(char));
		if (!map2[i])
		{
			free_split(map2);
			return (NULL);
		}
		copy_cols(allo->map[i], map2[i]);
		i++;
	}
	map2[rows] = NULL;
	return (map2);
}

void	copy_cols(char	*src, char	*dest)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
