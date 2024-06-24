/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:12:42 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/24 17:21:30 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     handle_closing(void *param)
{
    (void)param;
    write(2, "the game has been closed.\n", 26);
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
        write(2, "Escape key has been pressed. Exiting game.\n", 43);
        destroy_mlx(allo, 0);
    }
    return (0);
}

void    f()
{
    system("leaks so_long");
}

int main(int argc, char *argv[])
{
    t_data  data;
    
    if (argc == 2)
    {
        atexit(f);
        check_valid_map(&data, argv[1]);
        initialise_mlx(&data);
        mlx_key_hook(data.win_ptr, handle_input, &data);
        mlx_hook(data.win_ptr, 17, 0, handle_closing, &data);
        mlx_loop(data.mlx_ptr);
        if (!data.mlx_ptr)
            printf("mkx is not there");
        if (!data.win_ptr)
            printf("win is not there");
        destroy_mlx(&data, 0);
    }
    else
    printf("invalid args\n");
}

