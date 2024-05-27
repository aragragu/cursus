/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:45:50 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/27 03:06:43 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}					t_stack;

typedef struct s_instruction
{
	char					*instruction;
	struct s_instruction	*next;
}					t_instruction;

void			check_in(char *line, t_instruction **instructions, t_stack **a);
int				ft_strlen(char *s);
void			shift(char *buf, int endl);
char			*ft_strjoin(char *line, char *buf);
void			free_it(char *str);
int				ft_strchr( char *s, int readit);
char			*read_and_getline(char *buf, int fd, char *line);
char			*get_next_line(int fd);
void			sa(t_stack **list_a);
void			sb(t_stack **list_b);
void			ss(t_stack **list_a, t_stack **list_b);
void			pa(t_stack **list_a, t_stack **list_b);
void			pb(t_stack **list_a, t_stack **list_b);
void			ra(t_stack **list_a);
void			rb(t_stack **list_b);
void			rr(t_stack **list_a, t_stack **list_b);
void			rra(t_stack **list_a);
void			rrb(t_stack **list_b);
void			rrr(t_stack **list_a, t_stack **list_b);
long long		ft_atoi(const char *str);
void			free_list(t_stack *head);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
void			check_argument(char **argv, t_stack **list);
void			fill_stack(char *argv, t_stack **list);
void			checker(char **num, int *number, int i, t_stack **list);
int				convert_numbers(char *str, int *num);
int				check_list(t_stack **list, int num);
int				check_args(char *argv);
void			free_split(char **str);
void			free_t_stack(t_stack **head);
int				ft_isdigit(int c);
char			**ft_split(char const *s, char c);
int				ft_strncmp(char *s1, char *s2, size_t n);
void			fill_instruction(char *line, t_instruction **instructions);
void			ft_error(t_instruction **instructions, t_stack **a);
void			free_instruction(t_instruction **head);
void			use_instruct(t_stack **a, t_stack **b, t_instruction **current);
int				count_words(const char *s, char c);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
void			ft_lstadd_back2(t_instruction **lst, t_instruction *new);
t_stack			*ft_lstlast(t_stack *lst);
t_instruction	*ft_lstlast2(t_instruction *lst);
t_stack			*ft_lstnew1(int i);
t_instruction	*ft_lstnew2(char *i);
void			use_instruct2(t_stack **a, t_stack **b, t_instruction *current);
int				check_order(t_stack **head);
void			ft_lstadd_front(t_stack **lst, t_stack *new);

#endif