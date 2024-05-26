/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:45:50 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/26 07:43:22 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
    int				number;
    struct s_list	*next;
}					t_stack;

typedef enum e_instruction
{
    SA,
    SB,
    SS,
    PA,
    PB,
    RA,
    RB,
    RR,
    RRA,
    RRB,
    RRR
} t_type;

typedef struct s_instruction
{
    char				*instruction;
    t_type              allo;
    struct s_instruction	*next;
}					t_instruction;

char	*ft_strlcpy(char *dest, char *src, int stop);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*read_line(char *str, int fd);
char	*get_the_line(char *s);
char	*new_stash(char *str);
char	*get_next_line(int fd);
int     check_args(char *argv);
void	check_argument(char **argv, t_stack **list);
void	fill_stack(char *argv, t_stack **list);
void	checker(char **num, int *number, int i, t_stack **list);
int     convert_numbers(char *str, int *num);
int     check_list(t_stack **list, int num);
void	free_split(char **str);
void	free_t_stack(t_stack **head);
t_stack	*ft_lstnew1(int i);
t_instruction	*ft_lstnew2(char *i);
int	    ft_strncmp(char *s1, char *s2, size_t n);
void    fill_instruction(char *line, t_instruction **instructions, t_type allo);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void    ft_error(t_instruction **instructions, t_stack **a);
void    check_instruction(char *line, t_instruction **instructions, t_stack **a);
void    use_instruction(t_stack **a, t_stack **b, t_instruction **current);
void 	use_instruction2(t_stack **a, t_stack **b, t_instruction *current);
int     check_order(t_stack **head);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int	count_words(const char *s, char c);
char	**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);
void	free_list(t_stack *head);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int	ft_isdigit(int c);
void	ft_lstadd_back2(t_instruction **lst, t_instruction *new);
void	free_instruction(t_instruction **head);
void	sa(t_stack **list_a);  
void	sb(t_stack **list_b);
void	ss(t_stack **list_a, t_stack **list_b);
void	pa(t_stack **list_a, t_stack **list_b);
void	pb(t_stack **list_a, t_stack **list_b);
void	ra(t_stack **list_a);
void	rb(t_stack **list_b);
void	rr(t_stack **list_a, t_stack **list_b);
void	rra(t_stack **list_a);
void	rrb(t_stack **list_b);
void	rrr(t_stack **list_a, t_stack **list_b);
void    ft_error(t_instruction **instructions, t_stack **a);
t_instruction	*ft_lstlast2(t_instruction *lst);
void    print_list(t_stack **head);



#endif