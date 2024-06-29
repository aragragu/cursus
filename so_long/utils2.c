/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:07:30 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/29 21:51:50 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	check_collectibles(char **allo)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (allo[y])
	{
		while (allo[y][x])
		{
			if (allo[y][x] == 'C')
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	check_xpm_path(t_data *allo)
{
	if (!allo->textures[0] || !allo->textures[1] || !allo->textures[2] \
			|| !allo->textures[3] || !allo->textures[4])
	{
		free_split(allo->map);
		free_textures(allo);
		print_error("invalid path to xpm file\n", 1);
	}
}
