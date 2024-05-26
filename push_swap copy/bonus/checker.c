/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:45:36 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/26 07:42:26 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    check_instruction(char *line, t_instruction **instructions, t_stack **a)
{
    if (ft_strncmp(line, "sa", 2) == 0)
        fill_instruction(line, instructions, SA);
    else if (ft_strncmp(line, "sb", 2) == 0)
        fill_instruction(line, instructions, SB);
    else if (ft_strncmp(line, "ss", 2) == 0)
        fill_instruction(line, instructions, SS);
    else if (ft_strncmp(line, "pa", 2) == 0)
        fill_instruction(line, instructions, PA);
    else if (ft_strncmp(line, "pb", 2) == 0)
        fill_instruction(line, instructions, PB);
    else if (ft_strncmp(line, "ra", 2) == 0)
        fill_instruction(line, instructions, RA);
    else if (ft_strncmp(line, "rb", 2) == 0)
        fill_instruction(line, instructions, RB);
    else if (ft_strncmp(line, "rr", 2) == 0)
        fill_instruction(line, instructions, RR);
    else if (ft_strncmp(line, "rra", 3) == 0)
        fill_instruction(line, instructions, RRA);
    else if (ft_strncmp(line, "rrb", 3) == 0)
        fill_instruction(line, instructions, RRB);
    else if (ft_strncmp(line, "rrr", 3) == 0)
        fill_instruction(line, instructions, RRR);
    else
        ft_error(instructions, a);
}


int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
    t_instruction *instructions;
    char    *line;

    a = NULL;
    b = NULL;
    instructions = NULL;
    if (argc >= 2)
    {
        check_argument(argv, &a);
        line = get_next_line(0);
        while (line)
        {
            check_instruction(line, &instructions, &a);
            line = get_next_line(0);
            if (!line)
                break;
        }   
        use_instruction(&a, &b, &instructions);
        print_list(&a);
        if (check_order(&a))
            write(1, "OK\n", 3);
        else
            write(1, "KO\n", 3);
        free_t_stack(&a);
        free_t_stack(&b);
    }
    
}

void    print_list(t_stack **head)
{
    t_stack *current;

    current = *head;
    while (current != NULL)
    {
        printf("%d\n", current->number);
        current = current->next;
    }
}

void    print_instruction(t_instruction **head)
{
    t_instruction *current;

    current = *head;
    while (current != NULL)
    {
        printf("%s\n", current->instruction);
        current = current->next;
    }
}