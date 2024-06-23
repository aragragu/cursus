/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:12:42 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/23 20:03:38 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     handle_closing(void *param)
{
    (void)param;
    printf("the game has been closed\n");
    exit(0);
}

int     handle_input(int key, void *param)
{
    t_data *allo = (t_data *)param;
    
    if (key == 13 || key == 126)
        move_up(allo);
    else if (key == 1 || key == 125)
        move_down(allo);
    else if (key == 2 || key == 124)
        move_right(allo);
    else if (key == 0 || key == 123)
        move_left(allo);
    else if (key == 53)
    {
        // quit_game(allo);
        printf("the key pressed is = %d wich is escape\n", key);
        exit(0);
    }
    return (0);
}

int main(int argc, char *argv[])
{
    t_data  data;
    
    if (argc == 2)
    {
        data.map = check_valid_map(argv[1]);
        initialise_mlx(&data);
        mlx_key_hook(data.win_ptr, handle_input, &data);
        mlx_hook(data.win_ptr, 17, 0, handle_closing, &data);
        mlx_loop(data.mlx_ptr);
        
        mlx_destroy_image(data.mlx_ptr, data.win_ptr);
        mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    }
    else
    printf("invalid args\n");
}

