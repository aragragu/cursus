/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:53:28 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/26 03:17:33 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct t_list
{
    int             number;
    int             index;
    int             position;
    struct t_list    *next;
}                   t_stack;

void     check_argument(char **argv, t_stack **list);
void    fill_stack(char *argv, t_stack **list);
int     check_args(char *argv);
t_stack	*ft_lstnew(int i);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int	    ft_lstsize(t_stack *list);
t_stack	*ft_lstlast(t_stack *lst);
int	    count_words(const char *s, char c);
char	**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);
int    convert_numbers(char *str, int *num);
void free_list(t_stack *head);
int	ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int    check_list(t_stack **list, int i);
void    sa(t_stack **list); 
void    sb(t_stack **list);
void    ss(t_stack **list_a, t_stack **list_b);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void    pa(t_stack **list_a, t_stack **list_b);
void    pb(t_stack **list_a, t_stack **list_b);
void free_list(t_stack *head);
void    ra(t_stack **list_a);
void    rb(t_stack **list_b);
void    rr(t_stack **list_a, t_stack **list_b);
void    rra(t_stack **list);
void    rrb(t_stack **list);
void    rrr(t_stack **list_a, t_stack **list_b);
void    free_split(char **str);
void    free_t_stack(t_stack **head);
void    position_list(t_stack **list);
int    check_order(t_stack **head);
void    sort_stack(t_stack **list_a, t_stack **list_b);
void    sort_two(t_stack **list);
void    sort_three(t_stack **list);
void    sort_four(t_stack **list_a, t_stack **list_b);
t_stack *find_max(t_stack **list);
t_stack *find_min(t_stack **list);
void print_stack(t_stack **stack);
void    sort_five(t_stack **list_a, t_stack **list_b);
void    fill_index( t_stack **list);
void    sort_hundred(t_stack **list_a, t_stack **list_b);
void    push_to_b(t_stack **list_a, t_stack **list_b);
void    bring_back(t_stack **list_a, t_stack **list_b);
void	checker(char **num, int *number, int i, t_stack **list);

#endif