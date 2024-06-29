/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:52:00 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/29 11:41:00 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	print_error(const char *message, int i)
{
	write(2, message, ft_strlen(message));
	if (i == 0)
		exit(0);
	else
		exit(1);
}

void	free_split(char	**allo)
{
	int	i;

	i = 0;
	if (allo == NULL)
		return ;
	while (allo[i])
	{
		free(allo[i++]);
	}
	free(allo);
}

void	free_textures(t_data *allo)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (allo->textures[i])
		{
			mlx_destroy_image(allo->mlx_ptr, allo->textures[i]);
			allo->textures[i] = NULL;
		}
		i++;
	}
	if (allo->win_ptr)
	{
		mlx_destroy_window(allo->mlx_ptr, allo->win_ptr);
		allo->win_ptr = NULL;
	}
	return ;
}

void	destroy_mlx(t_data *allo, int exit_code)
{
	if (!allo)
	{
		print_error("Error: allo is NULL\n", 1);
		free_split(allo->map);
		exit(exit_code);
	}
	if (allo->map)
	{
		free_split(allo->map);
		allo->map = NULL;
	}
	free_textures(allo);
	exit(exit_code);
}
