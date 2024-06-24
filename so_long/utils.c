/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:52:00 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/24 19:34:49 by aragragu         ###   ########.fr       */
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

void	print_error(const char *message)
{
	write(2, message, ft_strlen(message));
	exit(1);
}

void	free_split(char	**allo)
{
	int	i;

	i = 0;
	while (allo[i])
	{
		free(allo[i++]);
	}
	free(allo);
}

void	destroy_mlx(t_data *allo, int i)
{
	if (!allo)
		print_error("Error: allo is NULL\n");
	if (!allo->map)
	{
		free_split(allo->map);
		allo->map = NULL;
	}
	if (!allo->win_ptr)
	{
		mlx_destroy_image(allo->mlx_ptr, allo->win_ptr);
		allo->win_ptr = NULL;
	}
	if (!allo->win_ptr)
	{
		mlx_destroy_window(allo->mlx_ptr, allo->win_ptr);
		allo->win_ptr = NULL;
	}
	if (i == 0)
		exit(0);
	else
		exit(1);
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
