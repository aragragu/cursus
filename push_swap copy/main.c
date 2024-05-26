/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:51:21 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/26 04:43:18 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack1(t_stack **stack)
{
    t_stack *current = *stack;
    while (current)
    {
        printf("||%d||\t ||%d|| \t ||%d||\n", current->number, current->index, current->position);
        current = current->next;
    }
    printf("\n");
}


int main(int argc, char *argv[]) 
{
    t_stack *list_a;
    t_stack *list_b;
    
    list_a = NULL;
    list_b = NULL;
    if (argc >= 2) 
    {
        check_argument(argv, &list_a);
        if (!check_order(&list_a))
            sort_stack(&list_a, &list_b);
        // print_stack1(&list_a);
        // print_stack1(&list_a);
        free_t_stack(&list_a);
        free_t_stack(&list_b);
    } 
    else 
        return 0;

}
