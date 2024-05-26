/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:54:28 by aragragu          #+#    #+#             */
/*   Updated: 2024/05/26 07:26:46 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"



int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}


void    fill_instruction(char *line, t_instruction **instructions, t_type allo)
{
    t_instruction *new_node;

    if (!*instructions)
	{
		*instructions = ft_lstnew2(line);
		(*instructions)->allo = allo;	
	}
    else
    {
        new_node = ft_lstnew2(line);
		new_node->allo = allo;
        ft_lstadd_back2(instructions, new_node);
    }
}


void    ft_error(t_instruction **instructions, t_stack **a)
{
	free_t_stack(a);
	free_instruction(instructions);
    write(2, "Error\n", 6);
    exit(1);
}



void	free_instruction(t_instruction **head)
{
	t_instruction	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void	use_instruction(t_stack **a, t_stack **b, t_instruction **instructions)
{
	t_instruction *current;

	current = *instructions;
	while (current)
	{
		if (current->allo == SA)
			sa(a);
		else if (current->allo == SB)
			sb(b);
		else if (current->allo == SS)
			ss(a, b);
		else if (current->allo == PA)
			pa(a, b);
		else if (current->allo == PB)
			pb(a, b);
		use_instruction2(a, b, current);
		current = current->next;
	}
}

void 	use_instruction2(t_stack **a, t_stack **b, t_instruction *current)
{
	if (current->allo == RA)
		ra(a);
	else if (current->allo == RB)
		rb(b);
	else if (current->allo == RR)
		rr(a, b);
	else if (current->allo == RRA)
		rra(a);
	else if (current->allo == RRB)
		rrb(b);
	else if (current->allo == RRR)
		rrr(a, b);
}

int	check_order(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}



static	size_t	count_letter(const char *s, int position, char c)
{
	size_t		i;
	char		*p;

	p = (char *)s;
	i = 0;
	while (*(s + position + i) && *(s + position + i) != c)
		i++;
	return (i);
}

static void	ft_free1(char **reslut, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(reslut[i]);
		i++;
	}
	free(reslut);
}

static	char	**allocation(char **s, const char *x, int i, char c)
{
	int			z;
	int			y;

	y = 0;
	while (x[i])
	{
		z = 0;
		while (x[i] && x[i] == c)
			++i;
		if (x[i])
		{
			s[y] = (char *)ft_calloc((count_letter(x, i, c) + 1), sizeof(char));
			if (!s[y])
			{
				ft_free1(s, y);
				return (NULL);
			}
			while (x[i] && x[i] != c)
				s[y][z++] = x[i++];
			y++;
		}
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	char		**result;
	size_t		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	result = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!result)
		return (NULL);
	result[count] = NULL;
	i = 0;
	result = allocation(result, s, i, c);
	return (result);
}
long long	ft_atoi(const char *str)
{
	int					sign;
	long long			result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return ((result * sign));
}

void	free_list(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	if (count > 0 && size > 9223372036854775807ULL / count)
		return (0);
	data = malloc(count * size);
	if (!data)
		return (NULL);
	ft_bzero(data, (count * size));
	return (data);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '+' || c == '-')
		return (1);
	else
		return (0);
}