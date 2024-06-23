/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:52:49 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/23 22:55:42 by aragragu         ###   ########.fr       */
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
	path = ft_strdup("");
	if (lenght >= 4 && !ft_strncmp(&argv[lenght - 4], ".ber", 4))
	{
		path = ft_strjoin(path, (char *)(argv));
		fd = open(path, O_RDONLY);
		free(path);
		if (fd == -1)
			print_error("Error: Can't open map file\n");
	}
	else
		print_error("Error: Wrong map file extension\n");
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
