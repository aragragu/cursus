/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:53:45 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/24 16:31:27 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(t_data *allo)
{
    int x;
    int y;

    x = 0;
    y = 0;
    player_position(allo->map, &x, &y);
    if (allo->map[y - 1][x] == 'E' && !check_collectibles(allo))
        destroy_mlx(allo, 0);
    if (allo->map[y - 1][x] == '0' || allo->map[y - 1][x] == 'C')
    {
        allo->map[y - 1][x] = 'P';
        allo->map[y][x] = '0';
        allo->mouvement++;
        printf("number of mouvement is : %d\n", allo->mouvement);
    }
    mlx_clear_window(allo->mlx_ptr, allo->win_ptr);
    fill_window(allo);
    return ;
}

void    move_down(t_data *allo)
{
    int x;
    int y;

    x = 0;
    y = 0;
    player_position(allo->map, &x, &y);
    if (allo->map[y + 1][x] == 'E' && !check_collectibles(allo))
        destroy_mlx(allo, 0);
    if (allo->map[y + 1][x] == '0' || allo->map[y + 1][x] == 'C')
    {
        allo->map[y + 1][x] = 'P';
        allo->map[y][x] = '0';
        allo->mouvement++;
        printf("number of mouvement is : %d\n", allo->mouvement);
    }
    mlx_clear_window(allo->mlx_ptr, allo->win_ptr);
    fill_window(allo);
    return ;
}
void    move_right(t_data *allo)
{
    int x;
    int y;

    x = 0;
    y = 0;
    player_position(allo->map, &x, &y);
    if (allo->map[y][x + 1] == 'E' && !check_collectibles(allo))
        destroy_mlx(allo, 0);
    if (allo->map[y][x + 1] == '0' || allo->map[y][x + 1] == 'C')
    {
        allo->map[y][x + 1] = 'P';
        allo->map[y][x] = '0';
        allo->mouvement++;
        printf("number of mouvement is : %d\n", allo->mouvement);
    }
    mlx_clear_window(allo->mlx_ptr, allo->win_ptr);
    fill_window(allo);
    return ;
}
void    move_left(t_data *allo)
{
    int x;
    int y;

    x = 0;
    y = 0;
    player_position(allo->map, &x, &y);
    if (allo->map[y][x - 1] == 'E' && !check_collectibles(allo))
        destroy_mlx(allo, 0);
    if (allo->map[y][x - 1] == '0' || allo->map[y][x - 1] == 'C')
    {
        allo->map[y][x - 1] = 'P';
        allo->map[y][x] = '0';
        allo->mouvement++;
        printf("number of mouvement is : %d\n", allo->mouvement);
    }
    mlx_clear_window(allo->mlx_ptr, allo->win_ptr);
    fill_window(allo);
    return ;
}



void    player_position(char **map, int *x, int *y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[j])
    {
        while (map[j][i])
        {
            if (map[j][i] == 'P')
            {
                *y = j;
                *x = i;
                return ;
            }
            i++;
        }
        i = 0;
        j++;
    }
}

int     check_collectibles(t_data *allo)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (allo->map[y])
    {
        while (allo->map[y][x])
        {
            if (allo->map[y][x] == 'C')
                return (1);
            x++;
        }
        x = 0;
        y++;
    }
    return (0);
}