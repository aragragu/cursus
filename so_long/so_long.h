/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:09:57 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/29 21:51:57 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define ERR_INVALID_COLS \
	"Error: Inconsistent number of columns in the map"
# define ERR_INVALID_TOP_BOTTOM \
	"Error: Top or bottom border is not properly enclosed"
# define ERR_INVALID_SIDES \
	"Error: Left or right border is not properly enclosed"
# define ERR_MISSING_ELEMENTS "Error: Missing player, or exit, or collectible"

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	char		**map;
	char		**map2;
	char		**map3;
	int			mouvement;
	int			width;
	int			height;
	int			collectibles;
}	t_data;

typedef struct s_player
{
	int			x;
	int			y;
}			t_player;

void	check_valid_map(t_data *allo, char *argv);
char	*read_map(const char *argv);
char	**ft_split(char const *s, char c);
int		check_map(char *whole_map, t_data *allo);
int		map_sides(char **map);
int		map_sides_2(char **map, int cols, int rows);
void	free_split(char	**allo);
void	initialise_mlx(t_data *allo);
void	initialise_image(t_data *allo);
void	fill_window(t_data *allo);
void	put_to_window(t_data *allo, int image, int x, int y);
int		handle_input(int key, void *param);
void	player_position(char **map, int *x, int *y, char c);
void	move_up(t_data *allo);
void	move_down(t_data *allo);
void	move_right(t_data *allo);
void	move_left(t_data *allo);
int		check_collectibles(char **allo);
int		handle_closing(void *param);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_file(const char *argv);
void	print_error(const char *message, int i);
int		count_element(char *whole_map, int *player, \
		int *exit, int *collectible);
void	copy_cols(char	*src, char	*dest);
char	**copy_map(t_data *allo);
void	flood_fill(t_data *allo);
void	destroy_mlx(t_data *allo, int i);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen(const char *s);
int		ft_strlen2(char **s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_printf(const char *format, ...);
void	check_flag(va_list args, const char s, int *count);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putstr(char *s, int *count);
int		check_for_exit(char **map, t_player size, t_player cur);
int		check_for_collectibles(char **map, t_data *allo, \
		t_player size, t_player cur);
int		flood_fill_exit(char **map, t_player size, t_player cur);
int		flood_fill_collectibles(char **map, t_player size, t_player cur);
void	free_textures(t_data *allo);
void	check_xpm_path(t_data *allo);

#endif