/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:09:57 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/23 22:59:46 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H



# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include "get_next_line/get_next_line.h"

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	char		**map;
	char		**map2;
	int			mouvement;
}	t_data;

char	**check_valid_map(char *argv);
char	*read_map(const char *argv);
char	**ft_split(char const *s, char c);
int		check_map(char *whole_map);
int     map_sides(char **map);
int		map_sides_2(char **map, int cols, int rows);
void	free_split(char	**allo);
void    initialise_mlx(t_data *allo);
void  	initialise_image(t_data *allo);
void    fill_window(t_data *allo);
void    put_to_window(t_data *allo, int image, int x, int y);
int     handle_input(int key, void *param);
void    player_position(t_data *allo, int *x, int *y);
void    move_up(t_data *allo);
void    move_down(t_data *allo);
void    move_right(t_data *allo);
void    move_left(t_data *allo);
int     check_collectibles(t_data *allo);
int     handle_closing(void *param);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_file(const char *argv);
void	print_error(const char *message);
int		count_element(char *whole_map, int *player, int *exit, int *collectible);





#endif